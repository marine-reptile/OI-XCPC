
namespace maxflow{
    const int N=1000005;
    const int Inf=1000000000;
    int pnts[N],vis[N],cur[N],dep[N],inq[N];
    int hd[N],nxt[N<<1],q[N],fr,ed;
    int siz,cnt=1,sink,termin;
    struct edge{
        int fr,to,f;
        edge(){}
        edge(int _fr,int _to,int _f){
            fr=_fr,to=_to,f=_f;
        }
    }e[N<<1];
    inline void addvert(int x){
        pnts[++siz]=x;
    }
    inline void add(int x,int y,int z){
        nxt[++cnt]=hd[x];
        e[cnt]=edge(x,y,z);
        hd[x]=cnt;
    }
    inline void addedge(int x,int y,int z){
        add(x,y,z);
        add(y,x,0);
    }
    inline int bfsflow(){
        for(int i=1;i<=siz;i++){
            vis[pnts[i]]=0,inq[pnts[i]]=0;
            cur[pnts[i]]=hd[pnts[i]];
            dep[pnts[i]]=0;
        }
        inq[sink]=1,dep[sink]=1;
        q[fr=ed=1]=sink;
        while(fr<=ed){
            int x=q[fr++];
            vis[x]=1;
            for(int i=hd[x];i;i=nxt[i]){
                if(e[i].f&&!dep[e[i].to]){
                    dep[e[i].to]=dep[x]+1;
                    if(!inq[e[i].to]){
                    q[++ed]=e[i].to;
                    }
                }
            }
        }
        return dep[termin];
    }
    inline int dfsflow(int x,int f){
        if(x==termin||!f)return f;
        int resul=0;
        for(int i=cur[x];i;i=nxt[i]){
            cur[x]=i;
            if(e[i].f&&dep[e[i].to]==dep[x]+1){
                int flow=dfsflow(e[i].to,min(f,e[i].f));
                e[i].f-=flow,e[i^1].f+=flow;
                f-=flow,resul+=flow;
            }
            if(!f)break;
        }return resul;
    }
    int totflow=0;
    inline int Maxflow(){
        while(bfsflow()){
            totflow+=dfsflow(sink,Inf);
        }
        return totflow;
    }
    inline void flush(){
        for(int i=1;i<=siz;i++){
            hd[pnts[i]]=0;
        }
        cnt=1,siz=0;
        totflow=0;
    }
    inline void makepnt(int l,int r){
        for(int i=l;i<=r;i++)addvert(i);
    }
    inline void makest(int _s,int _t){
        sink=_s,termin=_t;
    }
}