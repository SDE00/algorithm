#include<iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int count=0, sum=0;
        string a;
        cin >> a;

        for(int j=0; j<a.length(); j++){
            if(a[j] == 'O') {
                count ++;
                sum += count;
            }else
                count = 0;
        }
        cout << sum << "\n";
    }

	return 0;
}