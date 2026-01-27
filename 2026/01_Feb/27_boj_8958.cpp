#include<iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int count;
        int sum=0;

        char a;
        cin >> a;

        if(a == 'O') {
            count ++;
            sum += count;
        }else
            count = 0;

        cout << sum << "\n";

    }

	return 0;
}