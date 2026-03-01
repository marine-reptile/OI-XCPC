inline int fpow(int a,int p){
    int res=1,cur=a;
    for(int i=0;i<=30;i++){
        if(p>>i&1)res=1ll*res*cur%P;
        cur=1ll*cur*cur%P;
    }
    return res;
}