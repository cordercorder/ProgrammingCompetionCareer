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

const int maxn=1010+30;
const int inf=(int)1e9;

int k,n;
int res[maxn],sum;

struct node{
    int to;
    int flow;
    int next;
};
node g[maxn*maxn*2];
int cnt,head[maxn],d[maxn];
int from,to;
vector<int> ans[50];

void Init_e(){
    cnt=0;
    for(int i=0;i<=n+k+1;i++){
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
    for(int i=0;i<=n+k+1;i++){
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
    int sum=0,v,tmp;
    for(int i=head[u];i!=-1;i=g[i].next){
        v=g[i].to;
        if(d[v]==d[u]+1&&g[i].flow>0){
            tmp=dfs(v,min(flow-sum,g[i].flow));
            g[i].flow-=tmp;
            g[i^1].flow+=tmp;
            sum+=tmp;
            if(sum==flow)
                break;
        }
    }
    if(sum==0){
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
    from=0;
    to=n+k+1;
    for(int i=1;i<=n;i++){
        add(from,i,1);
        add(i,from,0);
    }
    for(int i=1;i<=k;i++){
        add(n+i,to,res[i]);
        add(to,n+i,0);
    }
    int maxflow=dinic();
    if(maxflow!=sum){
        puts("No Solution!");
        return ;
    }
    for(int i=1;i<=n;i++){
        for(int j=head[i];j!=-1;j=g[j].next){
            if(g[j].to!=from&&g[j].flow==0){
                ans[g[j].to-n].push_back(i);
            }
        }
    }
    for(int i=1;i<=k;i++){
        printf("%d:",i);
        for(int v:ans[i]){
            printf(" %d",v);
        }
        puts("");
    }
}

int main(void){
    int temp,v;
    scanf("%d %d",&k,&n);
    Init_e();
    for(int i=1;i<=k;i++){
        scanf("%d",&res[i]);
        sum+=res[i];
    }
    for(int i=1;i<=n;i++){
        scanf("%d",&temp);
        for(int j=1;j<=temp;j++){
            scanf("%d",&v);
            add(i,n+v,1);
            add(n+v,i,0);
        }
    }
    solve();
    return 0;
}
