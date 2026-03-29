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
const int N=200005;
int n,m,a,b,vis[N],inq[N],gt=-1,ans[N];
vt<int>G[N];
inline void dfs(int x,int t,int p){
    vis[x]=1,ans[x]=t;
    bool flag=0;
    for(auto i:G[x])if(vis[i]&&i!=p){
        if(gt==-1){
            gt=x;
            flag=1;
        }
    }
    if(flag)ans[x]=flag;
    for(auto i:G[x])if(!vis[i]){
        dfs(i,flag|t,x);
    }
}
inline void solve(){
    cin>>n>>m;
    rp(i,n){
        G[i].clear();
        vis[i]=0;
    }
    rp(i,m){
        cin>>a>>b;
        G[a].pb(b);
        G[b].pb(a);
    }
    gt=-1;
    rp(i,n)if(!vis[i]){
        if(i==1)dfs(i,0,0);
        else{
            cout<<"-1\n";
            return;
        }
    }
    if(gt==-1){
        cout<<"-1\n";
    }else{
        rp(i,n)cout<<"BW"[ans[i]];
        cout<<'\n';
    }
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    rd(_,t)solve();
    return 0;
}