#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

void cantor(vector<char> &arr, int start, int len) {
    if (len == 1) return;

    int third = len / 3;
    for (int i = start + third; i < start + 2 * third; i++) {
        arr[i] = ' ';
    }

    cantor(arr, start, third);
    cantor(arr, start + 2 * third, third);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    int n;
    while (cin >> n) {
        int len = pow(3, n);
        vector<char> arr(len, '-');

        cantor(arr, 0, len);

        for (int i = 0; i < len; i++) {
            cout << arr[i];
        }
        cout << '\n';
    }

    return 0;
}