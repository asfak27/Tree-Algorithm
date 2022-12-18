#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define  no               cout<<"NO"<<endl
#define  yes              cout<<"YES"<<endl
#define  mod       1000000007
//#define  N         100005
#define  fast  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
struct BIT
{
    ll N;
    vector<ll> bit;
    void init(ll n)
    {
        N = n;
        bit.assign(n + 1, 0);
    }
    void update(ll idx, ll val)
    {
        while(idx <= N)
        {
            bit[idx] += val;
            idx += idx & -idx;
        }
    }
    ll query(ll idx)
    {
        ll ans = 0;
        while(idx > 0)
        {
            ans += bit[idx];
            idx -= idx & -idx;
        }
        return ans;
    }
    ll rsum(ll l,ll r)
    {
        return query(r)-query(l - 1);
    }
};
void solve()
{

    ll n,i,j;
    cin>>n;
    ll a[n+1];
    for(i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    BIT q;
    q.init(n+1);
    ll ans=0;
    for(i=1;i<=n;i++)
    {
        ans+=q.rsum(a[i],n);
        q.update(a[i],1);
    }
    cout<<ans<<endl;

}
int main()
{
    fast;
    int T=1;
    cin>>T;
    while(T--)solve();
    return 0;
}
