#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

struct Person{
    int age;
    string name;
};

int main() 
{
    int n;
    //입력
    cin >> n;
    Person p[n];
    for(int i=0;i<n;i++){
        cin >> p[i].age >> p[i].name;
    }

    //정렬 - Stable Sort 이용
    stable_sort(p, p+n, [](const Person& a, const Person& b){
        return a.age < b.age;
    });

    //출력
    for(int i=0;i<n;i++){
        cout << p[i].age << " " << p[i].name << "\n";
    }
    return 0;
}