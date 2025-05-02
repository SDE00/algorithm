#include <iostream>
#include <deque>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    deque<int> dq;
    
    //하나씩 처리
    for(int i = 1; i <= n; ++i) {
        int commend, x = 0;
        cin >> commend;

        switch (commend) {
            case 1: //1과 2 앞뒤 넣기
                cin >> x;
                dq.push_front(x);
                break;
            case 2:
                cin >> x;
                dq.push_back(x);
                break;
            case 3: //3과 4 앞뒤 정수 뺴고 출력 없음 -1
                if(dq.empty()){
                    cout << -1 << "\n";
                } else {
                    cout << dq.front() << "\n";
                    dq.pop_front();
                }
                break;
            case 4:
                if(dq.empty()){
                    cout << -1 << "\n";
                } else {
                    cout << dq.back() << "\n";
                    dq.pop_back();
                }
                break;
            case 5: //5와 6 덱 정수 개수 / 덱 empty확인
                cout << dq.size() << "\n";
                break;
            case 6:
                cout << (dq.empty() ? "1" : "0") << "\n";
                break;
            case 7: //7과 8 덱 앞뒤 정수 출력, 없음 -1
                if(dq.empty()){
                    cout << -1 << "\n";
                } else {
                    cout << dq.front() << "\n";
                }
                break;
            case 8:
                if(dq.empty()){
                    cout << -1 << "\n";
                } else {
                    cout << dq.back() << "\n";
                }
                break;
        }
    }

    return 0;
}