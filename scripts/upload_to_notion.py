import os
import sys
import requests
from notion_client import Client
from datetime import datetime

def get_tier(level):
    """Solved.ac 레벨 숫자를 한글 티어 이름으로 변환 (예: 실버 III)"""
    tiers = ['Unrated', '브론즈', '실버', '골드', '플래티넘', '다이아몬드', '루비']
    if level == 0: return tiers[0]
    tier_name = tiers[(level - 1) // 5 + 1]
    tier_num_list = ['V', 'IV', 'III', 'II', 'I']
    tier_num = tier_num_list[(level - 1) % 5]
    return f"{tier_name} {tier_num}"

def get_language(ext):
    """파일 확장자에 따라 사용 언어 텍스트 반환"""
    lang_map = {
        '.cpp': 'C++17',
        '.py': 'Python',
        '.js': 'JavaScript',
        '.java': 'Java',
        '.c': 'C'
    }
    return lang_map.get(ext.lower(), 'C++17') # 등록되지 않은 확장자는 기본값 C++17

def main():
    if len(sys.argv) < 2: return
    file_path = sys.argv[1]
    file_name = os.path.basename(file_path)
    base_name, ext = os.path.splitext(file_name)

    # 1. 사이트 및 문제 번호 판별
    site_name = "Baekjoon" # 기본값
    if 'boj_' in file_name:
        site_name = "Baekjoon"
    elif 'pg_' in file_name: # 프로그래머스 대비용 (예: 8_pg_12345.py)
        site_name = "Programmers"
    else:
        return # 둘 다 아니면 무시

    try:
        problem_id = base_name.split('_')[-1]
    except:
        return

    # 2. 정보 가져오기 (백준일 때만 Solved.ac 호출)
    title = f"Problem {problem_id}" # 기본 제목
    level_text = "Unrated"
    tags = []
    link = f"https://www.acmicpc.net/problem/{problem_id}"

    if site_name == "Baekjoon":
        res = requests.get(f"https://solved.ac/api/v3/problem/show?problemId={problem_id}")
        if res.status_code == 200:
            p_data = res.json()
            title = p_data.get('titleKo', title)
            level_text = get_tier(p_data.get('level', 0))
            tags = [{"name": tag['key'].upper()} for tag in p_data.get('tags', [])[:3]]
    #TODO: 프로그래머스 사용 시에 대해 예외 처리하기
    elif site_name == "Programmers":
        link = f"https://school.programmers.co.kr/learn/courses/30/lessons/{problem_id}"
        # 프로그래머스는 별도 API가 없으므로 제목은 직접 수정하시거나 파일명을 활용해야 합니다.

    # 3. 노션 연결
    notion = Client(auth=os.environ["NOTION_TOKEN"])
    database_id = os.environ["NOTION_DATABASE_ID"]

    # 4. 페이지 생성
    notion.pages.create(
        parent={"database_id": database_id},
        icon={
            "type": "external",
            "external": {
                "url": "https://www.notion.so/icons/code_green.svg"
            }
        },
        properties={
            "이름": {"title": [{"text": {"content": title}}]},
            "문제번호": {"number": int(problem_id) if problem_id.isdigit() else 0},
            "등급": {"select": {"name": level_text}},
            "링크": {"url": link},
            "사용 개념": {"multi_select": tags},
            "사용 언어": {"select": {"name": get_language(ext)}}, # 확장자 자동 인식
            "사이트명": {"select": {"name": site_name}},
            "날짜": {"date": {"start": datetime.now().strftime('%Y-%m-%d')}}
        },
        children=[
            {"object": "block", "type": "heading_2", "heading_2": {"rich_text": [{"text": {"content": "01. 문제 설명"}}]}},
            {"object": "block", "type": "heading_2", "heading_2": {"rich_text": [{"text": {"content": "02. 필요 개념"}}]}},
            {"object": "block", "type": "heading_2", "heading_2": {"rich_text": [{"text": {"content": "03. 핵심 코드"}}]}},
            {"object": "block", "type": "heading_2", "heading_2": {"rich_text": [{"text": {"content": "04. 코드 (풀이 방식)"}}]}},
            {"object": "block", "type": "heading_2", "heading_2": {"rich_text": [{"text": {"content": "05. 어려웠던 부분"}}]}}
        ]
    )

if __name__ == "__main__":
    main()