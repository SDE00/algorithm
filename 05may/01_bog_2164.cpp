#include <iostream>
#include <queue>
using namespace std;

int main() {
    int n;
    cin >> n;
    queue<int> q;

    ios::sync_with_stdio(false);
    cin.tie(0);
    // 1부터 n까지 큐에 삽입
    for (int i = 1; i <= n; ++i) {
        q.push(i);
    }

    // 카드가 하나 남을 때까지 반복
    while (q.size() > 1) {
        q.pop();               // 1. 맨 위 카드 버림
        int top = q.front();   // 2. 그 다음 카드 맨 뒤로
        q.pop();
        q.push(top);
    }

    // 마지막 남은 카드 출력
    cout << q.front() << endl;
    return 0;
}
