#include<iostream>
using namespace std;

int main ()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	int n;
	int l[101], j[101]; 
	int dp[101];
	
	//입력
	cin >> n;
	for (int i=0; i<n; i++)
		cin >> l[i];
	
	for (int i=0; i<n; i++)
		cin >> j[i];

	
	//전체 반복해서 각 최댓값을 구해서 현재 체력 기준으로 얻을 있는 최대값을 저장하기
	for(int i=0; i<n; i++)
	{
		for(int hp=100; hp >= l[i]; hp--)
		{
			int c = dp[hp - l[i]] + j[i];
			
			if(c > dp[hp])
				dp[hp] = c;
		}
	}
	
	int res = 0;
	for (int i=0; i<n; i++)
		if(res < dp[i])
			res = dp[i]; 
	
	cout << res;
	
	return 0;
}