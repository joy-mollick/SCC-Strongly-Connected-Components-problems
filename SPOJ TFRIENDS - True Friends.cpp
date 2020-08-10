/// Strongly Connected Components - SCC .
/// SCC can be found by other algorithms in linear time like tarjan algorithm (articulation finding algorithm)
/// Here I will implement Kosaraju's algorithm.
/// Time Complexity O(V+E)

/*
 Here we run two times dfs,nothing else.First time serially we push the nodes into the stack by original graph.
 First ,we take the serial in which the original graph will be traversed . Then store them into a stack.
 Then we know that if original graph will be reversed,therefore the cycle remains cycle(scc block remains okk).
 So ,now again traverse the reverse graph.
*/

/// Time-1970ms

#include<bits/stdc++.h>

using namespace std;

const int mx=101;

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
    /// this node (u) is a part of the current cycle i.e. current scc block
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
    int V,E,u,v;

    int tc;

    cin>>tc;

    char c;

    while(tc--)
    {

    for(int k=0;k<mx;k++)
    {
        visited[k]=false;
        nwvisited[k]=false;
        rev[k].clear();
        adj[k].clear();
    }
    cin>>V;

    for(int i=1;i<=V;i++)
    {
        for(int j=1;j<=V;j++)
        {
            cin>>c;
            if(c=='Y')
            {
                adj[i].push_back(j);
                rev[j].push_back(i);
            }
        }
    }

    for(int i=1;i<=V;i++)
    {
        if(!visited[i]) dfs1(i);
    }

    int cnt=0;

    while(!st.empty())
    {
        int node=st.top();
        st.pop();
        if(!nwvisited[node])
        {
///this function dfs2 will print the scc block including node
            dfs2(node);
            cnt++;
        }
    }

    cout<<cnt<<endl;

    }

    return 0;
}
