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
int n,m,k;
vt<int>v;
inline void dfs(int i,int s){
    if(i==m){
        k--;
        for(auto j:v)cout<<j<<' ';
        cout<<n-s<<'\n';
        if(k==0)exit(0);
        return;
    }
    rep(j,1,n){
        v.pb(j);
        dfs(i+1,(s+j)%n);
        v.pop_back();
    }
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n>>m>>k;
    dfs(1,0);
    return 0;
}