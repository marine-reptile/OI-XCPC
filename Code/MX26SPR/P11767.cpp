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
const int N=200005;
const int P=1000000007;
int n,m,q,x,t,fac[N],ifac[N],s[N];
inline int fpow(int x,int p){
    int res=1,cur=x;
    rep(i,0,30){
        if(p>>i&1)res=1ll*res*cur%P;
        cur=1ll*cur*cur%P;
    }
    return res;
}
inline int C(int n,int m){
    if(n<0||m<0||n<m)return 0;
    return 1ll*fac[n]*ifac[m]%P*ifac[n-m]%P;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n>>m>>q;
    fac[0]=ifac[0]=1;
    rep(i,1,n)fac[i]=1ll*fac[i-1]*i%P;
    rep(i,1,n)ifac[i]=fpow(fac[i],P-2);
    rep(i,1,n)s[i]=(s[i-1]+C(i,m-1))%P;
    rp(i,q){
        cin>>x>>t;
        int ans=0;
        int A=max(0,min(x-1,n-t)-max(x-t,1)+1);
        int B=max(0,x-1-t)+max(0,n-t-(x+1)+1);
        ans=(ans+1ll*A*C(t-1,m-1)%P)%P;
        ans=(ans+1ll*B*C(t,m-1)%P)%P;
        int d=max(1,n-t+1),D=n-d+1;
        if(d<=x&&x<=n)D--;
        if(D>=1)ans=(ans+s[D-1])%P;
        cout<<1ll*ans*fac[m]%P<<'\n';
    }
    return 0;
}