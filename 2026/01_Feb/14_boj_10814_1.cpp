#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

struct Person {
    int age;
    int number;
    string name;
};

bool compare(const Person& a, const Person& b){
    if(a.age != b.age)//나이가 같지 않으면
        return a.age < b.age;
    return a.number < b.number; //나이가 같으면 가입 순서 우선
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    Person p[n];

    //입력
    for(int i=0; i<n; i++){
        p[i].number = i;
        cin >> p[i].age >> p[i].name;
    }

    //정렬 (1 나이 / 2 가입 번호)
    //1.나이 비교 이후 가입년도 기준으로 다시 정렬)
    sort(p, p+n, compare);

    //TODO: stable sort


    //출력
    for(int i=0; i<n; i++){
        cout << p[i].age << " " << p[i].name << "\n";
    }

    return 0;
}
