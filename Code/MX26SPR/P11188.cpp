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
string s;
int v[10],n;
ll dp[N][10],pw[10];
inline void solve(){
    cin>>s;
    rp(i,9)cin>>v[i];
    pw[0]=1;
    rep(i,1,9)pw[i]=pw[i-1]*10;
    n=s.size(),s='#'+s;
    rep(i,0,n)rep(j,0,9)dp[i][j]=1e18;
    dp[n+1][0]=0;
    per(i,1,n)rep(j,0,9){
        dp[i][j]=min(dp[i][j],dp[i+1][j]+v[s[i]-'0']);
        if(j!=9)dp[i][j+1]=min(dp[i][j+1],dp[i+1][j]+(s[i]-'0')*pw[j]);
    }
    ll ans=1e18;
    rep(j,0,9)ans=min(ans,dp[1][j]);
    cout<<ans<<'\n';
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int tid,t;
    cin>>tid>>t;
    rd(_,t)solve();
    return 0;
}