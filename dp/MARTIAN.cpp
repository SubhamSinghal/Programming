#include <iostream>
using namespace std;

int main()
{
	int n, m;
	long maxSum, sum, total;

	while(true)
	{
		cin >> n >> m;
		if(n == 0 && m == 0)
			break;

		maxSum = 0;
		int y[n][m], b[n][m];
		for(int i = 0; i < n; i++)
		{
			for(int j = 0; j < m; j++)
			{
				cin >> y[i][j];
				if(j > 0)
				{
					y[i][j] += y[i][j - 1];
				}

			}
		}

		for(int i = 0; i < n; i++)
		{
			for(int j = 0; j < m; j++)
			{
				cin >> b[i][j];
				maxSum += b[i][j];
				if(j > 0)
				{
					b[i][j] += b[i][j - 1];
				}
			}
		}

		sum = total = maxSum;

		for(int j = 0; j < m; j++)
		{
			sum = total;
			for(int i = n - 1; i >= 0; i--)
			{
				sum += (y[i][j] - b[i][j]);
				maxSum = max(maxSum, sum);
			}
		}

		cout << maxSum << endl;


	}
}