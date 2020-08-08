
/// Topological Sort(kahn's algo) + backtracking
/// Printing All topological Sort


#include<bits/stdc++.h>

using namespace std;

const int mx=1001;

int in_degree[mx];
bool visited[mx];

vector<int>adj[mx];
vector<int>::iterator it;

int V;

void all_topo_sort(vector<int>& ans,bool *visited)
{
    int v;
    bool flag =false;

    for(int i=1;i<=V;i++)
    {
        if(in_degree[i]==0 && !visited[i])
        {
            for(it=adj[i].begin();it!=adj[i].end();it++)
            {
                v=(*it);
                in_degree[v]--;
            }

            ans.push_back(i);
            visited[i]=true;
            all_topo_sort(ans,visited);

            visited[i]=false;
            ans.erase(ans.end()-1);
            for(it=adj[i].begin();it!=adj[i].end();it++)
            {
                v=(*it);
                in_degree[v]++;
            }

            flag=true;
        }
    }
    /// one topological order print lexicographically
    if (!flag)
    {
        for (int i = 0; i < ans.size(); i++)
            cout << ans[i]<<" ";

        cout << endl;
    }
}

int main()
{
     /// directed graph
     int E,u,v;

   cin>>V>>E;
   for(int i=1;i<=V;i++) visited[i]=false;
   while(E--)
   {
       cin>>u>>v;
       adj[u].push_back(v);
       in_degree[v]++;
   }

   vector<int>ans;
   all_topo_sort(ans,visited);

    return 0;
}
