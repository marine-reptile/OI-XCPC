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
const int N=5000005;
ll n,a[N];
int d[N],m;
inline void solve(){
    cin>>n;
    rp(i,n)cin>>a[i];
    d[m=1]=1;
    rep(i,2,n)if(a[i]<a[i-1])d[++m]=i;
    d[m+1]=n+1;
    ll ans=0;
    rep(i,1,m-1){
        //[i,i+1]
        int r=d[i+1]-1;
        rep(l,d[i],d[i+1]-1){
            while(r<d[i+2]-1&&a[r+1]<a[l])r++;
            ans+=r-d[i+1]+1;
        }
    }
    cout<<ans<<'\n';
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    rd(_,t)solve();
    return 0;
}