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
int n,a[N];
ll L[N],R[N],lans[N],rans[N];
inline void solve(){
    cin>>n;
    rp(i,n)cin>>a[i];
    L[0]=lans[0]=0;
    ll lst=0;
    rp(i,n){
        L[i]=lst,lans[i]=lans[i-1];
        if(L[i]>=a[i]){
            lst=a[i];
        }else{
            ll len=a[i]-L[i];
            lst=len,lans[i]+=len;
        }
    }
    R[n+1]=rans[n+1]=0;
    lst=0;
    per(i,1,n){
        R[i]=lst,rans[i]=rans[i+1];
        if(R[i]>=a[i]){
            lst=a[i];
        }else{
            ll len=a[i]-R[i];
            lst=len,rans[i]+=len;
        }
    }
    ll ans=min(lans[n],rans[1]);
    rep(i,1,n){
        ll res=lans[i-1]+rans[i+1];
        //L[i] R[i]
        if(L[i]+R[i]<a[i])res+=(a[i]-L[i]-R[i]);
        ans=min(ans,res);
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