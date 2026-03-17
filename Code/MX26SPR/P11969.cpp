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
ll t,n,a[N],b[N];

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>t>>n;
    rp(i,n)cin>>a[i];
    rp(i,n)b[a[i]]=i;
    if(t&1){
        rep(i,1,n)if(a[i]!=i){
            //i b[i]
            swap(a[i],a[b[i]]);
            break;
        }
    }else{
        if(a[1]!=n){
            int t=a[1];
            swap(a[1],a[b[n]]);
            swap(b[t],b[n]);
            rep(i,2,n)if(a[i]!=i-1){
                swap(a[i],a[b[i-1]]);
                break;
            }
        }
    }
    rp(i,n)cout<<a[i]<<' ';
    cout<<'\n';
    return 0;
}