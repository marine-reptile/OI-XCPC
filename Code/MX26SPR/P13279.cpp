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
const int N=500005;
int n,k,a,b,dep[N],mxdep[N];
vt<int>G[N];
ll ans=0;

inline void dfs(int x,int p){
    dep[x]=dep[p]+1,mxdep[x]=dep[x];
    for(auto i:G[x])if(i!=p){
        dfs(i,x);
        mxdep[x]=max(mxdep[x],mxdep[i]);
    }
    int cnt=0;
    for(auto i:G[x])if(i!=p){
        cnt++;
        if(mxdep[i]!=mxdep[x]){
            ans++;
        }
    }
    if(cnt!=0&&cnt<k)ans+=k-cnt;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n>>k;
    rp(i,n-1){
        cin>>a>>b;
        G[a].pb(b);
        G[b].pb(a);
    }
    dep[0]=-1;
    dfs(1,0);
    cout<<mxdep[1]<<' '<<ans<<'\n';
    return 0;
}