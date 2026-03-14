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
const int N=5005;
const int P=998244353;
int n,a[N];

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n;
    rp(i,n)cin>>a[i];
    int ans=0;
    rp(l,n){
        int sum=0,prd=1;
        rep(r,l,n){
            sum=(sum+(r-l+1)+a[r])%P;
            prd=1ll*prd*(a[r]-(r-l))%P;
            if(a[r]<=(r-l))break;
            ans=(ans+1ll*sum*prd%P)%P;
        }
    }
    if(ans&1){
        ans=(ans+P)/2;
    }else{
        ans/=2;
    }
    cout<<ans<<'\n';

    return 0;
}