/// Cycle detecting ,an interesting matter of use about dfs
/// Coloring algorithm

/*
  We will mark current processing's nodes as gray. 
  Then , we will check cycle .And after processing we will
  mark these nodes as black.
*/


#include<bits/stdc++.h>

using namespace std;

const int mx=1001;

int V;

#define WHITE 0
#define GRAY 1
#define BLACK 2

vector<int>adj[mx];
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
    for(int i=0;i<V;i++)
    {
        if(color[i]==WHITE) cyclic_dfs(i);
        if(cycle) return true;
    }
    return false;
}
