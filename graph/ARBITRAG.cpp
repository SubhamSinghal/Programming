#include <iostream>
#include <map>
#include <vector>
using namespace std;

struct edge 
{
     int s, d;
     double c;
};

map<string, int> nodes;
double v[50];
vector<edge> e;

bool bellmanFord(int s, int n)
{
     v[s] = 1;

     int source, dest;
     double rate;

     for(int j = 0; j < n - 1; j++)
     {
          for(int i = 0; i < e.size(); i++)
          {
               source = e[i].s;
               dest = e[i].d;
               rate = e[i].c;

               if(v[dest] < v[source] * rate)
               {
                    v[dest] = v[source] * rate;
               }
          }
     }

     for(int i = 0; i < e.size(); i++)
     {
               source = e[i].s;
               dest = e[i].d;
               rate = e[i].c;

               if(v[dest] < v[source] * rate)
               {     
                    v[dest] = v[source] * rate;
                    return true;
               }
     }

     return false;
}

int main()
{
     string a, b, c;
     int i, j, n, m, source, dest;
     double rate;
     int t = 1;
     bool result;

     while(true)
     {
          nodes.clear();
          e.clear();
          result = false;

          cin >> n;

          if(n == 0)
               break;

          for(i = 0; i < n; i++)
          {
               cin >> a;
               nodes[a] = i;
          }

          for(i = 0; i < n; i++)
          {
               v[i] = 0.0;
          }

          cin >> m;
          for(i = 0; i < m; i++)
          {
               cin >> a >> rate >> b;
               source = nodes[a];
               dest = nodes[b];

               edge temp;
               temp.s = source;
               temp.d = dest;
               temp.c = rate;
               e.push_back(temp);
          }

          for(int i = 0; i < n; i++)
          {
               if(v[i] == 0)
               {
                    v[i] = 1;
                    result = bellmanFord(i, n);
                    if(result)
                    {
                         break;
                    }
               }
          }

          cout << "Case " << t << ": ";
          if(!result)
               cout << "No" << endl;
          else
               cout << "Yes" << endl;
          t++;

     }
}