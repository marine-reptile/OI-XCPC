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
const int N=1000005;
int n,L,m,a[N];
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n>>L>>m;
    rp(i,n)cin>>a[i];
    int mx=0,cnt=0;
    ll sum=0;
    rp(i,n){
        mx=max(a[i],mx);
        if(a[i]<m)cnt++,sum+=m-a[i];
    }
    if(mx>=m){
        cout<<cnt+sum<<'\n';
    }else{
        cout<<m-mx-1+cnt+sum<<'\n';
    }
    return 0;
}