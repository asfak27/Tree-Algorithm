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
ll vis[N];
ll dis[N];
void dfs(ll node,ll par,ll cnt)
{
    vis[node]=1;
    dis[node]=cnt;
    for(ll i=0;i<g[node].size();i++)
    {
        ll child=g[node][i];
        if(vis[child]==0 && child!=par)
        {
            dfs(child,node,cnt+1);
        }
    }
}

void solve()
{
    //freopen("textnew.txt","r",stdin);
    vector<ll>v;
    map<ll,ll>mp;
    ll n,e,i,j,l,m,y,z,x,k;
    cin>>n;

    for(i=1;i<n;i++)
    {
        ll u,v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    ///find 1st longest node
    dfs(1,-1,0);

    ll node1=-1,node2=-1,mx=0;

    for(i=1;i<=n;i++)
    {
        if(mx<dis[i])
        {
            mx=dis[i];
            node1=i;
        }
    }
    ///find 2nd longest node
    for(i=1;i<=n;i++)
    {
        dis[i]=0;
        vis[i]=0;
    }
    mx=0;
    dfs(node1,-1,0);

    for(i=1;i<=n;i++)
    {
        if(mx<dis[i])
        {
            mx=dis[i];
            node2=i;
        }
    }
    ///find maximum distance node2 to other node

    vector<ll>p,q;
    p.push_back(0);
    for(i=1;i<=n;i++)
    {
        p.push_back(dis[i]);
    }
    ///find maximum distance node1 to other node
    for(i=1;i<=n;i++)
    {
        dis[i]=0;
        vis[i]=0;
    }

    dfs(node2,-1,0);
    q.push_back(0);
    for(i=1;i<=n;i++)
    {
        q.push_back(dis[i]);
    }

    ///final distance
    cout<<dis[node1]<<endl;

    /*for(i=1;i<=n;i++)
    {
        v.push_back(max(p[i],q[i]));
    }
    for(i=0;i<v.size();i++)
    {
        cout<<v[i]<<" ";
    }
    cout<<endl;*/
}
int main()
{
    fast;
    int T=1;
    //cin>>T;
    while(T--)solve();
    return 0;
}

/*#include <bits/stdc++.h>
#include <math.h>
using namespace std;
#define ll        long long int
#define  mod      1000000007
#define N        300005
#define yes      cout<<"YES"<<endl
#define no      cout<<"NO"<<endl
#define  fast  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
vector<ll>g[N+5];
ll vis[N];
ll mx=0,x,k;
void dfs(ll node,ll dis)
{
    vis[node]=1;

    if(dis>mx)
    {
        mx=dis;
        k=node;
    }
    for(ll i=0;i<g[node].size();i++)
    {
        ll child=g[node][i];
        if(vis[child]==0)
        {
            dfs(child,dis+1);
        }
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
    dfs(1,0);///first longest node
    for(i=0;i<=n;i++)
    {
        vis[i]=0;
    }
    mx=0;
    dfs(k,0);///first longest node to 2nd longest node
    cout<<mx<<endl;
}
int main()
{
    fast;
    int T=1;
    //cin>>T;
    while(T--)solve();
    return 0;
}*/
