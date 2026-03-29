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
int n,m,x[N],p[N];
string s;
char c[N];
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>n>>m>>s;
    s='_'+s;
    rp(i,m){
        cin>>c[i]>>x[i];
        if(i==1&&n==m){
            s[x[i]]='B';
        }else{
            if(c[i]=='R')p[x[i]]=1;
            else p[x[i]]=2;
        }
    }
    rep(i,1,n)if(s[i-1]!='_'&&s[i]=='_'){
        if(p[i]==1){
            s[i]=(s[i-1]=='B'?'W':'B');
        }else{
            s[i]=(s[i-1]=='B'?'B':'W');
        }
    }
    per(i,1,n-1)if(s[i]=='_'){
        if(p[i]==1){
            s[i]=(s[i+1]=='B'?'W':'B');
        }else{
            s[i]=(s[i+1]=='B'?'B':'W');
        }
    }
    int ans=1;
    rep(i,1,n-1)if(s[i]!=s[i+1])ans++;
    cout<<ans<<'\n';


    return 0;
}