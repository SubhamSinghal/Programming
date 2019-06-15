#include <iostream>
#include <climits>
using namespace std;

int h[501], k[501];
const int maxVal  = 99999;
int main()
{
	int t, n;
	cin >> t;
	while(t--)
	{
		cin >> n;
		int dp[1001][n + 1];
		for(int i = 0; i < n; i++)
		{
			cin >> h[i];
			h[i] = 2 * h[i];
		}

		for(int i = 0; i < n; i++)
		{
			cin >> k[i];
		}

		for(int i = 0; i <= 1000; i++)
		{
			for(int j = 0; j <= n; j++)
			{
				if(i == 0)
				{
					dp[i][j] = 0;
					continue;
				}
				else if(j == 0)
				{
					dp[i][j] = maxVal;
				}
				else
				{
					if(k[j - 1] > i)
					{
						dp[i][j] = dp[i][j - 1];
					}
					else		
						dp[i][j] = min(dp[i][j - 1], dp[i - k[j - 1]][j] + 1);
				}

			}
		}

		long minVal = 0;
		for(int i = 0; i < n; i++)
		{
			minVal += dp[h[i]][n];
		}
		cout << minVal << endl;
	}

	return 0;
}