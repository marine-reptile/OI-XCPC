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
const int N=1000005;
ll n,t[N],w[N];
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n;
    rp(i,n)cin>>t[i];
    rp(i,n)cin>>w[i];
    per(i,1,n-1){
        t[i]=min(t[i],t[i+1]);
        w[i]+=w[i+1];
    }
    per(i,1,n)w[i]=max(w[i],w[i+1]);
    ll ans=0;
    rp(i,n)if(t[i]>t[i-1]){
        ans+=(t[i]-t[i-1])*w[i];
    }
    cout<<ans<<'\n';
    return 0;
}