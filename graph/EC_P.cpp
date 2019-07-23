#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v[701];
vector<pair<int, int>> res;
int in[701], low[701], parent[701];
bool visited[701];
int n, m, a, b, test;
int value = 0;
bool isBridge;

void dfs(int s)
{
	visited[s] = true;
	int d;
	low[s] = in[s] = ++value;

	for(int i = 0; i < v[s].size(); i++)
	{
		d = v[s][i];
		if(!visited[d])
		{
			parent[d] = s;
			dfs(d);

			low[s] = min(low[s], low[d]);

			if(low[d] > in[s]) 
			{
				isBridge = true;
				if(s < d) {
					res.push_back(make_pair(s, d));
				}
				else
					res.push_back(make_pair(d, s));
			}
		}
		else if(d != parent[s])
		{
			low[s] = min(low[s], in[d]);
		}
		
	}
}

int main()
{
	cin >> test;
	for(int i = 1; i <= test; i++)
	{
		isBridge = false;
		value = 0;
		for(int j = 0; j <= 700; j++)
		{
			visited[j] = false;
			parent[j] = j;
			v[j].clear();
		}
		res.clear();

		cin >> n >> m;
		while(m--)
		{
			cin >> a >> b;
			v[a].push_back(b);
			v[b].push_back(a);
		}
	
		dfs(1);
		cout << "Caso #" << i << endl;
		
		if(!isBridge)
		{
			cout << "Sin bloqueos\n";
		}
		else
		{
			int size = res.size();
			sort(res.begin(), res.end());
			cout << size << endl;
			for(int j = 0; j < size; j++)
			{
				cout << res[j].first << " " << res[j].second << endl;
			}
		}
	}
}