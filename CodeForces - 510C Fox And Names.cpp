
/// A must do problem of topological sort
/// Topological Sort Classical One
/// Some strings are listed
/// You have to say,what kind of sequence of a-z should be to make the strings as sorted.Or Impossible

#include<bits/stdc++.h>

using namespace std;

const int mx=1005;

#define black 1
#define gray 2
#define white 0

vector<int>adj[mx];
stack<int>st;
int color[mx];
int V,cnt;
bool cycle=false;
/// cycle detecting
/// + topologically sort by pushing character into stack
   void cyclic_dfs(int u)
{
    color[u]=gray;
    for(int i=0; i<adj[u].size(); i++)
    {
        int v=adj[u][i];
        /// v is in process ,so it is cycle
        if(color[v]==gray)
        {
            cycle=true;
             return;
        }
        /// not process ? push them into process
         else if(color[v]==white)
        {
            cyclic_dfs(v);
        }
    }
    color[u]=black;
    st.push(u);
}

int main()
{
    int e,u,v,n,cnt=0,flag=0,x,y;
    cin>>n;
    string s[n];

    for(int i=0;i<n;i++)
    {
        cin>>s[i];
    }

    for(int i=0; i<n-1; i++)
    {
        x=s[i].size();
        y=s[i+1].size();
        cnt=0;
        for(int j=0;j<min(x,y);j++)
        {
    ///finding the first character which does not match with the next one
            if(s[i][j]!=s[i+1][j])
            {
                u=(int)s[i][j];
                v=(int)s[i+1][j];
                adj[u].push_back(v);
                cnt++;
                break;
            }

        }
        ///first one is greater than second one
        ///And second one is a prefix of first one
        /// implies,impossible
        if(x>y&&cnt==0)
            flag=1;
    }

    ///stack will keep reversely,so we will run also from reversely
    for(int i=122; i>=97; i--)
    {
        if(color[i]==white)
        {
            cyclic_dfs(i);
        }
    }
    if(cycle||flag==1)
    {
        cout<<"Impossible"<<endl;
        return 0;
    }

    else
    {
       while(!st.empty())
       {
           cout<<(char)(st.top());
           st.pop();
       }
    }

    return 0;
}
