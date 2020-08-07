/// Cycle detecting
/// Coloring algorithm
/// Time-0.131s

#include<bits/stdc++.h>

using namespace std;

const int mx=10010;

map<string,int>mp;

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

int main()
{
    int tc,u,v,e;
    int tst=1;
    cin>>tc;
    while(tc--)
    {
        for(int j=0;j<mx;j++)
        {
            ///initially all nodes are white.
            color[j]=WHITE;
            adj[j].clear();
        }
        mp.clear();
       cin>>e;
       string le,ri;
       int str_id=0;
       while(e--)
       {
           cin>>le>>ri;
           if(!mp[le])mp[le] = ++str_id;
           if(!mp[ri])mp[ri] = ++str_id;
           adj[mp[le]].push_back(mp[ri]);
       }
       V=str_id;
       cout<<"Case "<<tst<<": ";
       if(dfs())  cout<<"No"<<endl;
        else cout<<"Yes"<<endl;

     tst++;
    }
    return 0;
}
