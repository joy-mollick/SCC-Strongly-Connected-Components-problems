
/// Topological Sort(kahn's algo) + backtracking
/// printing all topological sort 


#include<bits/stdc++.h>

using namespace std;

const int mx=1001;

map<char,int>mapping;
map<int,char>mapping2;

int in_degree[mx];
bool visited[mx];

vector<int>adj[mx];
vector<char>vec;
vector<int>::iterator it;

int V;

void all_topo_sort(vector<int>& ans,bool *visited)
{
    int v;
    bool flag =false;

    for(int i=1;i<=V;i++)
    {
        if(in_degree[i]==0 && !visited[i])
        {
            for(it=adj[i].begin();it!=adj[i].end();it++)
            {
                v=(*it);
                in_degree[v]--;
            }

            ans.push_back(i);
            visited[i]=true;
            all_topo_sort(ans,visited);

            visited[i]=false;
            ans.erase(ans.end()-1);
            for(it=adj[i].begin();it!=adj[i].end();it++)
            {
                v=(*it);
                in_degree[v]++;
            }

            flag=true;
        }
    }
    /// one topological order print lexicographically
    if (!flag)
    {
        for (int i = 0; i < ans.size(); i++)
            cout << mapping2[ans[i]];

        cout << endl;
    }
}

int main()
{
    /// directed graph
    int E,u,v,tc=0;
    char a,b;

    string st;

    while(getline(cin,st))
    {
    if(tc>0)
    {
        cout<<endl;
    }
    for(int j=0;j<mx;j++)
    {
        adj[j].clear();
        in_degree[j]=0;
        visited[j]=false;
    }
    mapping.clear();
    mapping2.clear();
    vec.clear();

    stringstream str(st);

     int counts=0;
     int id=1;

     while(str>>a) {counts++;vec.push_back(a);}

     sort(vec.begin(),vec.end());

     for(int k=0;k<(int)vec.size();k++)
     {
        mapping[vec[k]]=id;
        mapping2[id]=vec[k];
        id++;
     }

     V=counts;

    getline(cin,st);
    stringstream str1(st);

    while(str1>>a)
    {
        str1>>b;
        ///u-v,like edge
        u=mapping[a];
        v=mapping[b];
        adj[u].push_back(v);
        in_degree[v]++;
    }

   vector<int>ans;
   all_topo_sort(ans,visited);
   tc++;
    }
    return 0;
}
