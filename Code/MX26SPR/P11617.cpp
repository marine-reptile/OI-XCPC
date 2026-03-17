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
const int N=5005;
const int P=998244353;
int n,a[N],b[N],sum,s[N];
inline int fpow(int x,int p){
    int res=1,cur=x;
    rep(i,0,30){
        if(p>>i&1)res=1ll*res*cur%P;
        cur=1ll*cur*cur%P;
    }
    return res;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n;
    rep(i,0,n-1)cin>>a[i];
    rep(i,0,n)cin>>b[i];
    s[0]=a[0];
    rep(i,0,n-1)s[i]=(s[i-1]+a[i])%P;
    rep(i,0,n)sum=(sum+b[i])%P;
    int ans=0;
    rep(i,0,n-1){
        ans=(ans+1ll*b[i]*s[n-i-1]%P)%P;
    }
    cout<<1ll*ans*fpow(sum,P-2)%P<<'\n';


    return 0;
}