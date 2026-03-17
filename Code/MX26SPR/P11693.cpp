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
int n,m,q,x,y,dp[5][N][2];
vt<int>G[N];
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n>>m>>q;
    rp(i,m){
        cin>>x>>y;
        G[x].pb(y);
        G[y].pb(x);
    }
    rep(i,1,n)rd(p,2)dp[0][i][p]=0;
    rep(i,1,4)rep(x,1,n){
        //0是第一个人，希望最大化
        dp[i][x][0]=0;
        dp[i][x][1]=n+1;
        for(auto y:G[x]){
            //dp[i-1][y][p^1]
            rd(p,2){
                int res=max(dp[i-1][y][p^1],y);
                if(p==0){
                    dp[i][x][p]=max(dp[i][x][p],res);
                }else{
                    dp[i][x][p]=min(dp[i][x][p],res);
                }
            }
        }
    }
    rp(i,q){
        cin>>x>>y;
        y=min(y,4);
        cout<<dp[y][x][0]<<'\n';
    }
    return 0;
}
