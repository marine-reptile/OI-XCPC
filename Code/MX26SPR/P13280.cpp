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
const int N=10000005;
const int P=998244353;
int fac[N],n,m,k;
inline void solve(){
    cin>>n>>m>>k;
    if(m==0){
        cout<<1ll*k*fac[n]%P<<'\n';
        return;
    }
    int cnt=0;
    for(int i=1;i*i<=m;i++)if(m%i==0){
        if(i<=n)cnt++;
        if(i*i!=m&&m/i<=n)cnt++;
    }
    int ans=1ll*k*cnt%P*fac[n-1]%P;
    ans=(ans+(1ll*n*(n+1)/2%P-k+P)%P*(n-cnt)%P*fac[n-2]%P)%P;
    cout<<ans<<'\n';
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    fac[0]=1;
    rep(i,1,N-5)fac[i]=1ll*fac[i-1]*i%P;
    int t;
    cin>>t;
    rd(_,t)solve();
    return 0;
}