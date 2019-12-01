#include<bits/stdc++.h>
 
using namespace std;
 
#define FC ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define deb(args...) std::cerr<<"DEBUG------"<<'\n';std::cerr<<#args<<"------>";err(args)

void err(){
    std::cerr<<'\n'<<"END OF DEBUG"<<'\n'<<'\n';
}

template<typename T,typename... Args>
void err(T a,Args... args){
    std::cerr<<a<<", ";
    err(args...);
}

template<template<typename...> class T,typename t,typename... Args>
void err(T<t> a, Args... args){
    for(auto x: a){
        std::cerr<<x<<", ";
    }
    err(args...);
}

const long double PI=acos(-1.0);  
const long double eps=1e-6;
const long long maxw=(long long)1e17+(long long)10;
 
using ll=long long;
using ull=unsigned long long;
using pii=pair<int,int>;
 
/*head------[@cordercorder]*/

const int maxn=110;
const ll inf=(ll)1e9;

ll ma[maxn][maxn];
ll n,m;
ll sum;

struct node{
    ll to;
    ll flow;
    ll next;
};
node g[maxn*maxn*8+maxn*maxn*2];
ll cnt,head[maxn*maxn],d[maxn*maxn];
ll from,to;// 源点和汇点 ,注意节点编号的范围 
ll dx[]={0,1,0,-1};
ll dy[]={1,0,-1,0};

void Init_e(){
    cnt=0;
    for(ll i=0;i<=n*m+1;i++){
        head[i]=-1;
    }
}

void add(ll u,ll v,ll flow){
    g[cnt].to=v;
    g[cnt].flow=flow;
    g[cnt].next=head[u];
    head[u]=cnt++;
}

bool bfs(){
    for(ll i=0;i<=n*m+1;i++){
    	d[i]=0;
    }
    d[from]=1;
    queue<int> q;
    q.push(from);
    int u,v;
    while(!q.empty()){
        u=q.front();
        q.pop();
        for(int i=head[u];i!=-1;i=g[i].next){
            v=g[i].to;
            if(!d[v]&&g[i].flow>0){
                d[v]=d[u]+1;
                q.push(v);
                if(v==to)
                    return true;
            }
        }
    }
    return false;
}

ll dfs(ll u,ll flow){
    if(u==to||flow==0)
        return flow;
    ll sum=0,v,tmp;//sum为经过节点u最多能增加的流 
    for(ll i=head[u];i!=-1;i=g[i].next){
        v=g[i].to;
        if(d[v]==d[u]+1&&g[i].flow>0){
            tmp=dfs(v,min(flow-sum,g[i].flow));
            g[i].flow-=tmp;//正向边 
            g[i^1].flow+=tmp;//反向边 
            sum+=tmp;
            if(sum==flow)
                break;
        }
    }
    if(sum==0){//优化 
        d[u]=-1;
    }
    return sum;
}

ll dinic(){
    ll ans=0;
    while(bfs()){
        ans+=dfs(from,inf);
    }
    return ans;
}

void solve(){
    from=0;
    to=n*m+1;
    Init_e();
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if((i+j)%2==1){
                add(from,(i-1)*n+j,ma[i][j]);
                add((i-1)*n+j,from,0); 
            }
            else{
                add((i-1)*n+j,to,ma[i][j]);
                add(to,(i-1)*n+j,0);
            }
        }
    }
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if((i+j)%2==1){
                for(int k=0;k<4;k++){
                    int nx=i+dx[k];
                    int ny=j+dy[k];
                    if(nx>=1&&nx<=m&&ny>=1&&ny<=n){
                        add((i-1)*n+j,(nx-1)*n+ny,inf);
                        add((nx-1)*n+ny,(i-1)*n+j,0);
                    }
                }
            }
        }
    }
    ll maxflow=dinic();
    sum-=maxflow;
    printf("%lld\n",sum);
}

int main(void){
    scanf("%lld %lld",&m,&n);
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            scanf("%lld",&ma[i][j]);
            sum+=ma[i][j];
        }
    }
    solve();
    return 0;
}
