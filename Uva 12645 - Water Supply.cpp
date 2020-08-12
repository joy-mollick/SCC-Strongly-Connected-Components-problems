
/// Classical problem of Topological Sort + dfs. 
/// Time-0.020s
/// Rank-43th.

/*
It's main concept is , 0 is our water supply node .Now you have to add minimum edges so that all nodes are reachable from that (0) node.
So, we will find those nodes in which order ,they form topological sort.
From a node with incoming degree(0) , we can add that node to 0 node so that by that node connected component of the node has been covered by 0 node.
That's why we will take node from , topo sort and take a node count the edge of this and 0 node and marked all connected component's nodes .
Thus ,we can calculate minimum edges. 
*/

#include<bits/stdc++.h>

using namespace std;

const int mx=1001;

bool visited[mx]={false};

vector<int>adj[mx];
stack<int>topo_sort;

void dfs(int u,bool stck)
{
    visited[u]=true;
    vector<int>::iterator it;
    for(it=adj[u].begin();it!=adj[u].end();it++)
    {
        int v=(*it);
        if(!visited[v])
        {
            dfs(v,stck);
        }
    }
/// we will use this one dfs to work of twice dfs's work using stck (boolean) parameter.
    if(stck==true)
    topo_sort.push(u);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n,m,u,v;
    while(cin>>n>>m)
    {

    for(int l=0;l<mx;l++)
    {
        adj[l].clear();
        visited[l]=false;
    }

    while(m--)
    {
        cin>>u>>v;
        adj[u].push_back(v);
    }
    int minimum_edges=0;

    /// finding topological order
    for(int k=0;k<=n;k++)
    {
        if(!visited[k]) dfs(k,true);
    }

    memset(visited,false,sizeof(visited));

    while(!topo_sort.empty())
    {
        int u=topo_sort.top();
        topo_sort.pop();
        if(!visited[u])
        {
            dfs(u,false);
///the nodes which are not connected by u ,we have to connect those
            if(u!=0)
            minimum_edges++;
        }
    }

    cout<<minimum_edges<<endl;
}

    return 0;
}
