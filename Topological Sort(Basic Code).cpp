
///Topological Sort ,Interesting sort .
///Making a serialization of all nodes,where a node u will come before v if v is reachable from u
///It can be said that it is a dfs serialization .
///It is not unique permutation.
///The graph with cycles don't have topological sort.

#include<bits/stdc++.h>

using namespace std;

const int mx=10010;

vector<int>adj[mx];
stack<int>st;
bool visited[mx];

int V;

#define WHITE 0
#define GRAY 1
#define BLACK 2

int color[mx];
bool cycle=false;

void cyclic_dfs(int u)
{
    ///this means that,this node is now already in processs
    color[u]=GRAY;
    vector<int>::iterator it;
    for(it=adj[u].begin();it!=adj[u].end();it++)
    {
        int v=(*it);
        ///this node is not still visited.
        if(color[v]==WHITE)
        {
            cyclic_dfs(v);
        }
/// this node is in already our dfs progress , and we met it again i.e. there is a cycle
        else if(color[v]==GRAY){
            cycle = true;
            return;
        }
    }
    /// BLACK means already visited
    color[u]=BLACK;
}

/// It will return true or false about appearance of cycle in graph .
bool dfs()
{
    cycle=false;
    for(int i=1;i<=V;i++)
    {
        if(color[i]==WHITE) cyclic_dfs(i);
        if(cycle) return true;
    }
    return false;
}

void topo_sort(int u)
{
    visited[u]=true;
    vector<int>::iterator it;
    for(it=adj[u].begin();it!=adj[u].end();it++)
    {
        int v=(*it);
        if(!visited[v])
        {
            topo_sort(v);
        }
    }
    st.push(u);
}

int main()
{
    int e,u,v;

    cin>>V>>e;

    while(e--)
    {
        cin>>u>>v;
        adj[u].push_back(v);
    }

    /// initialize white colors
    memset(color,0,sizeof(color));

    /// cycle remains here
    if(dfs())
    {
        cout<<"-1"<<endl;
        return 0;
    }

    memset(visited,false,sizeof(visited));

    for(int i=1;i<=V;i++)
    {
        if(!visited[i])
        {
            topo_sort(i);
        }
    }

    while(!st.empty())
    {
        cout<<st.top()<<" ";
        st.pop();
    }

    return 0;
}
