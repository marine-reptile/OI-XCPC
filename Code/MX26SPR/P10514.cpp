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
const int P=998244353;
int n,m,k,a[N],fac[N],ifac[N];
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
    cin>>n>>m>>k;
    rp(i,m)cin>>a[i];
    fac[0]=ifac[0]=1;
    rep(i,1,n)fac[i]=1ll*fac[i-1]*i%P;
    rep(i,1,n)ifac[i]=1ll*ifac[i-1]*fac[i]%P;
    ifac[n]=fpow(ifac[n],P-2);
    per(i,1,n){
        int tmp=ifac[i];
        ifac[i]=1ll*ifac[i]*ifac[i-1]%P;
        ifac[i-1]=1ll*tmp*fac[i]%P;
    }
    int A=1,B=1;
    rep(i,1,m){
        A=1ll*A*C(n-k,a[i])%P;
        B=1ll*B*C(n,a[i])%P;
    }
    cout<<1ll*A*fpow(B,P-2)%P<<'\n';
    return 0;
}