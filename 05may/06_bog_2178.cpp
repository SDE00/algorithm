#include <iostream>
#include <queue>
#include <string>
using namespace std;

int n, m;
int a[100][100];      // 미로 지도
int dist[100][100];   // 최소 칸 수 저장

// 상하좌우 이동 방향 (dx[i], dy[i])
int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        string row;
        cin >> row;
        for (int j = 0; j < m; j++) {
            a[i][j] = row[j] - '0';  // char → int
        }
    }

    queue<pair<int, int>> q;
    q.push({0, 0});
    dist[0][0] = 1;  // 시작 지점도 칸에 포함

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i];
            int ny = y + dy[i];

            // 범위 밖 or 벽 or 이미 방문
            if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
            if (a[nx][ny] == 0 || dist[nx][ny] > 0) continue;

            dist[nx][ny] = dist[x][y] + 1;
            q.push({nx, ny});
        }
    }

    cout << dist[n-1][m-1] << '\n';
    return 0;
}