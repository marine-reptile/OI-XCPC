namespace mcmf{
    const int N=1005;
    const int M=15005;
    const int inf=1000000000;
    struct edge{
        int fr,to,f,c,ori;
        edge(){}
        edge(int a,int b,int _c,int _d){
            fr=a,to=b,f=_c,c=_d,ori=f;
        }
    }e[M<<1];
    int hd[N],nxt[M<<1],cnt=1,cs[N];
    int vert[N],s,t,siz,vis[N],inq[N],cur[N];
    int dist[N];
    inline void add(int a,int b,int c,int d){
        cnt++;
        nxt[cnt]=hd[a];
        e[cnt]=edge(a,b,c,d);
        hd[a]=cnt;
    }
    inline void addedge(int a,int b,int c,int d){
        add(a,b,c,d);
        add(b,a,0,-d);
    }
    inline void addvert(int a){
        vert[++siz]=a;
    }
    inline bool spfa(){
        for(int i=1;i<=siz;i++){
            dist[vert[i]]=inf;
            inq[vert[i]]=0;
            cs[vert[i]]=0;
            cur[vert[i]]=hd[vert[i]];
        }
        queue<int>q;
        dist[s]=0,inq[s]=1;
        q.push(s);
        while(q.size()){
            int x=q.front();
            q.pop();inq[x]=0;
            for(int i=hd[x];i;i=nxt[i]){
                if(e[i].f&&dist[e[i].to]>dist[x]+e[i].c){
                    dist[e[i].to]=dist[x]+e[i].c;
                    if(!inq[e[i].to]){
                        inq[e[i].to]=1;
                        cs[e[i].to]++;
                        q.push(e[i].to);
                    }
                }
            }
        }
        return dist[t]!=inf;
    }
    int cost=0;
    inline int dfs(int x,int f){
        if(x==t||!f)return f;
        int ans=0;
        inq[x]=1;
        for(int i=cur[x];i;i=nxt[i]){
            cur[x]=i;
            if(e[i].f&&dist[e[i].to]==dist[x]+e[i].c&&!inq[e[i].to]){
                int res=dfs(e[i].to,min(e[i].f,f));
                cost+=res*e[i].c,e[i].f-=res;
                e[i^1].f+=res,f-=res,ans+=res;
            }if(!f)break;
        }inq[x]=0;
        return ans;
    } 
    inline int MCMF(){
        int flow=0;
        while(spfa()){
            flow+=dfs(s,inf);
        }return flow;
    }
}