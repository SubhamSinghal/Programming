#include <iostream>
#include <cmath>
#include <stdio.h>
using namespace std;

long int dp[201][201];

int findPermutation(string s, int i, int j)
{
	if(s[i] == '?' && (s[j] == ')' || s[j] == '}' || s[j] == ']'))
		return 1;

	if(s[j] == '?' && (s[i] == '(' || s[i] == '{' || s[i] == '['))
	{
		return 1;
	}

	if((s[i] == '(' && s[j] == ')') || (s[i] == '{' && s[j] == '}') || (s[i] == '[' && s[j] == ']'))
		return 1;

	if(s[i] == '?' && s[j] == '?')
		return 3;

	return 0;
}


int main()
{
	int n;
	string s;
	bool f;

	cin >> n >> s;

	f = false;

	for(int i = 0; i < 201; i++)
	{
		for(int j = 0; j < 201; j++)
		{
			dp[i][j] = 0;
			if(i > j){
				dp[i][j] = 1;
			}
		}
	}

	for(int l = 2; l <= n; l++)
	{
		for(int i = 0; i <= n - l; i++)
		{
			int j = i + l - 1;
			if(l == 2)
			{
				dp[i][j] = findPermutation(s, i, j);
			} 
			else if(l % 2 != 0)
			{
				dp[i][j] = 0;
			}
			else
			{
				for(int k = i + 1; k <= j; k++)
				{
					dp[i][j] += findPermutation(s, i, k) * dp[i + 1][k - 1] * dp[k + 1][j];
				}

				if(dp[i][j] > 100000)
				{
					f = true;
					dp[i][j] %= 100000;
				}
			}
		}
	}

	printf(f?"%05ld\n":"%ld\n",dp[0][n - 1]);
	return 0;
}
