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
const int N=1e7+5;
const int P=998244353;
int n,m,k,d,x;
int A;
inline int fpow(int x,int p){
    int res=1,cur=x;
    rep(i,0,30){
        if(p>>i&1)res=1ll*res*cur%P;
        cur=1ll*cur*cur%P;
    }
    return res;
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
	cin>>n>>m>>k;
	cin>>A>>d>>x;
	for(int i=2;i<=k;i++){
		A=((A-d)^x);
	}
    if(m==0){
        cout<<1<<'\n';
        return 0;
    }
    int cur=0,f=1;
    int ans=0,res=1;
    per(i,1,k){
        int a=A-cur;
        res=1ll*res*a%P;
        if(n>=a-1){
            n-=a-1;
            cur+=a-1;
            ans=((1ll*ans*a%P)+1ll*f*(a-1)%P)%P;
        }else{
            cur+=n;
            ans=((1ll*ans*a%P)+1ll*f*n%P)%P;
            f=1ll*f*(a-n)%P;
            n=0;
        }
        A=(A^x)+d;
    }
    //n个黑点，m个白点
    ans=(ans+1ll*f*n%P*fpow((n+m)%P,P-2)%P)%P;
    ans=1ll*ans*fpow(res,P-2)%P;
    cout<<ans<<'\n';

    return 0;
}