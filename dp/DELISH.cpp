#include <iostream>
#include<cmath>
#define max(a,b) (a>b ? a : b)
#define min(a,b) (a<b ? a : b)
using namespace std;

long long int leftdp[1000004][2],rightdp[1000004][2], dish[1000004];

int main() 
{
	int t, n;
	cin >> t;
	while(t--)
	{
		cin >> n;
		for(int i = 0; i < n; i++)
		{
			cin >> dish[i];
		}

		leftdp[0][0] = dish[0];
		leftdp[0][1] = dish[0];

		for(int i = 1; i < n; i++)
		{
			leftdp[i][0] = max(leftdp[i - 1][0], 0) + dish[i];
			leftdp[i][1] = min(leftdp[i - 1][1], 0) + dish[i];
		}

		rightdp[n - 1][0] = dish[n - 1];
		rightdp[n - 1][1] = dish[n - 1];

		for(int i = n - 2; i >= 0; i--)
		{
			rightdp[i][0] = max(rightdp[i + 1][0], 0) + dish[i];
			rightdp[i][1] = min(rightdp[i + 1][1], 0) + dish[i];
		}

		long long int ans = 0;
		for(int i = 0; i < n-1; i++)
		{
	   		ans = max(ans,abs(leftdp[i][0] - rightdp[i+1][1]));
	   		ans = max(ans,abs(leftdp[i][1] - rightdp[i+1][0]));
		}

		cout << ans << endl;
	}
	return 0;
}