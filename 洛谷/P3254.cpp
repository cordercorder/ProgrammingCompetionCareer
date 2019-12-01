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

const int inf=(int)1e9;
const int maxn=450;

int m,n,sum;
vector<int> rev[maxn];

struct node{
    int to;
    int flow;
    int next;
};
node g[300*200*2+4*300];
int cnt,head[maxn],d[maxn];
int from,to;// 源点和汇点 ,注意节点编号的范围 

void Init_e(){
    cnt=0;
    for(int i=0;i<=m+n+1;i++){
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
    for(int i=0;i<=m+n+1;i++){
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
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            add(i,j+m,1);
            add(j+m,i,0);
        }
    }
    int maxflow=dinic();
    if(maxflow<sum){
        puts("0");
        return ;
    }
    puts("1");
    for(int i=1;i<=m;i++){
        for(int j=head[i];j!=-1;j=g[j].next){
            if(g[j].to!=from&&g[j].flow==0){
                rev[i].push_back(g[j].to-m);
            }
        }
    }
    for(int i=1;i<=m;i++){
        for(int j=0;j<(int)rev[i].size();j++){
            if(j>0){
                printf(" ");
            }
            printf("%d",rev[i][j]);
        }
        puts("");
    }
}

int main(void){
    int x;
    scanf("%d %d",&m,&n);
    Init_e();
    from=0;
    to=n+m+1;
    for(int i=1;i<=m;i++){
        scanf("%d",&x);
        add(from,i,x);
        add(i,from,0);
        sum+=x;
    }
    for(int i=1;i<=n;i++){
        scanf("%d",&x);
        add(i+m,to,x);
        add(to,i+m,0); 
    }
    solve();
    return 0;
}
