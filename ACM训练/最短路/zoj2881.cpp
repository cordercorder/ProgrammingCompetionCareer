#include<bits/stdc++.h>
 
using namespace std;
 
#define FC ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define FIN freopen("in.txt","r",stdin)
#define FOUT freopen("out.txt","w",stdout)
#define deb(x) cerr<<"DEBUG------"<<'\n';cerr<<#x<<"------>";err(x)
 
template<typename T>
void err(T a){
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

const int maxn=1010;

struct node{
    int to;
    int w;
};

struct Node{
    int id;
    int fill;
    int cost;
    bool operator<(const Node &a)const{
        return cost>a.cost;
    }
};

int p[maxn],n,m;
vector<node> e[maxn];
int c,st,ed;
int dis[maxn][101];
bool isv[maxn][101];

void solve(){
    for(int i=0;i<n;i++){
        for(int j=0;j<=c;j++){
            dis[i][j]=(int)1e9;
            isv[i][j]=false;
        }
    }
    priority_queue<Node> q;
    q.push({st,0,0});
    dis[st][0]=0;
    Node now;
    int u,v,w,ret,need;
    while(!q.empty()){
        now=q.top();
        q.pop();
        if(isv[now.id][now.fill]){
            continue;
        }
        isv[now.id][now.fill]=true;
        if(now.fill<c&&now.cost+p[now.id]<dis[now.id][now.fill+1]){
            dis[now.id][now.fill+1]=now.cost+p[now.id];
            q.push({now.id,now.fill+1,dis[now.id][now.fill+1]});
        }
        u=now.id;
        for(int i=0;i<(int)e[u].size();i++){
            v=e[u][i].to;
            w=now.fill-e[u][i].w;
            if(w>=0&&dis[v][w]>dis[u][now.fill]){
                dis[v][w]=dis[u][now.fill];
                q.push({v,w,now.cost});
            }
        }
    }
    int ans=(int)1e9;
    for(int i=0;i<=c;i++){
        ans=min(ans,dis[ed][i]);
    }
    if(ans==(int)1e9){
        puts("impossible");
    }
    else{
        printf("%d\n",ans);
    }
}

int main(void){
    int u,v,d,q;
    scanf("%d %d",&n,&m);
    for(int i=0;i<n;i++){
        scanf("%d",&p[i]);
    }
    for(int i=1;i<=m;i++){
        scanf("%d %d %d",&u,&v,&d);
        e[u].push_back({v,d});
        e[v].push_back({u,d});
    }
    scanf("%d",&q);
    while(q--){
        scanf("%d %d %d",&c,&st,&ed);
        solve();
    }
    
    return 0;
}
