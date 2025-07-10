#include <iostream>
#include <string>
#include <queue>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    int a[100][100];
    int dist[100][100];

    //방향 백터: 상 하 좌 우
    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};

    for(int i = 0; i < n; i++) {
        string row;
        cin >> row;
        for(int j=0; j<m; j++){
            a[i][j] = row[j] - '0';
        }
    }

    queue<pair<int, int>> q; // 탐색 큐
    q.push({0, 0});
    dist[0][0] = 1;

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