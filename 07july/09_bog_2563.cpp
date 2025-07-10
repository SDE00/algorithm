#include <iostream>
#include <cmath>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    bool box[100][100];
    int n;
    int start, end;

    for(int i=0; i<100; i++)
    {
        for(int j=0; j<100; j++)
        {
            box[i][j] = false;
        }
    }

    //입력
    cin >> n;

    for(int i=0; i<n; i++)
    {
        cin >> start >> end;

        //받은 넓이 바꾸기
        for(int i=0; i<10; i++)
        {
            for(int j=0; j<10; j++)
            {
                box[start+i][end+j] = true;
            }
        
        }
    }
    
    int sum = 0;

    for(int i=0; i<100; i++)
    {
        for(int j=0; j<100; j++)
        {
            if(box[i][j] == true)
                sum++;
        }
    }

    cout << sum;
    
}