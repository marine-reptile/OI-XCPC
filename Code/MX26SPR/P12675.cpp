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
int n,a[N],b[N],pre[N],suf[N];
inline void solve(){
    cin>>n;
    rp(i,n)cin>>a[i];
    int ans=n+abs(a[1]-a[n]);
    rep(i,2,n-2){
        ans=min(ans,n+abs(a[1]-a[i])+abs(a[n]-a[i+1]));
    }
    int mn=1e9;
    rep(i,1,n){
        pre[i]=i+abs(a[1]-a[i]);
        suf[i]=n-i+1+abs(a[n]-a[i]);
        if(i!=n)ans=min(ans,mn+abs(a[n]-a[i])+n+2);
        if(i!=1)mn=min(mn,abs(a[1]-a[i]));
    }
    rp(i,n)b[a[i]]=i;
    rep(i,1,n-1){
        //i i+1
        int x=b[i],y=b[i+1];
        //x<=y
        if(x>y)swap(x,y);
        //[1,x-1][x,y][y+1,n]
        if(x<=2||y>=n-1)continue;
        ans=min(ans,pre[x-1]+suf[y+1]+1+y-x+1);
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