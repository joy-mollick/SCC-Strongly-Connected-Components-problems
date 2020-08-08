
/// Topological Sort + dfs 
/// Time - 0.210s

/*
 It is an interesting problem regarding topological sort I have ever faced.
 Here You can't manually switch any switch amongst n switches.
 Otherwise ,you can run a normal dfs over graph and finding the number of connected components. This would be our answer.
 But,here you have to switch those lights which themselves being on can toggle other lights .
 So, first find the dfs(topological) sort of graph.
 So, now by these nodes from topo sort ,we can find the number of connected components by another dfs.
*/


#include<bits/stdc++.h>

using namespace std;

const int mx=10001;

bool visited[mx]={false};
bool nwvisited[mx]={false};

stack<int>st;
vector<int>adj[mx];
vector<int>rev[mx];

void dfs1(int u)
{
    visited[u]=true;
    vector<int>::iterator it;
    for(it=adj[u].begin();it!=adj[u].end();it++)
    {
        int v=(*it);
        if(!visited[v])
        {
            dfs1(v);
        }
    }
    st.push(u);
    ///it stores the nodes in the stack according to dfs time
}

void dfs2(int u)
{
    nwvisited[u]=true;
    vector<int>::iterator it;
    for(it=adj[u].begin();it!=adj[u].end();it++)
    {
        int v=(*it);
        if(!nwvisited[v])
        {
            dfs2(v);
        }
    }
}

int main()
{
    /// directed graph
    int V,E,u,v,tc;

    cin>>tc;

    for(int c=1;c<=tc;c++)
    {
    for(int j=0;j<mx;j++)
    {
        adj[j].clear();
        visited[j]=false;
        nwvisited[j]=false;
    }
    /// if remaining ,then make empty
    while(!st.empty()) st.top();

    cin>>V>>E;

    while(E--)
    {
        cin>>u>>v;
        /// given graph
        adj[u].push_back(v);
    }
    for(int i=1;i<=V;i++)
    {
        if(!visited[i]) dfs1(i);
    }
    int ans=0;
    while(!st.empty())
    {
        int node=st.top();
        st.pop();
        if(!nwvisited[node])
        {
             ans++;
            dfs2(node);
        }
    }
     cout<<"Case "<<c<<": "<<ans<<endl;
    }

    return 0;
}
