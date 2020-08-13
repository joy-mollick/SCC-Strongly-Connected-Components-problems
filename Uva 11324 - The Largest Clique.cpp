

/// Time-0.070s
/// Rank-215th
/// Category- Hard.
/// Nice problem.

/*
 You have to find out the the longest sub-graph of the graph so that any two nodes u, v are set in this sub-graph. 
 Satisfaction: Either u can reach v, or v can reach u, or reach each other. (So, scc is not mandatory ,in scc every pair( u and v && v and u ) needs path between them)
 But, here it can be like connected component, like from a node(u) others nodes on its paths can be reachable. ( u and v || v and u ) needs path.
 So , make all scc to a point having size ( number of nodes of scc) then, it will be a DAG . Now again construct the graph and make maximum DAG path with point(sz).
*/

#include<bits/stdc++.h>

using namespace std;

const int mx=1001;

bool visited[mx]={false};

vector<int>adj[mx];
vector<int>DAG[mx];
vector<int>rev[mx];
stack<int>topo_sort;
int scc_count;
int sz_scc[mx];
int scc[mx];
int ans[mx];/// ans[i],it hold the maximum node in DAG from the point i

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
    topo_sort.push(u);
}

void dfs1(int u)
{
    sz_scc[scc_count]++;
    scc[u]=scc_count;
    visited[u]=true;
    vector<int>::iterator it;
    for(it=rev[u].begin();it!=rev[u].end();it++)
    {
        int v=(*it);
        if(!visited[v])
        {
            dfs1(v);
        }
    }
}

int nw_dfs(int u)
{
    if (DAG[u].size() == 0) return (ans[u] = sz_scc[u]);
    if (-1 != ans[u]) return ans[u];

    int resu = 0;
    for (int i = 0; i < DAG[u].size(); ++i)
    {
        int v = DAG[u][i];
        /// max (sz_scc[u]+its adjacency answer).
        resu = max(resu, sz_scc[u] + nw_dfs(v));
    }

    return ans[u] = resu;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n,m,u,v,cost,tc;

    cin>>tc;

    while(tc--)
    {

    cin>>n>>m;

    for(int l=0;l<mx;l++)
    {
        adj[l].clear();
        rev[l].clear();
        visited[l]=false;
        DAG[l].clear();
        ans[l]=-1;
        scc[l]=0;
        sz_scc[l]=0;
    }
    scc_count=0;
    while(m--)
    {
        cin>>u>>v;
        adj[u].push_back(v);
        rev[v].push_back(u);
    }

    /// finding topological order
    for(int k=1;k<=n;k++)
    {
        if(!visited[k]) dfs(k);
    }

    memset(visited,false,sizeof(visited));

    while(!topo_sort.empty())
    {
        int u=topo_sort.top();
        topo_sort.pop();
        if(!visited[u])
        {
            dfs1(u);
            scc_count++;
        }
    }

    for(int p=1;p<=n;p++)
    {
        for(int j=0;j<adj[p].size();j++)
        {
            int v=adj[p][j];
            if(scc[p]!=scc[v])
            {
                DAG[scc[p]].push_back(scc[v]);
            }
        }
    }

    memset(ans,-1,sizeof(ans));
    int res=0;
    for(int m=0;m<scc_count;m++)
    {
            if(ans[m]==-1)
            {
            /// longest path starting from the scc number m.
            res=max(res,nw_dfs(m));
            }
          ///  cout<<ans[m]<<" "<<m<<endl;
    }

    cout<<(res)<<endl;
}

    return 0;
}
