
/// Codeforces : 711D - Directed Roads.
/// Category : cycle finding + combinatorics.


/// You have to find out the length of the all cycles 
/// So, you can choose set from these cycles in the 2^len-2 ways 
/// because empty and full set will not be considered.(if full set will be flipped again it will be cyclic)
/// two set will not be considered here .


/// you can find cycle length by scc algorithm also 


#include<bits/stdc++.h>


using namespace std;

const int mx=200005;

typedef long long ll;

const ll mod=1e9+7;

ll res=1ll;
ll tot=0ll;

ll depth[mx];
int go[mx];
int par[mx];

 ll pow(ll a,ll b)
{
    ll ans=1ll;
    while(b)
    {
        if(b&1ll) ans=(ans*a)%mod;

        a=(a*a)%mod;
        b=b>>1ll;
    }
    return (ans%mod);
}

 void dfs(int u,int deep,int father)
 {
     par[u]=father;
     depth[u]=deep;
     int v=go[u];
     if(!par[v]) dfs(v,deep+1,father);
     else if(par[v]==father)
     {
         ll cycle_len=depth[u]-depth[v]+1ll;
         res=(res*(pow(2ll,cycle_len)-2ll+mod)%mod);
         res%=mod;
         tot+=cycle_len;
     }
 }


int main()

{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll n,x;
    cin>>n;

    for(int i=1;i<=n;i++)
    {
        cin>>x;
        go[i]=x;
    }

    for(int i=1;i<=n;i++)
    {
        if(!par[i])
        {
            dfs(i,0,i);
        }
    }

    res=(res*(pow(2ll,n-tot))%mod)%mod;

    cout<<res<<endl;

	return 0;
}
