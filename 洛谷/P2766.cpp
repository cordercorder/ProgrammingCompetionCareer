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

const int maxn=510;
const int inf=(int)1e9;

int n,a[maxn],dp[maxn];

struct node{
    int to;
    int flow;
    int next;
};
node g[maxn*maxn*2+6*maxn];
int cnt,head[maxn+maxn],d[maxn+maxn];
int from,to;// 源点和汇点 ,注意节点编号的范围 

void Init_e(){
    cnt=0;
    for(int i=0;i<=2*n+1;i++){
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
    for(int i=0;i<=2*n+1;i++){
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
            g[i].flow-=tmp;//正向边。满流时正向边的流量为0
            g[i^1].flow+=tmp;//反向边。满流时反向边的流量为起始时正向边的流量
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
    for(int i=1;i<=n;i++){
        dp[i]=1;
        for(int j=1;j<i;j++){
            if(a[j]<=a[i]){
                dp[i]=max(dp[i],dp[j]+1);
            }
        }
    }
    int maxe=dp[1];
    for(int i=2;i<=n;i++){
        maxe=max(maxe,dp[i]);
    }
    printf("%d\n",maxe);
    if(maxe==1){
        printf("%d\n%d",n,n);
        return ;
    }
    Init_e();
    from=0;
    to=2*n+1;
    for(int i=1;i<=n;i++){
        add(i+n,i,1);
        add(i,i+n,0);
    }
    for(int i=1;i<=n;i++){
        if(dp[i]==1){
            add(from,i,1);
            add(i,from,0);
        }
        if(dp[i]==maxe){
            add(i+n,to,1);
            add(to,i+n,0);
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<i;j++){
            if(a[j]<=a[i]&&dp[i]==dp[j]+1){
                add(j,i+n,1);
                add(i+n,j,0);
            }
        }
    }
    int maxflow=dinic();
    printf("%d\n",maxflow);
    Init_e();
    for(int i=1;i<=n;i++){
        add(i+n,i,1);
        add(i,i+n,0);
    }
    for(int i=1;i<=n;i++){
        if(dp[i]==1){
            int flow=1;
            if(i==1||i==n){
                flow=inf;
            }
            add(from,i,flow);
            add(i,from,0);
        }
        if(dp[i]==maxe){
            int flow=1;
            if(i==1||i==n){
                flow=inf;
            }
            add(i+n,to,flow);
            add(to,i+n,0);
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<i;j++){
            if(a[j]<=a[i]&&dp[i]==dp[j]+1){
                add(j,i+n,1);
                add(i+n,j,0);
            }
        }
    }
    maxflow=dinic();
    printf("%d\n",maxflow);
}

int main(void){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    solve();
    return 0;
}
