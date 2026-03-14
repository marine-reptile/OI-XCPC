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
ll n,m;
inline void solve(){
    cin>>n>>m;
    ll l=1,r=min(n-1,2000000000ll),mid,k=r+1;
    while(l<=r){
        mid=(l+r)>>1;
        if(m<mid*(mid-1)/2+n-mid){
            r=mid-1,k=mid;
        }else{
            l=mid+1;
        }
    }
    __int128 res=(__int128(k)*(k-1)*(2*k-1)/6-k*(k-1)/2)/2+k-1;
    res+=__int128(2*m-(n-k)+1)*(n-k)/2;
    cout<<(ll)(res%998244353)<<'\n';
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    rd(_,t)solve();
    return 0;
}