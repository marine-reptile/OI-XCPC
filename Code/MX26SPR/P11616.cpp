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
const int N=10000007;
const int P=998244353;
inline int fpow(int x,int p){
    int res=1,cur=x;
    rep(i,0,30){
        if(p>>i&1)res=1ll*res*cur%P;
        cur=1ll*cur*cur%P;
    }
    return res;
}
int n,m,a[N],fac[N],ifac[N-5];
inline int C(int n,int m){
    if(n<0||m<0||n<m)return 0;
    return 1ll*fac[n]*ifac[m]%P*ifac[n-m]%P;
}
inline void init(){
    fac[0]=ifac[0]=1;
    rep(i,1,N-5)fac[i]=1ll*fac[i-1]*i%P;
    rep(i,1,N-5)ifac[i]=1ll*ifac[i-1]*fac[i]%P;
    ifac[N-5]=fpow(ifac[N-5],P-2);
    per(i,1,N-5){
        int tmp=ifac[i];
        ifac[i]=1ll*ifac[i]*ifac[i-1]%P;
        ifac[i-1]=1ll*tmp*fac[i]%P;
    }
    // rep(i,1,10)cout<<1ll*fac[i]*ifac[i]%P<<' ';
    // cout<<endl;
}
inline void solve(){
    cin>>n>>m;
    rp(i,n)cin>>a[i];
    int x=0;
    rp(i,n-1)if(a[i]>=a[i+1])x++;
    int ans=0;
    rep(i,1,m){
        if(x>i-1)continue;
        ans=(ans+C(n-1-x,i-1-x))%P;
    }
    cout<<ans<<'\n';
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    init();
    int t;
    cin>>t;
    rd(_,t)solve();
    return 0;
}