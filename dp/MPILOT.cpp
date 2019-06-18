#include <iostream>
#include <cmath>
using namespace std;

long INF = 9999999;

int main()
{
	int n, x, y;
	int assistant[10000], captain[10000];
	long dp[2][5001];

	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		cin >> captain[i] >> assistant[i];
	}

	for (int i = 0; i < 2; ++i)
	{
		for (int j = 0; j <= n / 2; ++j)
		{
			dp[i][j] = INF;
		}
	}

	dp[1][1] = assistant[0];

	for (int i = 2; i <= n; ++i)
	{
		int m = min(i, n / 2);
		int index = i % 2;

		// if we have to make 0 extra assistant then last one has to be captain 
		//because last one is eldest and cannot be assistant 
		dp[index][0] = dp[1 - index][1] + captain[i - 1];
		// if we have to make m more assistants then  last one has to be assistant 
		//because i = 5 and m = 5 then we cannot do dp[4][5].
		dp[index][m] = dp[1 - index][m - 1] + assistant[i - 1];

		for(int j = 1; j < m; j++)
		{
			dp[index][j] = min(dp[1 - index][j - 1] + assistant[i - 1], dp[1 - index][j + 1] + captain[i - 1]);
		}	
	}

	cout << dp[0][0] << endl;


	return 0;
}