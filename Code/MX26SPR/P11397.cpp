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
const int P=998244353;
ll n;
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n;
    ll ans=0;
    rep(x,1,60){
        ll l=(1ll<<(x-1))+1,r=(1ll<<x);
        //[l,r] [1,n]
        if(n>=l){
        //    cout<<x<<' '<<l<<' '<<min(n,r)<<endl;
            ans+=(min(n,r)-l+1)%P*x%P;
            ans%=P;
        }
    }
    cout<<(ans+n)%P<<'\n';
    return 0;
}