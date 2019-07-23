#include <iostream>
#include <vector>
#include <set>
using namespace std;

const int N = 10001;
vector<int> graph[N];
set<int> res;
int parent[N], dis[N], low[N];
bool visited[N]; 
int n, m, u, v, value;

void dfs(int source)
{
		int dest, children;
		children = 0;
		visited[source] = true;
		dis[source] = low[source] = ++value;

		for(int i = 0; i < graph[source].size(); i++)
		{
				dest = graph[source][i];
				if(!visited[dest])
				{
						children++;
						parent[dest] = source;
						dfs(dest);

						low[source] = min(low[source], low[dest]);

						if(parent[source] == -1 && children > 1)
						{
								res.insert(source);
						}
						if(parent[source] != -1 && low[dest] >= dis[source])
						{       
								res.insert(source);
						}
				}
				else if(dest != parent[source])
				{
						low[source] = min(low[source], dis[dest]);
				}
		}
}

int main()
{
		while(true)
		{
				cin >> n >> m;
				if(n == 0 && m == 0)
						break;

				value = 0;
				res.clear();
				for(int i = 0; i < N; i++)
				{
						visited[i] = false;
						parent[i] = i;
						graph[i].clear();
				}

				while(m--)
				{
						cin >> u >> v;
						graph[u].push_back(v);
						graph[v].push_back(u);
				}

				parent[1] = -1;

				dfs(1);

				cout << res.size() << endl;
		}
		
}