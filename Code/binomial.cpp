namespace Comb{
    const int N=1000005;
    inline int fpow(int a,int p){
        int res=1,cur=a;
        for(int i=0;i<=30;i++){
            if(p>>i&1)res=1ll*res*cur%P;
            cur=1ll*cur*cur%P;
        }
        return res;
    }
    int fac[N],ifac[N];
    inline void init(int n){
        fac[0]=ifac[0]=1;
        for(int i=1;i<=n;i++){
            fac[i]=1ll*fac[i-1]*i%P;
            ifac[i]=1ll*ifac[i-1]*fac[i]%P;
        }
        ifac[n]=fpow(ifac[n],P-2);
        for(int i=n;i>=1;i--){
            int tmp=ifac[i];
            ifac[i]=1ll*ifac[i]*ifac[i-1]%P;
            ifac[i-1]=1ll*tmp*fac[i]%P;
        }
    }
    inline int C(int n,int m){
        if(n<0||m<0||n<m)return 0;
        return 1ll*fac[n]*ifac[m]%P*ifac[n-m]%P;
    }
}