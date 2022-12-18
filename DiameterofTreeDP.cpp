#include <bits/stdc++.h>
#include <math.h>
using namespace std;
#define ll        long long int
#define  mod      1000000007
#define N        300005
#define yes      cout<<"YES"<<endl
#define no      cout<<"NO"<<endl
#define  fast  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
vector<ll>g[N];
ll vis[N];
ll level[N];
ll f[N];
ll ans;
void dfs(ll node,ll par)
{
    vector<ll>v;
    for(ll i=0;i<g[node].size();i++)
    {
        ll child=g[node][i];
        if(child!=par)
        {
            dfs(child,node);
            level[node]=max(level[node],level[child]+1);
            v.push_back(level[child]);
        }
    }
    ans=max(ans,level[node]);

    sort(v.begin(),v.end());
    if(v.size()>=2)
    {
        f[node]=2+v[v.size()-1]+v[v.size()-2];
        ans=max(ans,f[node]);
    }
}
void solve()
{
    //freopen("textnew.txt","r",stdin);
    vector<ll>v;
    map<ll,ll>mp;
    ll n,e,i,j,l,m,y,z;
    cin>>n;

    for(i=1;i<n;i++)
    {
        ll u,v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1,-1);
    cout<<ans<<endl;
}
int main()
{
    fast;
    int T=1;
    //cin>>T;
    while(T--)solve();
    return 0;
}

