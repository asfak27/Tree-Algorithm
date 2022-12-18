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
void binary_lifting(ll node,ll par,ll cnt)
{
    dp[node][0]=par;
    depth[node]=cnt;
    for(ll i=1; i<=32; i++)
    {
        if(dp[node][i-1]!=-1)
        {
            dp[node][i]=dp[ dp[node][i-1] ][i-1];
        }
    }
    for(ll i=0; i<g[node].size(); i++)
    {
        ll child=g[node][i];
        if(child!=par)
        {
            binary_lifting(child,node,cnt+1);
        }
    }
}
ll query(ll node,ll k)
{
    if(depth[node]<k)return -1;
    for(ll j=LOG-1; j>=0; j--)
    {
        if(k>=(1<<j))
        {
            node=dp[node][j];
            k-=(1<<j);
        }
    }
    return node;
}

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
    binary_lifting(1,-1,0);
    LOG=0;
    while((1<<LOG)<=n)
    {
        LOG++;
    }
    while(m--)
    {
        ll node,k;
        cin>>node>>k;
        cout<<query(node,k)<<endl;
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

