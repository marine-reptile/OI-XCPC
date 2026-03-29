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
int n,m,t[N],v[N<<1],k;
int l[N],r[N],opt[N<<1];
int sum[N<<1][3];
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    rp(i,n)cin>>t[i];
    sort(t+1,t+1+n);
    rp(i,n){
        v[++k]=t[i];
        v[++k]=t[i]+m;
    }
    sort(v+1,v+1+k);
    k=unique(v+1,v+1+k)-v-1;
    rp(i,n){
        l[i]=lower_bound(v+1,v+1+k,t[i])-v;
        r[i]=lower_bound(v+1,v+1+k,t[i]+m)-v-1;
        opt[l[i]]++,opt[r[i]+1]--;
    }
    int cnt=0;
    rp(i,k-1){
        int len=v[i+1]-v[i];
        cnt+=opt[i];
        rd(j,3)sum[i][j]=sum[i-1][j];
        if(cnt<=2)sum[i][cnt]+=len;
    }
    ll res=sum[k-1][1],ans=res;
    rp(i,n){
        ans=max(ans,res+m+(sum[r[i]][2]-sum[l[i]-1][2])-(sum[r[i]][1]-sum[l[i]-1][1]));
    }
    cout<<ans<<'\n';
    return 0;
}