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
int n,a[N],b[N],st[N],top,hd;
ll t[N];
inline bool check(ll x){
    st[top=0]=0,hd=1;
    ll cur=0;
    rep(i,1,n){
        ll res=0;
        t[i]=b[i];
        while(hd<=top&&a[st[top]]<=a[i]){
            t[i]+=t[st[top]];
            top--;
        }
        top++,st[top]=i;
        while(cur<x){
            ll d=x-cur;
            //尝试在st[hd]上买东西
            while(hd<=top&&t[st[hd]]==0)hd++;
            if(hd>top)return 0;
            ll u=min(t[st[hd]],(d+a[st[hd]]-1)/a[st[hd]]);
            t[st[hd]]-=u;
            cur+=a[st[hd]]*u;
        }
        cur-=x;
    }
    return 1;
}
inline void solve(){
    cin>>n;
    rp(i,n)cin>>a[i];
    rp(i,n)cin>>b[i];
    ll l=1,r=1e12,mid,ans=0;
    while(l<=r){
        mid=(l+r)>>1;
        if(check(mid)){
            l=mid+1,ans=mid;
        }else{
            r=mid-1;
        }
    }
    cout<<ans<<'\n';
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    rd(_,t)solve();
    return 0;
}