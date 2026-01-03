#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    if (n == 0) {
        cout << 0 << '\n';
        return 0;
    }

    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    sort(v.begin(), v.end());

    int cut = round(n * 0.15);

    int sum = 0;
    int cnt = 0;
    for (int i = cut; i < n - cut; i++) {
        sum += v[i];
        cnt++;
    }

    int result = round((double)sum / cnt);
    cout << result << '\n';

    return 0;
}
