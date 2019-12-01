#include<algorithm>
#include<iostream>
#include<limits.h>
#include<cstdlib>
#include<cstring>
#include<vector>
#include<string>
#include<cstdio>
#include<bitset>
#include<cmath>
#include<queue>
#include<stack>
#include<deque>
#include<ctime>
#include<list>
#include<set>
#include<map>
using namespace std;
 
/*head------[@cordercorder]*/

const int maxn=110;
const int inf=(int)1e9;

int F,D,N;

struct node{
    int to;
    int flow;
    int next;
};
node g[maxn*maxn*4+6*maxn];
int cnt,head[4*maxn],d[4*maxn];
int from,to;// 源点和汇点 ,注意节点编号的范围 

void Init_e(){
    cnt=0;
    for(int i=0;i<=F+N+N+D+1;i++){
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
    for(int i=0;i<=F+N+N+D+1;i++){
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

int main(void){
    int num1,num2,x;
    scanf("%d %d %d",&N,&F,&D);
    Init_e();
    from=0;
    to=F+N+N+D+1;
    for(int i=1;i<=F;i++){
        add(from,i,1);
        add(i,from,0);
    }
    for(int i=1;i<=D;i++){
        add(F+N+N+i,to,1);
        add(to,F+N+N+i,0);
    }
    for(int i=1;i<=N;i++){
        add(F+i,F+N+i,1);
        add(F+N+i,F+i,0);
    }
    for(int i=1;i<=N;i++){
        scanf("%d %d",&num1,&num2);
        for(int j=1;j<=num1;j++){
            scanf("%d",&x);
            add(x,F+i,1);
            add(F+i,x,0);
        }
        for(int j=1;j<=num2;j++){
            scanf("%d",&x);
            add(F+N+i,F+N+N+x,1);
            add(F+N+N+x,F+N+i,0);
        }
    }
    int maxflow=dinic();
    printf("%d\n",maxflow);
    return 0;
}
