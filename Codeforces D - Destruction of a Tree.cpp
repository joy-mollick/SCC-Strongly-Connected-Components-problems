
/// Codeforces D - Destruction of a Tree
/// DFS + thinking + greedy + topological sort 

/// It is better to be possible we have to remove edges which are even and closest to the leaves
/// This is greedy approach

/// We will make topological sort by a dfs and store the father of a node
/// then run another dfs by which from topo order from the last
/// we will check the nodes with even degrees and repeatedly check and go to the leaves and store them

#include <bits/stdc++.h>

using namespace std;

const int mxn=2e5+20;

int vis[mxn],degree[mxn],fat[mxn];

vector<int>adj[mxn];
vector<int>ans;
stack<int>rev_topo;

void topo_dfs(int p,int u)
{
    rev_topo.push(u);
    fat[u]=p;
    for(int i=0;i<adj[u].size();i++)
    {
        int v=adj[u][i];
        if(v==p) continue;
        topo_dfs(u,v);
    }
}

void real_dfs(int u)
{
    ans.push_back(u);
    vis[u]=1;
    for(int i=0;i<adj[u].size();i++)
    {
        int v=adj[u][i];
        --degree[v];
        /// go towards the son and not up to father
        if(v==fat[u]) continue;
        if(vis[v]) continue;
        if(degree[v]%2==0) real_dfs(v);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    memset(vis,0,sizeof(vis));
    memset(degree,0,sizeof(degree));
    int n,x;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>x;
        if(x)
        {
            adj[i].push_back(x);
            adj[x].push_back(i);
            degree[i]++;
            degree[x]++;
        }
    }
    topo_dfs(0,1);
    /// now traversing according to topo order

    while(!rev_topo.empty())
    {
        int u=rev_topo.top();
        rev_topo.pop();
        if(degree[u]%2==0) real_dfs(u);
    }

    if(ans.size()==n)
    {
        cout<<"YES\n";
        for(int i=0;i<ans.size();i++)
        {
            cout<<ans[i]<<endl;
        }
    }

    else
    {
        cout<<"NO"<<endl;
    }

    return 0;
}
