
/// Codeforces : 1253D - Harmonious Graph.
/// Category : graph + dsu.


/// we use disjoint set union to find out our minimum edges needed to be added
/// if i is connected to i+m , then obviously i,i+1,i+2....i+m should be in the same connected component
/// when we make union of two different nodes , then we make bigger node parent to smaller one .

/// so from i=2 to n we will traverse
/// if father of (i-1) is (i-1) then there is no problem .
/// But ,if father of (i-1) is greater than i and ith father is not father of (i-1) then it is clear that (i) is not in the connected component of  i-1.
/// so make union (i,i-1)

#include<bits/stdc++.h>


using namespace std;

const int mx=200005;

int par[mx];

/// log(n)
int finder(int i)
{
    if(par[i]!=i) par[i]=finder(par[i]);
    return par[i];
}

/// log(n) in average
void Union(int x,int y)
{
    int xroot=finder(x);
    int yroot=finder(y);
    /// assigning bigger one to smaller one
     if(xroot!=yroot)
    {
        if(xroot<yroot)
        par[xroot]=yroot;
        else
        par[yroot]=xroot;
    }
}

int main()

{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n,m,u,v;
    cin>>n>>m;

    for(int i=1;i<=n;i++) par[i]=i;

    while(m--)
    {
        cin>>u>>v;
        Union(u,v);
    }

    int ans=0;

    for(int i=2;i<=n;i++)
    {
        int prev=finder(i-1);
        int now=finder(i);
        /// prev node has been added to bigger than i node
        /// which implies i should also be added
        if(prev!=now && prev>i)
        {
            Union(i,i-1);
            ans++;
        }
    }

    cout<<ans<<endl;

	return 0;
}
