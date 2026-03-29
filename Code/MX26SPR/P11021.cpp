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
int n,m,p,q,to[N];
struct node{
    int t,x,id;
    bool operator <(const node b){
        return t<b.t;
    }
}a[N];
pii u[3];
inline void add(int val,int id){
    rep(i,0,2)if(val>u[i].first){
        per(j,i+1,2)u[j]=u[j-1];
        u[i]={val,id};
        return;
    }
}
inline int qry(int x){
    int res=0;
    rep(i,0,2)if(u[i].second!=x-1&&u[i].second!=x){
        res=max(res,u[i].first);
    }
    return res;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    rp(i,n){
        cin>>a[i].x>>a[i].t;
        a[i].id=i;
    }
    sort(a+1,a+1+n);
    rp(i,n)to[a[i].id]=i;
    rep(i,1,n-1){
        add(abs(a[i+1].x-a[i].x)/(a[i+1].t-a[i].t),i);
    }
    rp(i,m){
        cin>>p>>q;
        int res=qry(to[p]);
        if(to[p]!=1&&to[p]!=n){
            res=max(res,abs(a[to[p]+1].x-a[to[p]-1].x)/(a[to[p]+1].t-a[to[p]-1].t));
        }
        int t=lower_bound(a+1,a+1+n,(node){q,p,a[to[p]].x})-a;
        int prv=t-1,nxt=(t==to[p]?t+1:t);
        if(prv!=0){
            res=max(res,abs(a[to[p]].x-a[prv].x)/(q-a[prv].t));
        }
        if(nxt!=n+1){
            res=max(res,abs(a[nxt].x-a[to[p]].x)/(a[nxt].t-q));
        }
        cout<<res<<'\n';
    }
    return 0;
}