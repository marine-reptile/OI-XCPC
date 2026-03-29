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
ull n,m,a,b,x;
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n>>m>>a>>b>>x;
    if(x==1){
        ull ans=n*m-((n+1)/2)*((m+1)/2);
        if((n&1)&&(m&1)&&(a&1)&&(b&1)){
            cout<<ans+1<<'\n';
        }else{
            cout<<ans<<'\n';
        }
    }else{
        ull ans=n*m-((n+a%2)/2)*((m+b%2)/2);
        cout<<ans<<'\n';
    }
    return 0;
}