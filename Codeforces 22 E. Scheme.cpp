
/// Time- 560ms

/*
 Here , it is guarantee that ,every edge has out-degree.
 So,obviously our structure will like that our connected component(not strongly) will be like 
 a cycle or from a node the path goes to a cycle.
             
             3- 5
             |  |
       1- 2- 4- 6  , - state for directed edge  or a cycle     
        
         like this cycle.
             3- 5
             |  |
             4- 6
             
we will store every component's first element from where journey of a connected component starts like (1) in above diagram and end (4) i.e. from 4 we can again come back to 4.
for cycle like above,the start point will be any node of a cycle where end point will be also that (starting node),because cycle form this structure.
    Then, we add the current's end point to next's start point ,and at the last we add last component's end point to the first component's start point.
    So, overall it forms a strongly connected component.
*/


#include<bits/stdc++.h>

using namespace std;

const int mx=100001;

bool visited[mx]={false};

int scc_number[mx];

int connctd_cmp_cnt;

///each connected component's properties (first and second)
pair<int,int> cmp_pro[mx];

vector<int>adj[mx];
vector<int>rev[mx];

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
       /// already visited,so this is the last point we reach.
        else
        {
            cmp_pro[connctd_cmp_cnt].second=v;
        }
    }
}

int main()
{
    /// directed graph
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        int to;
        cin >> to;
        adj[i].push_back(to);
        rev[to].push_back(i);
    }

    /// this is for those fact where , a path from a node i goes towards a cycle
     for (int i = 1; i <= n; ++i)
    {
        /// no incoming edge comes to this node.
        /// this is the start(first) point of every component.
        if ((rev[i].size())==0)
        {
            cmp_pro[connctd_cmp_cnt].first = i;
            dfs(i);
            connctd_cmp_cnt++;
        }
    }

    /// this is for disconnected cycle (loop)
    /// here starting and end point are the same.
     for (int i = 1; i <= n; ++i) {
        if (!visited[i])
        {
            cmp_pro[connctd_cmp_cnt].first = i;
            dfs(i);
            connctd_cmp_cnt++;
        }
    }

    /// there is only one cycle, so no need to add any edges.
    if (connctd_cmp_cnt == 1 && cmp_pro[0].first == cmp_pro[0].second) { puts("0");return 0;}
    vector< pair<int,int> > ans;

    /// connecting consecutive connected component
    for (int i = 0; i < connctd_cmp_cnt-1; ++i)
        ans.push_back(make_pair(cmp_pro[i].second, cmp_pro[(i+1)].first));

        /// at last connect first connected and last connected component,which makes total a strongly connected component.
        ans.push_back(make_pair(cmp_pro[connctd_cmp_cnt-1].second, cmp_pro[0].first));

    cout << (int)(ans.size()) << '\n';
    for(int y=0;y<(int)(ans.size());y++)
    {
       cout<<ans[y].first<<" "<<ans[y].second<<endl;
    }

    return 0;
}
