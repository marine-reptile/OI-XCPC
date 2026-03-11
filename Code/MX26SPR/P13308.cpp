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
const int M=300005;
const int N=10000007;
ll n,m,op,x;
struct hash_table{
    int hd[N],nxt[N],cnt;
    ll key[N],val[N];
    inline void add(ll x,ll v){
        int u=x%N;
        for(int i=hd[u];i;i=nxt[i])if(key[i]==x){
            val[i]+=v;
            return;
        }
        cnt++,nxt[cnt]=hd[u],hd[u]=cnt;
        key[cnt]=x,val[cnt]=v;
    }
    inline ll qry(ll x){
        int u=x%N;
        for(int i=hd[u];i;i=nxt[i])if(key[i]==x){
            return val[i];
        }
        return -1;
    }
}isdel,val;
inline ll init_val(ll x){
    int d=__lg(x)+1;
    //n-d+1
    return (1ll<<(n-d+1))-1;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    ll ans=0;
    rp(i,m){
        cin>>op>>x;
        if(op==1){
            if(x==1||isdel.qry(x)!=-1)continue;
            isdel.add(x,1);
            if(val.qry(x)==-1)val.add(x,init_val(x));
            ll cur=val.qry(x);
            do{
                x>>=1;
                if(val.qry(x)==-1)val.add(x,init_val(x));
                val.add(x,-cur);
            }while(x!=1&&isdel.qry(x)==-1);
        }else{
            while(x!=1&&isdel.qry(x)==-1)x>>=1;
            if(val.qry(x)==-1){
                ans^=init_val(x);
            }else{
                ans^=val.qry(x);
            }
        }
    }
    cout<<ans<<'\n';
    return 0;
}
