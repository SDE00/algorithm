#include <iostream>
#include <stack>
#include <vector>

using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n, p;

    //크기 입력
    cin >> n >> p;

    //스택 선언
    vector<stack<int>> guitar(7);
    long long move_count=0;

    for(int i=0; i<n; i++){
        int line, fret;

        cin >> line >> fret;

        //스택이 비어있거나, 현재 누르고 있는 플랫이 더 클때 -> 빼준다
        while(!guitar[line].empty() && guitar[line].top() > fret){
            guitar[line].pop();
            move_count++;
        }

        //아무것도 안눌린 상태
        if(guitar[line].empty() || guitar[line].top() < fret){
            guitar[line].push(fret);
            move_count++;
        }
    }

    cout << move_count;

    return 0;
}