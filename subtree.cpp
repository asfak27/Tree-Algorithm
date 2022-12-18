#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define  no               cout<<"NO"<<endl
#define  yes              cout<<"YES"<<endl
#define  mod       1000000007
#define  N       2000005
#define  fast  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
vector<ll>g[N];
ll subtree[N];
void dfs(ll node,ll p)//p=parent ,n=node
{
    subtree[node]=1;
    for(ll i=0;i<g[node].size();i++)
    {
        ll child=g[node][i];
        if(child!=p)
        {
            dfs(child,node);
            subtree[node]+=subtree[child];
        }
    }
}
void solve()
{
    map<ll,ll>mp;
    ll n,j,i,y,z,l,r,d,x,k,m;
    cin>>n;
    ll a[n+1];
    for(i=2; i<=n; i++)
    {
        cin>>a[i];
        g[a[i]].push_back(i);
        g[i].push_back(a[i]);
    }
    dfs(1,-1);
    for(i=1;i<=n;i++)
    {
        cout<<subtree[i]-1<<" ";
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
