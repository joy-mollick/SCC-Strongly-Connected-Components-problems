
/// Codeforces : 915D - Almost Acyclic Graph.
/// Category : greedy + cycle detecting by indegree .
/// Fantastic Classical One 

/// we used kahn's algorithm here which return whatever the graph is cycle or not ?
/// we decrease an in degree and check ,there is a cycle or not ?

#include<bits/stdc++.h>


using namespace std;

const int mx=501;

typedef long long ll;

vector<int>adj[mx];
int in_degree[mx];
int real_in_degree[mx];
int V;

bool topo()
{
     queue<int>st;
     int cnt=0;
       /// queue with all nodes with in-degree
      for(int i = 1; i <= V; i++) {
        if (in_degree[i] == 0) {
            st.push(i);
        }
      }


    while (!st.empty()) {
        int u = st.front();
        st.pop();

        vector<int>::iterator itr;
        for (itr = adj[u].begin();itr != adj[u].end(); itr++)
        {
            int v=(*itr);
            /// removing edge from u
            --in_degree[v];
            if (in_degree[v] == 0)
            {
                st.push(v);
            }
        }

        cnt++;
    }
    /// there is no cycle
    if(cnt==V) return true;
    else return false;
}

int main()

{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n,m,u,v;

    cin>>n>>m;
    V=n;

    while(m--)
    {
        cin>>u>>v;
        adj[u].push_back(v);
        in_degree[v]++;
        real_in_degree[v]++;
    }

    /// there is no ring
    if(topo())
    {
        cout<<"YES"<<endl;
        return 0;
    }

    for(int i=1;i<=n;i++)
    {
        /// copy real_in_degree to in_degree
        memcpy(in_degree,real_in_degree,sizeof(real_in_degree));
        /// if i is in the cycle then in_degree i will be of course >=1
        if(in_degree[i]>=1)
        {
            /// assuming this edge has been removed
            in_degree[i]--;
            if(topo())
            {
                cout<<"YES"<<endl;
                return 0;
            }
        }
    }

    cout<<"NO"<<endl;

    return 0;
}
