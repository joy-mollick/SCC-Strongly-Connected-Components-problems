

/// Time-0.170s

/*
 Pick a node , run dfs over that node and choose the nodes which has been visited.
 After run dfs of all , find the number of nodes which has not been visited yet.
 Those nodes should be covered to make strongly connected component.

*/

#include<bits/stdc++.h>

using namespace std;

const int mx=10001;

bool visited[mx]={false};
bool global[mx]={false};
bool already[mx]={false};

vector<int>adj[mx];

void dfs(int u)
{
    visited[u]=global[u]=true;
    vector<int>::iterator it;
    for(it=adj[u].begin();it!=adj[u].end();it++)
    {
        int v=(*it);
        if(!visited[v])
        {
            dfs(v);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int tc,t=0;

    cin>>tc;
    while(tc--)
    {

    for(int j=0;j<mx;j++)
    {
        adj[j].clear();
        visited[j]=false;
        global[j]=false;
        already[j]=false;
    }

    int m,n,u,v;
    cin>>m>>n;

    while(n--)
    {
        cin>>u>>v;
        adj[u].push_back(v);
    }

    int not_prove=m;
    for(int i=1;i<=m;i++)
    {
        if(!global[i])
        {
            memset(visited,false,sizeof(visited));
            dfs(i);
            for(int j=1;j<=m;j++)
            {
                if(i!=j && !already[j] &&visited[j])
                {
                    not_prove--;
                    already[j]=true;
                }
            }
        }
    }
     printf("Case %d: %d\n", t+1, not_prove);
     t++;
    }
    return 0;
}
