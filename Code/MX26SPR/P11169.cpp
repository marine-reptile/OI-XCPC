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
ll n;
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n;
    if(n<=1){
        cout<<0<<' '<<0<<'\n';
        return 0;
    }
    ll w=1,ans=0;
    rep(i,1,100){
        ll pri=(i==1?2:2*i-1);
        ll t=(n/pri);
        w=w*pri/__gcd(w,pri);
        if(t/w==0)break;
        ans+=t/w;
    }
    cout<<(n+1)/2<<' '<<ans<<'\n';
    return 0;
}
//i=6