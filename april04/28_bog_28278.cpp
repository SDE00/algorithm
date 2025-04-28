#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, trash; 
    int x[1000000];
    int top = 0;
    
    cin >> n;

    while (n >0)
    {
        int command;
        cin >> command;

        if (command == 1)
        {
            if (top >= 1000000) {
                cin >> trash;
            }
            else {
                cin >> x[top];
                top++;
            }
        }
        else if (command == 2)
        {
            if (top <= 0)
            {
                cout << -1 << "\n";
            } else
            {
                cout << x[top - 1] << "\n";
                top--;
            }
        }
        else if (command == 3) // 전체 개수
        {
            cout << top << "\n";
        }
        else if (command == 4) // 스택이 비어있는지?
        {
            if(top <= 0)
                cout << 1 << "\n";
            else
                cout << 0 << "\n";
        
        }
        else if (command == 5)
        {
            if( top <= 0)
                cout << -1 << "\n";
            else
                cout << x[top - 1] << "\n";
        }

        n--;
    }
    


    return 0;
}