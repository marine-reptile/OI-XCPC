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
int n,m,k,l[N],r[N],w[N];
ll f[N];
vt<int>add[N],ers[N];
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n>>m>>k;
    rp(i,n){
        cin>>l[i]>>r[i]>>w[i];
        if(r[i]-l[i]+1>=k){
            add[l[i]+k-1].pb(w[i]);
            ers[r[i]+1].pb(w[i]);
        }
    }
    map<int,int>mp;
    rp(i,m){
        f[i]=max(f[i],f[i-1]);
        for(auto j:add[i])mp[j]++;
        for(auto j:ers[i]){
            mp[j]--;
            if(mp[j]==0)mp.erase(j);
        }
        if(i>=k&&mp.size()){
            f[i]=max(f[i],f[i-k]+mp.rbegin()->first);
        }
    }
    cout<<f[m]<<'\n';
    return 0;
}