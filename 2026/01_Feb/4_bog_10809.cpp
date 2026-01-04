#include <iostream>
#include <string>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    string s;
    cin >> s;

    //알파벳 위치 저장
    int pos[26];

    for(int i=0; i<26; i++){
        pos[i] = -1;
    }
    
    for(int i=0; i<s.size(); i++){
        int index = s[i] - 'a';
        if(pos[index] == -1)
            pos[index] = i;
    }

    for(int i=0; i<26; i++){
        cout << pos[i] << " ";
    }


    return 0;
}