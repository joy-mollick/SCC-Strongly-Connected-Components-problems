#include<bits/stdc++.h>
using namespace std;

vector <int> G[105];
vector <int> processed;
queue <int> q;
int n, m;
int indegree[105];

void topsort()
{
    int u;
    while(!q.empty())
    {
        u=q.front();
        q.pop();
        processed.push_back(u);
        for(int i=0; i<G[u].size(); i++)
        {
            int v=G[u][i];
            indegree[v]--;
            if(indegree[v]==0)
            {
                q.push(v);
            }
        }
    }
}

int main()
{
    int u, v;
    while(scanf("%d%d", &n, &m)==2)
    {
        if(n==0 && m==0)
            break;
        memset(indegree, 0, sizeof(indegree));
        for(int i=0; i<m; i++)
        {
            scanf("%d%d", &u, &v);
            indegree[v]++;
            G[u].push_back(v);
        }
        for(int i=1; i<=n; i++)
        {
            if(indegree[i]==0)
            {
                q.push(i);
            }
        }
        topsort();
        for(int i=0; i<processed.size(); i++)
        {
            if(i== (processed.size()-1))
            {
                printf("%d", processed[i]);
            }
            else
            {
                printf("%d ", processed[i]);
            }
        }
        processed.clear();
        for(int i=1; i<=n; i++)
        {
            G[i].clear();
        }
        printf("\n");
    }
    return 0;
}
