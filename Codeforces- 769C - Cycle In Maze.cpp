
/// Codeforces- 769C - Cycle In Maze.
/// Category: greedy + cycle of k length + bfs.


#include<bits/stdc++.h>

using namespace std;

typedef long long ll;


const int mx=1002;

char mat[mx][mx];
int dist[mx][mx];

string str="DLRU";

/// sorted according to DLRU
int dx[4]={1,0,0,-1};
int dy[4]={0,-1,1,0};

bool ok(int x,int y,int n,int m)
{
    if(x>=1 && y>=1 && x<=n && y<=m && mat[x][y]!='*') return true;
    else return false;
}

int main()

{
    int n,m,K,robotx,roboty;
    cin>>n>>m>>K;

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cin>>mat[i][j];
            if(mat[i][j]=='X')
            {
                robotx=i;
                roboty=j;
            }
            /// initially make distances of all indices infinite
                dist[i][j]=INT_MAX;
        }
    }

    queue< pair<int,int> >pq;
    pq.push(make_pair(robotx,roboty));
    dist[robotx][roboty]=0;
    int curr_x,curr_y,next_x,next_y;
    pair<int,int>p;

    while(!pq.empty())
    {
        p=pq.front();
        curr_x=p.first;
        curr_y=p.second;
        pq.pop();
        for(int i=0;i<4;i++)
        {
            next_x=curr_x+dx[i];
            next_y=curr_y+dy[i];

            if(ok(next_x,next_y,n,m) && (dist[next_x][next_y]>dist[curr_x][curr_y]+1))
            {
                dist[next_x][next_y]=dist[curr_x][curr_y]+1;
                pq.push(make_pair(next_x,next_y));
            }
        }
    }

    string ans="";
    curr_x=robotx;
    curr_y=roboty;
    int i;

    for(int k=0;k<K;k++)
    {
        /// it is already sorted greedily
        for( i=0;i<4;i++)
        {
            next_x=curr_x+dx[i];
            next_y=curr_y+dy[i];
            /// at each k step, K-1-k is the maximum distance robot can travel.
            ///so that it can come back to initial position by K steps.
            if(ok(next_x,next_y,n,m) && dist[next_x][next_y]<=K-1-k)
            {
                break;
            }
        }

        ///there is no way to go from curr_x and curr_y.
        if(i==4)
        {
            cout<<"IMPOSSIBLE"<<endl;
            return 0;
        }

        curr_x+=dx[i];
        curr_y+=dy[i];

        ans+=str[i];
    }

    cout<<ans<<endl;

    return 0;
}
