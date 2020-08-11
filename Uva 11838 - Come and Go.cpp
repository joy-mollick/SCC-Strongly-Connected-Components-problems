
#include<bits/stdc++.h>

using namespace std;

const int mx=10001;

bool visited[mx]={false};
bool nwvisited[mx]={false};
vector<int>adj[mx];
vector<int>rev[mx];

stack<int>st;

void dfs(int u)
{
    visited[u]=true;
    vector<int>::iterator it;
    for(it=adj[u].begin();it!=adj[u].end();it++)
    {
        int v=(*it);
        if(!visited[v])
        {
            dfs(v);
        }
    }
    st.push(u);
}

void dfs2(int u)
{
    nwvisited[u]=true;
    vector<int>::iterator it;
    for(it=rev[u].begin();it!=rev[u].end();it++)
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
    int V,E,u,v,t;
    while(cin>>V>>E && (V!=0&&E!=0))
    {
        for(int k=0;k<mx;k++)
        {
            adj[k].clear();
            rev[k].clear();
            visited[k]=false;
            nwvisited[k]=false;
        }

    while(E--)
    {
        cin>>u>>v>>t;
        /// one way road
        if(t==1)
        {
            adj[u].push_back(v);
            rev[v].push_back(u);
        }
        /// two way road.
        else if(t==2)
        {
            adj[u].push_back(v);
            adj[v].push_back(u);
            rev[v].push_back(u);
            rev[u].push_back(v);
        }
    }

    for(int i=1;i<=V;i++)
    {
        if(!visited[i]) dfs(i);
    }

    int num=0;

    while(!st.empty())
    {
        int node=st.top();
        st.pop();
        if(!nwvisited[node])
        {
            num++;
            dfs2(node);
        }
    }

    if(num==1) cout<<"1"<<endl;
    else cout<<"0"<<endl;
    }

    return 0;
}
