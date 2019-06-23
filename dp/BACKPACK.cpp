//Problem Link: https://www.spoj.com/problems/BACKPACK/
// Ref Link: https://stackoverflow.com/questions/24338459/spoj-backpack-dp-explaination

#include <iostream>
#include <vector>
using namespace std;
 
struct node
{
	int vol,profit, p;
};
 
int main()
{
	int t, n, vmax;
	long dp[32001][61];
	node parent[62];
	vector<node> child[62];
 
	cin >> t;
	while(t--)
	{
		cin >> vmax >> n;
		
		for(int i = 0; i < 62; i++)
		{
			parent[i].vol = -1;
			child[i].clear();
		}
 
		for(int i = 1; i <= n; i++)
		{
			node temp;
			cin >> temp.vol >> temp.profit >> temp.p;
			if(temp.p == 0)
			{
				parent[i] = temp;
			}
			else
			{
				child[temp.p].push_back(temp);
			}
		}
	
 
		for(int i = 0; i <= vmax; i++)
		{
			for(int j = 0; j <= n; j++)
			{
				if(i == 0 || j == 0)
				{
					dp[i][j] = 0;
					continue;
				}
				if(parent[j].vol != -1)
				{
					int vol = parent[j].vol;
					int tempVol, tempProfit;
					int p = parent[j].profit;
 
					dp[i][j] = dp[i][j - 1];
 
 					//consider only main good and check if it gives max value
					if(vol <= i)
					{
						dp[i][j] = max(dp[i][j], dp[i - vol][j - 1] + vol * p); 
					}
 
 					//consider single attachment and check if it gives max value 
					for(int k = 0; k < child[j].size(); k++)
					{
						tempVol = vol + child[j][k].vol;
						tempProfit = vol * p + child[j][k].vol * child[j][k].profit;
						if(tempVol <= i)
						{
							dp[i][j] = max(dp[i][j], dp[i - tempVol][j - 1] + tempProfit);
						}
					}
 
 					// if main good has 2 attachment consider both and check if it gives max value
					if(child[j].size() == 2)
					{
						tempVol = vol + child[j][0].vol + child[j][1].vol;
						tempProfit = vol * p + child[j][0].vol * child[j][0].profit + child[j][1].vol * child[j][1].profit;
						if(tempVol <= i)
						{
							dp[i][j] = max(dp[i][j], dp[i - tempVol][j - 1] + tempProfit);
						}
					}
				}
				else
				{
					dp[i][j] = dp[i][j - 1];
				}
			}
		}
 
		cout << dp[vmax][n] << endl;
	}
}