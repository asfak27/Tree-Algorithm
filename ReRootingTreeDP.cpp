#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define  no               cout<<"NO"<<endl
#define  yes              cout<<"YES"<<endl
#define  mod       1000000007
#define  N       2000005
#define  fast  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
vector<ll>g[N];
ll subtree[N],n;
ll subdis[N]; ///subdistance
ll res[N];
void dfs(ll node,ll par)
{
    subtree[node]=1;
    for(ll i=0;i<g[node].size();i++)
    {
        ll child=g[node][i];
        if(child!=par)
        {
            dfs(child,node);
            subtree[node]+=subtree[child];
            subdis[node]+=subtree[child]+subdis[child];
        }
    }
}
void dfs1(ll node,ll par)
{
    res[node]=res[par] - (subtree[node]+subdis[node]) + n - subtree[node] + subdis[node];
    for(ll i=0;i<g[node].size();i++)
    {
        ll child=g[node][i];
        if(child!=par)
        {
            dfs1(child,node);
        }
    }
}
void solve()
{
    map<ll,ll>mp;
    ll j,i,y,z,l,r,d,x,k,m;
    cin>>n;
    for(i=1; i<n; i++)
    {
        ll u,v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1,-1);
    res[1]=subdis[1];

    for(i=0;i<g[1].size();i++)
    {
        ll child=g[1][i];
        dfs1(child,1);
    }

    for(i=1;i<=n;i++)
    {
        cout<<res[i]<<" ";
    }
    cout<<endl;

}
int main()
{
    fast;
    int T=1;
    // cin>>T;
    while(T--)solve();
    return 0;
}
