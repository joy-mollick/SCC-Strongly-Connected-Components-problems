
/// Codeforces : D - Substring.
/// Category : topological sort (kahn's algo) + dp .



#include<bits/stdc++.h>


using namespace std;

const int mx=300005;

int vis[mx],in_degree[mx],degree[mx],val[mx],dp[mx][26];

vector<int>adj[mx];

int V,ans,cnt;
string s;

bool topo()
{
     queue<int>st;
     int cnt=0;
       /// queue with all nodes with in-degree
      for(int i = 0; i <V; i++) {
        if (in_degree[i] == 0) {
            st.push(i);
        }
      }


    while (!st.empty()) {
        int u = st.front();
        st.pop();
        dp[u][s[u]-'a']++;
        vector<int>::iterator itr;
        for (itr = adj[u].begin();itr != adj[u].end(); itr++)
        {
            int v=(*itr);
            /// greedily compare maximum with parents
            for(int i=0;i<26;i++)
            dp[v][i]=max(dp[v][i],dp[u][i]);
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
    cin>>s;
    ans=0;
    V=n;
    while(m--)
    {
        cin>>u>>v;
        u--;
        v--;
        adj[u].push_back(v);
        in_degree[v]++;
        degree[v]++;
    }

    bool cycle=topo();
    if(!cycle)
    {
        cout<<"-1"<<endl;
        return 0;
    }
        int mx = 0;
        for (int i = 0; i < n; i++){
            for (int j = 0; j < 26; j++){
                mx = max(mx, dp[i][j]);
            }
        }
        cout << mx << "\n";

    return 0;
}
