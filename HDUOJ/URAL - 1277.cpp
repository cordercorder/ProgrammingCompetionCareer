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
const int inf=(int)1e9;

int K;
int N,M,S,F;

struct node{
    int to;
    int flow;
    int next;
};
node g[maxn*2+10010*4];
int cnt,head[maxn+maxn],d[maxn+maxn];
int from,to;// 源点和汇点 ,注意节点编号的范围 

void Init_e(){
    cnt=0;
    for(int i=0;i<=2*N;i++){
        head[i]=-1;
    }
}

void add(int u,int v,int flow){
    g[cnt].to=v;
    g[cnt].flow=flow;
    g[cnt].next=head[u];
    head[u]=cnt++;
}

bool bfs(){
    for(int i=0;i<=2*N;i++){
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

int dfs(int u,int flow){
    if(u==to||flow==0)
        return flow;
    int sum=0,v,tmp;//sum为经过节点u最多能增加的流 
    for(int i=head[u];i!=-1;i=g[i].next){
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

int dinic(){
    int ans=0;
    while(bfs()){
        ans+=dfs(from,inf);
    }
    return ans;
}

void solve(){
    from=F;
    to=S+N;
    int maxflow=dinic();
//    deb(maxflow);
    if(maxflow<=K){
        puts("YES");
    }
    else{
        puts("NO");
    }
}

int main(void){
    int x,u,v;
    scanf("%d",&K);
    scanf("%d %d %d %d",&N,&M,&S,&F);
    Init_e();
    add(S,S+N,inf);
    add(S+N,S,0);
    add(F,F+N,inf);
    add(F+N,F,0);
    for(int i=1;i<=N;i++){
        scanf("%d",&x);
        if(i!=S&&i!=F){
            add(i,i+N,x);
            add(i+N,i,0);
        }
    }
    for(int i=1;i<=M;i++){
        scanf("%d %d",&u,&v);
        add(u+N,v,inf);
        add(v,u+N,0);
        
        add(v+N,u,inf);
        add(u,v+N,0);
    }
    if(S==F){
        puts("NO");
        return 0;
    } 
    solve();
    return 0;
}
