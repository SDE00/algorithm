#include <iostream>
#include <string>
using namespace std;

//현재 Stack의 top 확인
char pairOf(char ch) {
    return ch == ')' ? '(' : '[';
} 

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    string sentence;
    while (true)
    {
        //문장 전체 읽어오기
        getline(cin, sentence);
        if (sentence == ".") break;

        char stack[1000];
        int top = 0;
        bool valid = true;// 괄호 유효성 검사

        for (int i = 0; i < sentence.length(); i++)
        {
            char ch = sentence[i];

            if (ch == '(' || ch == '[')
                stack[top++] = ch;
            else if (ch == ')' || ch == ']')
            {
                if (top == 0 || stack[top - 1] != pairOf(ch)) {
                    valid = false;
                    break;
                }
                top--;
            }
        }

        if (top != 0) valid = false;

        cout << (valid ? "yes" : "no") << '\n';
    }

    return 0;
}

// 1차 시도: 스택 없이 구현 -> "([ (([( [ ] ) ( ) (( ))] )) ])." 판별 불가(짝수 여부만 판별이 가능해서 구조적인 문제를 찾을 수 없음)
// 2차 시도: 스택을 활용해서 구현 -> "([ (([( [ ] ) ( ) (( ))] )) ])." 판별 가능