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
const int N=2000005;
int m,q,n,x,to[N],st[N],top,cnt;
vt<pii>v;//x>a?p:q 15+4 20
string s;
inline void solve(int l,int r,int L,int R){
    if(L>R)return;
    //[l,r] x<..?..:.. a
    bool fl=0;
    if(s[l]=='x'){
        //x<....?...:..
        //x>....?...:..
        int res=0;
        rep(i,l+2,r){
            if(s[i]=='?'){
                if(s[l+1]=='<'){
                    //x<res?...:...
                    solve(i+1,to[i]-1,L,res-1);
                    solve(to[i]+1,r,res,R);
                }else{
                    //x>res?...:...
                    solve(i+1,to[i]-1,res+1,R);
                    solve(to[i]+1,r,L,res);
                }
                return;
            }
            res=res*10+s[i]-'0';
        }
    }else{
        int res=0;
        rep(i,l,r)res=res*10+s[i]-'0';
        //x\in[L,R] =res
        v.pb({R,res});
    }
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>m>>q>>s;
    n=s.size(),s='$'+s;
    rep(i,1,n){
        if(s[i]=='?'){
            st[++top]=i;
        }else if(s[i]==':'){
            to[st[top]]=i;
            top--;
        }
    }
    solve(1,n,0,1e9);
    sort(v.begin(),v.end());
    rp(i,q){
        cin>>x;
        auto k=lower_bound(v.begin(),v.end(),(pii){x,0});
        cout<<k->second<<'\n';
    }


    return 0;
}