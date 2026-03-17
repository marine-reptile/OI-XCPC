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
const int N=105;
const int P=998244353;
int n,m,x,y,k[N],deg[N];
ll t;
struct matrix{
    int a[N][N];
    matrix operator *(const matrix b)const{
        matrix res;
        rep(i,1,n+2)rep(j,1,n+2){
            res.a[i][j]=0;
            rep(k,1,n+2){
                res.a[i][j]=(res.a[i][j]+1ll*a[i][k]*b.a[k][j]%P)%P;
            }
        }
        return res;
    }
}E,A;
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n>>m>>t;
    rp(i,n){
        cin>>k[i];
        E.a[i][i]=1;
        A.a[i][i]=k[i];
    }
    A.a[n+1][n+1]=1;
    E.a[n+1][n+1]=1;
    A.a[n+2][n+2]=1;
    E.a[n+2][n+2]=1;
    A.a[n+2][n+1]=1;
    rp(i,m){
        cin>>x>>y;
        deg[y]++;
        A.a[x][y]+=1;
    }
    rp(i,n)if(!deg[i]){
        A.a[n+1][i]+=1;
        A.a[n+2][i]+=1;
    }
    rep(i,0,60){
        if(t>>i&1)E=E*A;
        A=A*A;
    }
    rp(i,n)cout<<E.a[n+2][i]<<' ';
    cout<<'\n';
    return 0;
}