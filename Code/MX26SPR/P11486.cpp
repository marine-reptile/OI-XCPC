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
const int N=300005;
int n,m,a,b,fa[N],vis[N];
vt<int>v;
inline int head(int x){
    return fa[x]==x?x:fa[x]=head(fa[x]);
}
vt<int>G[N];
vt<pii>vans;
inline void dfs(int x){
    vis[x]=1;
    for(auto i:G[x])if(!vis[i]){
        dfs(i);
    }
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    rp(i,n)fa[i]=i;
    rp(i,m){
        cin>>a>>b;
        if(head(a)==head(b)){
            cout<<"No\n";
            return 0;
        }
        fa[head(a)]=head(b);
        if(i!=m){
            G[a].pb(b);
            G[b].pb(a);
            vans.pb({a,b});
        }
    }
    dfs(a);
    dfs(b);
    rp(i,n)if(!vis[i]){
        dfs(i);
        v.pb(i);
    }
    int lst=a;
    for(auto i:v){
        vans.pb({lst,i});
        lst=i;
    }
    vans.pb({lst,b});
    cout<<"Yes\n";
    for(auto i:vans){
        cout<<i.first<<' '<<i.second<<'\n';
    }


    return 0;
}