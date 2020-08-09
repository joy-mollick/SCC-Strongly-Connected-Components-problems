
/// Topological Sort(kahn's algo) modification 
/// Time-490ms

#include<bits/stdc++.h>

using namespace std;

const int mx=1005;

vector<int>adj[mx];
typedef pair<int,int> pii;
/// min heap
priority_queue <pii, vector<pii>, greater<pii>> st;
bool visited[mx]={false};
int in_degree[mx];
int V,cnt;

void kahn_algorithm()
{
    vector< pair<int,int> >real;
    for(int u=0;u<V;u++)
    {
        ///calculating in_degree of each node.
        vector<int>::iterator it;
        for(it=adj[u].begin();it!=adj[u].end();it++)
        {
            int v=(*it);
            in_degree[v]++;
        }
    }

        /// min_heap with all nodes with in-degree.
        /// initially all with id 1
      for(int i = 0; i <V; i++) {
        if (in_degree[i] == 0) {
            st.push(make_pair(i,1));
            visited[i]=true;
        }
      }

    ///lexicographically sort order and keep its level from its previous
    vector<pii> top_order;
    int curr_lev;
    while (!st.empty()) {
        pii u = st.top();
        st.pop();
        top_order.push_back(u);
        curr_lev=u.second;

        vector<int>::iterator itr;
        for (itr = adj[u.first].begin();itr != adj[u.first].end(); itr++)
        {
            int v=(*itr);
        /// if not in stack ,then proceed
            if(!visited[v])
            {
            /// removing edge from u
            --in_degree[v];
            if (in_degree[v] == 0)
            {
                st.push(make_pair(v,curr_lev+1));
            /// now in stack
                visited[v]=true;
            }

            }
        }

        cnt++;
    }

    /// Check if there was a cycle
    if (cnt != V)
    {
        cout<<"-1\n";
        return;
    }
    /// Print topological order
    for (int i=0; i<top_order.size(); i++)
    {
        real.push_back(make_pair(top_order[i].second,top_order[i].first));
    }
    sort(real.begin(),real.end());
     for (int i=0; i<real.size(); i++)
    {
        cout<<real[i].first<<" "<<real[i].second<<endl;
    }
    cout<<endl;

}

int main()
{
    int e,u,v;

    int tc;

    cin>>tc;

    for(int t=1;t<=tc;t++)
    {

    for(int j=0;j<mx;j++)
    {
        adj[j].clear();
        in_degree[j]=0;
        visited[j]=false;
    }
    cnt=0;

    while(!st.empty()) st.pop();

    cin>>V>>e;

    while(e--)
    {
        cin>>u>>v;
        adj[v].push_back(u);
    }

    cout<<"Scenario #"<<t<<":"<<endl;
    kahn_algorithm();

    }

    return 0;
}
