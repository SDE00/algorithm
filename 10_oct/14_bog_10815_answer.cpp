#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m, card;

    // 입력
    cin >> n;
    vector<int> my_card(n);
    for (int i = 0; i < n; i++)
    {
        cin >> my_card[i];
    }

    sort(my_card.begin(), my_card.end());

    cin >> m;
    vector<int> hash(m, 0);
    for (int i = 0; i < m; i++)
    {
        cin >> card;
        if (binary_search(my_card.begin(), my_card.end(), card))
            hash[i]=1;
        else
            hash[i]=0;
        
    }

    // 출력
    for (int i = 0; i < m; i++)
    {
        cout << hash[i] << " ";
    }
}