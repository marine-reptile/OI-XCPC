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
const int N=105;
int n,a[N],m,x;
vt<int>v,vtot;
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n>>m;
    rp(i,n){
        cin>>a[i];
        v.clear();
        rp(j,a[i]){
            cin>>x;
            v.pb(x);
        }
        sort(v.begin(),v.end());
        v.erase(unique(v.begin(),v.end()),v.end());
        a[i]=v.size();
        for(int i=0;i<(int)v.size()-1;i++){
            vtot.pb(v[i+1]-v[i]-1);
        }
    }
    sort(vtot.begin(),vtot.end());
    m--;
    while(vtot.size()&&m!=0)vtot.pop_back(),m--;
    ll sum=0;
    for(auto i:vtot)sum+=i;
    rp(i,n)sum+=a[i];
    cout<<sum<<'\n';
    return 0;
}