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
const int N=500005;
const int P=998244353;
int n,m,v[N],a[N],x,p[N],ans[N];
vt<int>G[N];
ll k;
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n>>k>>m;
    rp(i,m)cin>>v[i];
    rp(i,n){
        cin>>a[i];
        rp(j,a[i]){
            cin>>x;
            G[i].pb(x);
        }
    }
    queue<int>q;
    rp(i,m){
        p[v[i]]=1;
        q.push(v[i]);
    }
    while(q.size()){
        int x=q.front();
        q.pop();
        for(auto i:G[x])if(!p[i]){
            p[i]=p[x]+1;
            q.push(i);
        }
    }
    rp(i,n)if(p[i]){
        if(k>=p[i]){
            ans[i]=(ans[i]+(k-p[i]+1)%P*a[i]%P)%P;
        }
        if(k>p[i]){
            for(auto j:G[i]){
                ans[j]=(ans[j]+(k-p[i])%P)%P;
            }
        }
    }
    rp(i,m)ans[v[i]]=(ans[v[i]]+k%P)%P;
    rp(i,n)cout<<ans[i]<<' ';
    cout<<'\n';
    return 0;
}