#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, min=0;
    cin >> n;

    for(int i=1; i<=n; i++){

        int sum=0;

        int temp = i;
        while(temp > 0) {
            sum+=(temp%10);
            temp /= 10;
        }

        //생성자인지 조건 확인
        if(i+sum == n){
            cout << i;
            return 0;
        }
    }      

    cout << 0;
    return 0;
}