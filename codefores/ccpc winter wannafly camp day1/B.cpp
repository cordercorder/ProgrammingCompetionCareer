#include<bits/stdc++.h>

using namespace std;

#define FC ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define FIN freopen("in.txt","r",stdin)
#define FOUT freopen("out.txt","w",stdout)
#define deb(x) cerr<<"DEBUG------"<<'\n';cerr<<#x<<"------>";err(x)

template<typename T>
void err(T a){
    for(auto i:a){
        cerr<<i<<" ";
    }
    cerr<<'\n'<<"END OF DEBUG"<<'\n'<<'\n';
}
void err(int a){
    cerr<<a<<'\n';
    cerr<<"END OF DEBUG"<<'\n'<<'\n';
}

const long double PI=acos(-1.0);  
const long double eps=1e-6;
const long long maxw=(long long)1e17+(long long)10;

using ll=long long;
using ull=unsigned long long;
using pii=pair<int,int>; 

/*head------[@cordercorder]*/


const int maxn=15;

int n,m,C;
int T[maxn][maxn];
int dp[maxn][maxn][13][2001];
int dx[5]={1,0,-1,0,0};
int dy[5]={0,1,0,-1,0};;

struct node{
    int x;
    int y;
    int ti;
    int sum;
    node():ti(0),sum(0){}
    node(int _x,int _y):x(_x),y(_y),ti(0),sum(0){}
};
node st,ed;

void solve(){
    queue<node> q;
    q.push(st);
    node now,tmp;
    int mod;
    while(!q.empty()){
        now=q.front();
//        deb(now.x);
//        deb(now.y);
        q.pop();
        for(int i=0;i<5;i++){
            tmp.x=dx[i]+now.x;
            tmp.y=dy[i]+now.y;
            if(tmp.x>=1&&tmp.x<=n&&tmp.y>=1&&tmp.y<=m){
                tmp.ti=now.ti+1;
                mod=tmp.ti%T[tmp.x][tmp.y];
                if(mod==0){
                    tmp.sum=now.sum+1;
                }
                else{
                    tmp.sum=now.sum;
                }
                if(dp[tmp.x][tmp.y][mod][tmp.sum]!=-1&&tmp.ti<dp[tmp.x][tmp.y][mod][tmp.sum]){
                    dp[tmp.x][tmp.y][mod][tmp.sum]=tmp.ti;
                    q.push(tmp);
                }
                else if(dp[tmp.x][tmp.y][mod][tmp.sum]==-1){
                    dp[tmp.x][tmp.y][mod][tmp.sum]=tmp.ti;
                    q.push(tmp);
                }
            }
        }
    }
    int ans=(int)(1e9)+10;
    for(int i=0;i<10;i++){
        for(int j=C;j<2001;j++){
            if(dp[ed.x][ed.y][i][j]!=-1){
                ans=min(ans,dp[ed.x][ed.y][i][j]);
//                deb(dp[ed.x][ed.y][i][j]);
            }
        }
    }
    cout<<ans<<'\n';
}

int main(void){
    FC;
//    FIN;
    cin>>n>>m>>C;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>T[i][j];
        }
    }
    cin>>st.x>>st.y;
    cin>>ed.x>>ed.y;
    memset(dp,-1,sizeof(dp));
    solve();
    return 0;
}
