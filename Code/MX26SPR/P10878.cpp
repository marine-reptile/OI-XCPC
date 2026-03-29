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
int n,m,a[N],c[N],q[N],hd,ed;

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    rp(i,n)cin>>a[i];
    q[hd=ed=1]=1;
    rep(i,2,m){
        while(hd<=ed&&a[q[ed]]<=a[i])ed--;
        q[++ed]=i;
    }
    //[i,i+m]
    rep(i,1,n-m){
        while(hd<=ed&&q[hd]<i)hd++;
        while(hd<=ed&&a[q[ed]]<=a[i+m])ed--;
        q[++ed]=i+m;
        c[i]=a[q[hd]];
    }
    int ans=c[1];
    rep(i,2,n-m)ans=min(ans,c[i]);
    cout<<ans<<'\n';
    return 0;
}