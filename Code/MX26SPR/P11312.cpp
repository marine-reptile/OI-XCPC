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
const int N=10005;
int n,k,l[N],r[N],t[N],L[N],R[N],v[1000005],m;
inline void getans(int x){
    cout<<"Yes\n";
    rp(i,n){
        cout<<(r[i]/x*x)<<' ';
    }
    cout<<'\n';
}
inline void solve(){
    cin>>n>>k;
    rp(i,n)cin>>l[i]>>r[i];
    rp(i,n)t[i]=i;
    sort(t+1,t+1+n,[](int x,int y){
        return r[x]-l[x]+1<r[y]-l[y]+1;
    });
    rp(i,n){
        L[i]=l[t[i]];
        R[i]=r[t[i]];
    }
    if(R[1]-L[1]+1>=k){
        getans(k);
        return;
    }
    m=0;
    rep(x,L[1],R[1]){
        for(int i=1;i*i<=x;i++)if(x%i==0){
            if(i>=k)v[++m]=i;
            if(i*i!=x&&x/i>=k)v[++m]=x/i;
        }
    }
    sort(v+1,v+1+m);
    rep(i,1,m){
        bool flag=1;
        rep(j,2,n)if((L[j]-1)/v[i]==R[j]/v[i]){
            flag=0;
            break;
        }
        if(flag){
            getans(v[i]);
            return;
        }
    }
    cout<<"No\n";
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int t;
    cin>>t;
    rd(_,t)solve();
    return 0;
}