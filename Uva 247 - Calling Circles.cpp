
#include<bits/stdc++.h>

using namespace std;

const int mx=30;

bool visited[mx]={false};
bool nwvisited[mx]={false};
vector<int>adj[mx];
vector<int>rev[mx];
map<string,int>mapping;
map<int,string>idd;
vector<string>vec[mx];
int cnt;
stack<int>st;

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
    st.push(u);
}

void dfs2(int u)
{
    vec[cnt].push_back(idd[u]);
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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    /// directed graph
    int V,E,t;
    int caso=1;
    string u,v;
    while(cin>>V>>E && (V!=0&&E!=0))
    {
        for(int k=0;k<mx;k++)
        {
            adj[k].clear();
            rev[k].clear();
            visited[k]=false;
            nwvisited[k]=false;
            vec[k].clear();
        }
    int id=1;
    cnt=0;
    while(E--)
    {
            cin>>u>>v;
            if(mapping[u]==0)
            {
                mapping[u]=id;
                idd[id]=u;
                id++;
            }
            if(mapping[v]==0)
            {
                mapping[v]=id;
                idd[id]=v;
                id++;
            }
            adj[mapping[u]].push_back(mapping[v]);
            rev[mapping[v]].push_back(mapping[u]);
    }

    for(int i=1;i<=V;i++)
    {
        if(!visited[i]) dfs(i);
    }

    while(!st.empty())
    {
        int node=st.top();
        st.pop();
        if(!nwvisited[node])
        {
            dfs2(node);
            cnt++;
        }
    }

        if (caso!=1) cout << endl;
        cout << "Calling circles for data set " << caso << ":" << endl;

        for (int i=0; i<cnt; ++i)
        {
            for (int j=0; j<vec[i].size()-1; ++j)
            {
                cout<<vec[i][j]<< ", ";
            }
            cout<<vec[i].back()<<endl;
        }

        caso++;
        mapping.clear();
        idd.clear();
    }

    return 0;
}
