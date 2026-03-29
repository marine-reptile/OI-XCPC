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
const int N=500005;
int n,a[N],f[N],g[N];
pii mx,mt;
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n;
    rp(i,n)cin>>a[i];
    rep(i,1,N-5)f[i]=-1e9;
    rep(i,1,n){
        int res=(mx.second==a[i]?mt.first:mx.first);
        g[a[i]]=max(g[a[i]],f[a[i]]+1);
        if(mx.second==a[i])mx.first=g[a[i]];
        else{
            if(g[a[i]]>mx.first){
                mt=mx;
                mx={g[a[i]],a[i]};
            }else if(g[a[i]]>mt.first&&a[i]!=mx.second){
                mt=max(mt,(pii){g[a[i]],a[i]});
            }
        }
        f[a[i]]=max(f[a[i]],res+1);
        // if(i==7){
        //     cout<<f[2]<<'\n';
        // }
    }
    cout<<mx.first<<'\n';
    return 0;
}