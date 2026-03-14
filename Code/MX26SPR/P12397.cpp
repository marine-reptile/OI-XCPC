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
const int N=200;
int k;
ll f[N+5],m;
inline int s(ll x){
    int res=0;
    while(x){
        res+=x%10;
        x/=10;
    }
    return res;
}
inline void solve(){
    cin>>m;
    if(k==0){
        cout<<1<<'\n';
        return;
    }
    ll cnt=0;
    rep(i,1,200){
        ll x=m-f[i];
        if(s(x)==i)cnt++;
    }
    cout<<cnt<<'\n';
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int t;
    cin>>t>>k;
    rep(i,1,N){
        //f[k-1][i]
        ll cur=i;
        f[i]+=cur;
        rep(j,1,min(k-1,3)){
            cur=s(cur);
            f[i]+=cur;
        }
        if(k-1>3)f[i]+=1ll*(k-4)*cur;
    }
    rd(_,t)solve();
    return 0;
}