#include <iostream>
using namespace std;

long long int dp[40][40];

int main()
{
	int d, n, k, pos;
	cin >> d;
	char arr[40];
	while(d)
	{
		cin >> n >> k;

		for(int i = 0; i < 2 * n; i++)
		{
			arr[i] = '?';
		}

		arr[2 * n] = '\0';

		for(int i = 0; i < k; i++)
		{
			cin >> pos;
			arr[pos - 1] = '[';
		}

		n = 2 * n;

		for(int i = 0; i <= n; i++)
		{
			for(int j = 0; j <= n; j++)
			{
				if(i == 0 && j == 0)
				{
					dp[i][j] = 1;
				}
				else if((i == 0 && j != 0))
				{
					dp[i][j] = 0;
				}
				else
				{
					if(arr[i - 1] == '?')
					{
						dp[i][j] = dp[i - 1][j + 1] + dp[i - 1][j - 1];
					}
					else
					{
						dp[i][j] = dp[i - 1][j - 1];
					}
				}
			}
		}

		cout << dp[n][0] << endl;
		d--;
	}
	return 0;
}