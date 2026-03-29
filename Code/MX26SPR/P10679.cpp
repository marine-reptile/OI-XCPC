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
const int N=1005;
int n,x[N],m,L[N][N],R[N][N];
int opt[N*N];
double l[N][N],r[N][N];
double v[N*N];
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n;
    rp(i,n)cin>>x[i];
    rp(i,n)rep(k,1,x[i]){
        l[i][k]=1.0*x[i]/k;
        r[i][k]=(x[i]+1.0)/k;
        v[++m]=l[i][k];
        v[++m]=r[i][k];
    }
    sort(v+1,v+1+m);
    rep(i,1,n)rep(k,1,x[i]){
        L[i][k]=lower_bound(v+1,v+1+m,l[i][k])-v;
        R[i][k]=lower_bound(v+1,v+1+m,r[i][k])-v;
        opt[L[i][k]]++,opt[R[i][k]]--;
    }
    int sum=0;
    double ans=1;
    rep(i,1,m-1){
        sum+=opt[i];
        if(sum==n)ans=max(ans,v[i+1]);
    }
    cout<<fixed<<setprecision(7)<<ans<<'\n';
    return 0;
}