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
int n,m,a,b,c;
int fa[N<<1],deg[N<<1];
inline int head(int x){
    return (x==fa[x])?x:fa[x]=head(fa[x]);
}
inline void merge(int x,int y){
    x=head(x),y=head(y);
    if(deg[x]<deg[y])swap(x,y);
    if(deg[x]==deg[y])deg[x]++;
    fa[y]=x;
}
inline void solve(){
    cin>>n>>m;
    rp(i,2*n)fa[i]=i,deg[i]=0;
    bool ft=0;
    rp(i,m){
        cin>>a>>b>>c;
        if(c==0&&a!=b)ft=1;
        if(c&1){
            merge(a,b+n);
            merge(a+n,b);
        }else{
            merge(a,b);
            merge(a+n,b+n);
        }
    }
    rp(i,n)if(head(i)==head(i+n)){
        cout<<"No\n";
        return;
    }
    int x=head(1),flag=0;
    rp(i,n)if(head(i)!=head(1))flag=1;
    if(!ft&&(flag||n==1))cout<<"Yes\n";
    else cout<<"No\n";
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    rd(_,t)solve();
    return 0;
}