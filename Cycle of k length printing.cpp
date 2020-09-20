/// k+1 length cycle

#include<bits/stdc++.h>


using namespace std;

const int mx=100001;

vector<int>adj[mx];
int node_cnt_num[mx];
int cnt_num_node[mx];
bool found;
int times=0,k,start,eds;

void dfs(int u)
{
    if(found) return;
    node_cnt_num[u]=++times;
    cnt_num_node[times]=u;
    int sz=adj[u].size();
    for(int i=0;i<sz;i++)
    {
        int v=adj[u][i];
        ///already visited this node.
        if(node_cnt_num[v])
        {
            if(node_cnt_num[u]-node_cnt_num[v]+1>=k+1)
            {
                start=v;
                eds=u;
                found=true;
                return;
            }
        }
        else
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

    int n,m,u,v;
    cin>>n>>m>>k;

    while(m--)
    {
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    found=false;

    dfs(1);

    /// total nodes in the cycle
    cout<<node_cnt_num[eds]-node_cnt_num[start]+1<<endl;

    ///printing those nodes
    for(int i=node_cnt_num[start];i<=node_cnt_num[eds];i++)
        cout<<cnt_num_node[i]<<" ";


    return 0;
}
