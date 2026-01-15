#include<iostream>
#include<algorithm>
#include<string>

using namespace std;

bool compare(const string& a, const string& b){
    if(a.length() != b.length())
        return a.length() < b.length();
    return a < b;
}
int main()
{
    int n;
    cin >> n;
    string word[n];

    //입력
    for(int i=0; i<n; i++){
        cin >> word[i];
    }

    //정렬 (길이 짧은 순 / 사전 순)
    sort(word, word+n, compare);

    //출력
    for(int i=0; i<n; i++){
        if(word[i] == word[i-1])
            continue;
        cout << word[i] << "\n";
    }

    return 0;
}