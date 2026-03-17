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
const int N=25;
int times,player_num;
int player_type[N];
int is_alive[N];
int new_alive[N];
int poi_used[N];
int mad_used[N];
int new_poi_used[N];
int new_mad_used[N];
int event_num;
int event_type;
int event_player;
int event_target;
int action_used[N];
int action_valid[4][5]={{0,1,0,0,0},{0,0,0,0,1},{0,0,0,0,1},{0,0,0,1,0}};

inline bool a_night(){
    rp(i,player_num){
        new_alive[i]=is_alive[i];
        new_poi_used[i]=poi_used[i];
        new_mad_used[i]=mad_used[i];
        action_used[i]=0;
    }
    int night_valid=1;
    cin>>event_num;
    rp(_,event_num){
        cin>>event_type>>event_player>>event_target;
        if(event_player<1||event_player>player_num)night_valid=-1;
        if(event_target<1||event_target>player_num)night_valid=-2;
        if(!is_alive[event_player]||!is_alive[event_target])night_valid=-3;
        if(event_type!=2&&!new_alive[event_target])night_valid=-4;
        if(event_type<=1&&!new_alive[event_player])night_valid=-5;
        if(action_used[event_player])night_valid=-6;
        if(!action_valid[event_type][player_type[event_player]])night_valid=-7;
        action_used[event_player]=1;
        if(event_type==0){
            if(event_player==event_target)night_valid=2;
            new_alive[event_target]=0;
        }else if(event_type==1){
            if(new_poi_used[event_player])night_valid=4;
            new_poi_used[event_player]=1;
            if(event_player==event_target)night_valid=6;
            new_alive[event_target]=0;
        }else if(event_type==2){
            if(new_mad_used[event_player])night_valid=8;
            new_mad_used[event_player]=1;
            if(new_alive[event_target])night_valid=9;
            if(!is_alive[event_target])night_valid=10;
            new_alive[event_target]=1;
            if(event_player!=event_target&&!new_alive[event_player])night_valid=11;
            if(player_type[event_target]==3){
                action_used[event_target]=0;
            }
        }else{
            if(new_alive[event_player])night_valid=12;
            if(event_player==event_target)night_valid=13;
            new_alive[event_target]=0;
        }
   //     cout<<"++ "<<night_valid<<endl;
    }
    rep(i,1,player_num)if(player_type[i]==3){
        if(is_alive[i]&&!new_alive[i]){
            if(!action_used[i])night_valid=0;
        }
    }
    return (night_valid==1);
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>times>>player_num;
    rp(i,player_num)cin>>player_type[i];
    rp(i,player_num){
        is_alive[i]=1;
    }
    rp(_,times){
        if(a_night()){
            vector<int>dead_players;
            rp(i,player_num){
                if(is_alive[i]&&!new_alive[i]){
                    dead_players.pb(i);
                }
                is_alive[i]=new_alive[i];
                poi_used[i]=new_poi_used[i];
                mad_used[i]=new_mad_used[i];
                sort(dead_players.begin(),dead_players.end());
            }
            if(dead_players.empty()){
                cout<<"Safe\n";
            }else{
                cout<<dead_players.size()<<' ';
                for(auto i:dead_players)cout<<i<<' ';
                cout<<'\n';
            }

        }else{
            cout<<"Wrong\n";
        }
    }
    return 0;
}