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

namespace FastIO {
	const int SZ=(1<<21)+1;
	struct I {
		char ibuf[SZ],*iS,*iT,c;int f,_eof;FILE*fi;
		I(FILE*f):fi(f){}
		inline char Gc(){return iS==iT?(iT=(iS=ibuf)+fread(ibuf,1,SZ,fi),(iS==iT?EOF:*iS++)):*iS++;}
		inline ll operator()(){ll x;operator()(x);return x;}
		inline I&operator()(char&x){x=Gc();return*this;}
		inline I&operator()(char*s){for(c=Gc();c<32||c>126||c==' ';)c=Gc();for(;c>31&&c<127&&c!=' '&&c!='\n'&&c!='\r';++s,c=Gc())*s=c;*s=0;return*this;}
		template<class T>inline I&operator()(T&x){_eof=0;for(f=1,c=Gc();(c<'0'||c>'9')&&!_eof;c=Gc()){if(c=='-')f=-1;_eof|=c==EOF;}for(x=0;c<='9'&&c>='0'&&!_eof;c=Gc())x=x*10+(c&15),_eof|=c==EOF;x*=f;return*this;}
		template<class T>I&operator()(T*x,const int&n,const int&st=1){rep(i,st,n){operator()(x[i]);}return*this;}
	} in(stdin);
	struct O {
		char obuf[SZ],*oS=obuf,*oT=oS+SZ-1,qu[55];int f,qr;FILE*fi;
		O(FILE*f):fi(f){}
		~O(){Flush();}
		inline void Flush(){fwrite(obuf,1,oS-obuf,fi),oS=obuf;}
		inline O&operator()(char x){*oS++=x;if(oS==oT)Flush();return*this;}
		inline O&operator()(char*s){int len=strlen(s);for(f=0;f<len;++f)operator()(s[f]);return*this;}
		inline O&operator()(const char*s){return operator()((char*)s);}
		template<class T>inline O&operator()(T x){if(!x)operator()('0');if(x<0)operator()('-'),x=-x;while(x)qu[++qr]=x%10+'0',x/=10;while(qr)operator()(qu[qr--]);return*this;}
		template<class T>O&operator()(T*x,const int&n,const char&ed=' ',const int&st=1){rep(i,st,n)operator()(x[i])(ed);return*this;}
	} out(stdout);
}
using namespace FastIO;

int n,m,q,to[21],bk[21],u[21],op,x,y;
vt<int>v[21];
signed main(){
    n=in(),m=in(),q=in();
    rp(i,m){
        rp(j,n){
            x=in();
            v[i].pb(x);
        }
    }
    rp(i,m)to[i]=bk[i]=i;
    rp(i,q){
        op=in(),x=in(),y=in();
        if(op==1){
            if(!u[to[x]])sort(v[to[x]].begin(),v[to[x]].end());
            if(!u[to[y]])sort(v[to[y]].begin(),v[to[y]].end());
            u[to[x]]=u[to[y]]=1;
            if(v[to[x]].back()<=v[to[y]][0]){

            }else if(v[to[y]].back()<=v[to[x]][0]){
                swap(bk[to[x]],bk[to[y]]);
                swap(to[x],to[y]);
            }else{
                vt<int>vr;
                for(int i=0,j=0;i<n||j<n;){
                    if(i==n||(j<n&&v[to[y]][j]<v[to[x]][i])){
                        vr.pb(v[to[y]][j]);
                        j++;
                    }else{
                        vr.pb(v[to[x]][i]);
                        i++;
                    }
                }
                rd(i,n){
                    v[to[x]][i]=vr[i];
                    v[to[y]][i]=vr[i+n];
                }
            }
        }else{
            out(v[to[x]][y-1])('\n');
        }
    }
    return 0;
}