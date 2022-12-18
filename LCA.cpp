#include <bits/stdc++.h>
#include <math.h>
using namespace std;
#define ll        long long int
#define  mod      1000000007
#define N        300005
#define yes      cout<<"YES"<<endl
#define no      cout<<"NO"<<endl
#define  fast  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
vector<ll>g[N+5];
ll dp[N][35],LOG;
ll depth[N];
void dfs(ll node,ll par,ll dis)
{
    dp[node][0]=par;
    depth[node]=dis;
    for(ll i=0; i<g[node].size(); i++)
    {
        ll child=g[node][i];
        if(child!=par)
        {
            dfs(child,node,dis+1);
        }
    }
}
void init(ll n)
{
    for(ll j=1; j<=LOG; j++)
    {
        for(ll i=1; i<=n; i++)
        {
            if(dp[i][j-1]!=-1)
            {
                ll par=dp[i][j-1];
                dp[i][j]=dp[par][j-1];
            }
        }
    }
}
ll LCA(ll a,ll b)
{
    if(depth[b]<depth[a])swap(a,b);

    ll k=depth[b]-depth[a];
    for(ll j=LOG-1; j>=0; j--)
    {
        if(k>=(1<<j))
        {
            b=dp[b][j];
            k-=(1<<j);
        }
    }
    if(a==b)return a;

    for(ll i=LOG-1; i>=0; i--)
    {
        if(dp[a][i]!=-1 && (dp[a][i]!=dp[b][i]))
        {
            a=dp[a][i];
            b=dp[b][i];
        }
    }
    return dp[a][0];
}
/*
ll getDist(int a , int b)
{
	ll lca=LCA(a,b);
	return depth[a] + depth[b] - 2*depth[lca];
}
*/
void solve()
{
    //freopen("textnew.txt","r",stdin);
    vector<ll>v;
    map<ll,ll>mp;
    ll n,e,i,j,l,m,y,z,x,k;
    cin>>n>>m;
    for(i=2; i<=n; i++)
    {
        ll u,v;
        cin>>u;
        v=i;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    LOG=0;
    while((1<<LOG)<=n)
    {
        LOG++;
    }
    for(i=0; i<=n; i++)
    {
        for(j=0; j<=LOG; j++)
        {
            dp[i][j]=-1;
        }
    }
    dfs(1,-1,0);
    init(n);
    while(m--)
    {
        ll u,v;
        cin>>u>>v;
        ll ans=LCA(u,v);
        cout<<ans<<endl;
    }

}
int main()
{
    fast;
    int T=1;
    //cin>>T;
    while(T--)solve();
    return 0;
}


