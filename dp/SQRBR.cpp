#include <iostream>
using namespace std;

long long int dp[40][40];

int findPermutation(char s[], int i, int j)
{
	if(s[i] == '?' &&  s[j] == ']')
		return 1;

	if(s[j] == '?' && s[i] == '[')
	{
		return 1;
	}

	if((s[i] == '[' && s[j] == ']'))
		return 1;

	if(s[i] == '?' && s[j] == '?')
		return 1;

	return 0;
}


int main()
{
	int d, n, k, pos;
	cin >> d;
	char arr[40];
	while(d)
	{
		cin >> n >> k;
		
		for(int i = 0; i < 40; i++)
		{
			for(int j = 0; j < 40; j++)
			{
				dp[i][j] = 0;
				if(i > j){
					dp[i][j] = 1;
				}
			}
		}

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

		for(int l = 2; l <= n; l++)
		{
			for(int i = 0; i <= n - l; i++)
			{
				int j = i + l - 1;

				if(l == 2)
				{
					dp[i][j] = findPermutation(arr, i, j);
				}
				else if(l % 2 != 0)
				{
					dp[i][j] = 0;
				}
				else
				{
					for(int k = i + 1; k <= j; k++)
					{
						dp[i][j] += findPermutation(arr, i, k) * dp[i + 1][k - 1] * dp[k + 1][j];
					}
				}
			}
		}


		cout << dp[0][n - 1] << endl;
		d--;

	}
	return 0;
}