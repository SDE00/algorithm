//선형 풀이 -> 시간 초과
#include <iostream>
#include <vector>

using namespace std;
int main()
{
    int n, m, card;

    // 입력
    cin >> n;
    vector<int> my_card(n);
    for (int i = 0; i < n; i++)
    {
        cin >> my_card[i];
    }

    cin >> m;
    vector<int> hash(m, 0);
    for (int i = 0; i < m; i++)
    {
        cin >> card;
        for (int j = 0; j < n; j++)
        {
            if (my_card[j] == card)
            {
                hash[i] = 1;
                break;
            } 
        }
    }

    // 출력
    for (int i = 0; i < m; i++)
    {
        cout << hash[i];
    }
}