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
int n,k,a[N];
inline bool check(int x){
    int cnt=0,cur=0;
    rep(i,1,n){
        cur|=a[i];
        if((cur&x)==x){
            cnt++,cur=0;
        }
    }
    if(cnt==0)return 0;
    return cnt>=n-k;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n>>k;
    rp(i,n)cin>>a[i];
    int res=0;
    per(i,0,30){
        if(check(res|(1<<i))){
            res|=(1<<i);
        }
    }
    cout<<res<<'\n';
    return 0;
}