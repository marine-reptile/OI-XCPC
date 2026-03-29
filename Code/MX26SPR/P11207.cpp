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
int n,ch,a[N],b[N],c[3];
int fs[7],ls,ans=2,ti;
string sa,sb;
pii pid[7]={{0,0},{1,1},{-1,-1},{2,-1},{-1,2},{-2,1},{1,-2}};
map<pii,int>mp;
//[0]
//[1,6]
inline void add(char x,int p){
    int id=(x=='P'?0:(x=='V'?1:2));
    c[id]++,ti++;
    pii cur={c[1]-c[0],c[2]-c[1]};
    if(mp.count(cur)){
        if(mp[cur]==0){
            //(x,x,x)
            if(p){
                if(ls==1e9)ls=ti;
            }else{
                if(ls==1e9)ans=min(ans,0);
            }
        }else{
            int res=mp[cur];
            if(p){
                fs[res]=ti;
            }else{
                if(fs[res]<=ls){
                    ans=min(ans,1);
                }
            }
        }

    }
}
inline void solve(){
    cin>>n;
    cin>>sa>>sb;
    rd(i,3)c[i]=0;
    ans=2,ls=1e9,ti=0;
    rep(i,1,6)fs[i]=-1;
    rp(i,n){
        add(sa[i-1],0);
        add(sb[i-1],1);
    }
    cout<<ans<<'\n';
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    rep(i,0,6)mp[pid[i]]=i;
    int t;
    cin>>t;
    rd(_,t)solve();
    return 0;
}