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
int n,m,cnt[N],a;

inline void solve(){
    cin>>n>>m;
    rep(i,1,n)cnt[i]=0;
    rep(i,1,n*m){
        cin>>a;
        cnt[a]++;
    }
    bool flag=1;
    rep(i,1,n)if(cnt[i]!=m)flag=0;
    if(flag)cout<<"No\n";
    else cout<<"Yes\n";

}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    rd(_,t)solve();
    return 0;
}