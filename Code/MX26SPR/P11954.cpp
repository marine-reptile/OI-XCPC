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
int n,m,a,b,vis[N],sz[N],D=-1,del[N];
vt<int>G[N],T[N];
inline void dfs(int x,int p){
    vis[x]=1,sz[x]=1;
    for(auto i:G[x])if(!vis[i]){
        dfs(i,x);
        sz[x]+=sz[i];
        T[x].pb(i);

    }
    for(auto i:T[x]){
        if(T[x].size()+(p!=0)>=2&&sz[i]>=2){
            D=i;
        }
    }
    // cout<<x<<": ";
    // for(auto i:T[x])cout<<i<<' ';
    // cout<<endl;
}
inline void dfs2(int x,int p){
    del[x]=del[p];
    if(x==D)del[x]=1;
    for(auto i:T[x])dfs2(i,x);
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    rp(i,m){
        cin>>a>>b;
        G[a].pb(b);
        G[b].pb(a);
    }
    int d=0,rt=1;
    rp(i,n)if(G[i].size()>d)d=G[i].size(),rt=i;
    // cout<<rt<<endl;
    dfs(rt,0);
    // cout<<D<<endl;
    dfs2(rt,0);
    vt<pii>vans;
    // rp(i,n)cout<<del[i]<<' ';
    // cout<<endl;
    rp(i,n)if(del[i]){
        for(auto j:G[i])if(!del[j]){
        //    if(i>j)swap(i,j);
            vans.pb({i,j});
        }
    }
 //   return 0;
    if(D==-1||n<=3){
        cout<<-1<<'\n';
        return 0;
    }
    cout<<vans.size()<<'\n';
    for(auto i:vans)cout<<i.first<<' '<<i.second<<'\n';
    return 0;
}