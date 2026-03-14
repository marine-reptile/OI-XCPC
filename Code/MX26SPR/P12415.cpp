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
const int N=85;
const int P=1000000007;
int n,m,f[N][N*N],C[N][N],pw[N*N][N];
inline void upd(int &x,int y){
    x+=y;
    if(x>=P)x-=P;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    rep(i,1,n)f[i][1]=m;
    rep(i,0,m){
        C[i][0]=1;
        rep(j,1,i)C[i][j]=(C[i-1][j-1]+C[i-1][j])%P;
    }
    rep(i,1,n*m){
        pw[i][0]=1;
        rep(j,1,m)pw[i][j]=1ll*pw[i][j-1]*i%P;
    }
    rep(i,1,n-1)rep(j,1,(i-1)*m+1){
        rep(k,0,m){
            upd(f[i+1][j+k],1ll*f[i][j]*C[m][k]%P*pw[j][k]%P);
        }
    }
    int ans=0;
    rep(i,1,(n-1)*m+1)upd(ans,f[n][i]);
    cout<<ans<<'\n';
    return 0;
}