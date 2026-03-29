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
const int P=998244353;
ll n,m,q,l[N],r[N],b[N],s[N],S[N],L,R;
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n>>m>>q;
    rp(i,m){
        cin>>l[i]>>r[i]>>b[i];
        b[i]%=P;
        s[i]=1ll*(r[i]-l[i]+1)%P*b[i]%P;
        S[i]=1ll*(r[i]-l[i]+1)%P*b[i]%P*b[i]%P;
    }
    rp(i,m){
        s[i]=(s[i-1]+s[i])%P;
        S[i]=(S[i-1]+S[i])%P;
    }
    rp(i,q){
        cin>>L>>R;
        int lt=lower_bound(r+1,r+1+m,L)-r;
        int rt=lower_bound(r+1,r+1+m,R)-r;
        ll sum=0,SUM=0;
        if(lt==rt){
            sum=1ll*(R-L+1)%P*b[lt]%P;
            SUM=1ll*(R-L+1)%P*b[lt]%P*b[lt]%P;
        }else{
            sum=(sum+1ll*(r[lt]-L+1)%P*b[lt]%P)%P;
            sum=(sum+1ll*(R-l[rt]+1)%P*b[rt]%P)%P;
            SUM=(SUM+1ll*(r[lt]-L+1)%P*b[lt]%P*b[lt]%P)%P;
            SUM=(SUM+1ll*(R-l[rt]+1)%P*b[rt]%P*b[rt]%P)%P;
            if(rt-lt>=2){
                sum=(sum+(s[rt-1]-s[lt]+P)%P)%P;
                SUM=(SUM+(S[rt-1]-S[lt]+P)%P)%P;
            }
        }
        cout<<(1ll*(R-L+1)%P*SUM%P-1ll*sum*sum%P+P)%P<<'\n';
    }
    return 0;
}