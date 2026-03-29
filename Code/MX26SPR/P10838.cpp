#include<bits/stdc++.h>
using namespace std;
#define rd(i,n) for(int i=0;i<n;i++)
#define rp(i,n) for(int i=1;i<=n;i++)
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define per(i,a,b) for(int i=b;i>=a;i--)
#define vt vector
#define pb push_back
//#define int long long
typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef unsigned long long ull;
const int N=100005;
int n,m,k,s,t,a,b,c;
ll A[N],B[N],p[N];
vt<pii>G[N];
inline void dfs_dist(int x,int p,ll *h){
    for(auto i:G[x])if(i.first!=p){
        h[i.first]=h[x]+i.second;
        dfs_dist(i.first,x,h);
    }
}
inline bool check(ll w){
    ll tot=0;
    rep(i,1,n){
        //b[j]<=w-a[i]-k
        ll sum=upper_bound(p+1,p+1+n,w-A[i]-k)-p-1;
        for(auto j:G[i]){
            if(B[j.first]<=w-A[i]-k)sum--;
        }
        if(B[i]<=w-A[i]-k)sum--;
        tot+=sum;
    }
    return tot>m;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n>>m>>k>>s>>t;
    rp(i,n-1){
        cin>>a>>b>>c;
        G[a].pb({b,c});
        G[b].pb({a,c});
    }
    dfs_dist(s,0,A);
    dfs_dist(t,0,B);
    rp(i,n)p[i]=B[i];
    sort(p+1,p+1+n);
    ll totans=min(A[t],1000000000ll);
    ll l=0,r=1000000000ll,mid,ans=1000000000ll;
    while(l<=r){
        mid=(l+r)>>1;
        if(check(mid)){
            ans=mid,r=mid-1;
        }else{
            l=mid+1;
        }
    }
    cout<<min(totans,ans)<<'\n';
    return 0;
}