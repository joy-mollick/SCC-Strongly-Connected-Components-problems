
///Kahn’s algorithm.
///It's main logic is
///every Directed Acyclic Graph(DAG) has at least one vertex with in-degree 0 and one vertex with out-degree 0.
///So,first the nodes with zero in-degree and store them into a stack.
///Then pop a node from stack and remove that edge i.e.decrease the in-degree of the neighbor nodes of that edge
///Also,we can detect cycle by this algorithm.

#include<bits/stdc++.h>

using namespace std;

const int mx=10001;

vector<int>adj[mx];
queue<int>st;
int in_degree[mx];
int V,cnt;

void kahn_algorithm()
{
    for(int u=1;u<=V;u++)
    {
        ///calculating in_degree of each node.
        vector<int>::iterator it;
        for(it=adj[u].begin();it!=adj[u].end();it++)
        {
            int v=(*it);
            in_degree[v]++;
        }
    }

        /// queue with all nodes with in-degree
      for(int i = 1; i <= V; i++) {
        if (in_degree[i] == 0) {
            st.push(i);
        }
      }

    /// lexicographically topological sort order
    vector<int> top_order;

    while (!st.empty()) {
        int u = st.front();
        st.pop();
        top_order.push_back(u);


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

    /// Check if there was a cycle
    if (cnt != V)
    {
        cout<<"Cycle Exits\n";
        return;
    }

    /// Print topological order
    for (int i=0; i<top_order.size(); i++)
    {
        cout<<top_order[i]<<" ";
    }
    cout<<endl;

}

int main()
{
    int e,u,v;

    int tc;

    cin>>V>>e;

    while(e--)
    {
        cin>>u>>v;
        adj[u].push_back(v);
    }

    kahn_algorithm();

    return 0;
}
