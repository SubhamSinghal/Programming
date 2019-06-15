#include <iostream>
using namespace std;

int main() 
{
	int t, n, k;
	int arr[1001];
	bool dp[1024];
	cin >> t;

	while(t--)
	{
		cin >> n >> k;
		for(int i = 1; i <= n; i++)
		{
			cin >> arr[i];
		}

		dp[0] = true;

		for(int i = 1; i <= n; i++)
		{
			for(int j = 1; j <= 1023; j++)
			{
				dp[j^arr[i]] |= dp[j];
			}
		}

		int maxVal = k;
		for(int i = 1; i <= 1023; i++)
		{
			if(dp[i])
			{
				maxVal = max(maxVal, k ^ i);
			}
		}

		cout << maxVal << endl;
	}
	return 0;
}