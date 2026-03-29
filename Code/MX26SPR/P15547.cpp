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
int n,m,x,y,a,b,vis[N],col[N],ist,isb;
vt<int>G[N];
inline void dfs1(int x,int p){
    vis[x]=1;
    for(auto i:G[x])if(i!=p){
        if(!vis[i])dfs1(i,x);
        else ist=0;
    }
}
inline void dfs2(int x,int p){
    col[x]=col[p]^1;
    for(auto i:G[x]){
        if(col[i]==-1){
            dfs2(i,x);
        } else if(col[i]==col[x]){
            isb=0;
        }
    }  
}
inline void solve(){
    cin>>n>>m>>x>>y;
    rp(i,n){
        G[i].clear();
        vis[i]=0,col[i]=-1;
    }
    rp(i,m){
        cin>>a>>b;
        G[a].pb(b);
        G[b].pb(a);
    }
    ist=1,isb=1;
    dfs1(x,0);
    if(vis[y]==0||ist==1){
        cout<<"No\n";
        return;
    }
    dfs2(x,0);
    if(col[x]!=col[y]||isb==0){
        cout<<"Yes\n";
    }else{
        cout<<"No\n";
    }
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int tid,t;
    cin>>tid>>t;
    rd(_,t)solve();
    return 0;
}