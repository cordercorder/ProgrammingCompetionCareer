#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
const int maxn=100010;

bool vis[maxn];
int n,m,s,t,x,y,z,f,dis[maxn],pre[maxn],last[maxn],flow[maxn],maxflow,mincost;
//dis最小花费;pre每个点的前驱；last每个点的所连的前一条边；flow源点到此处的流量 
struct Edge{
    int to,next,flow,dis;//flow流量 dis花费 
}edge[maxn];
int head[maxn],num_edge; 
queue <int> q;

void add_edge(int from,int to,int flow,int dis)
{
    edge[num_edge].next=head[from];
    edge[num_edge].to=to;
    edge[num_edge].flow=flow;
    edge[num_edge].dis=dis;
    head[from]=num_edge++;
}

bool spfa(int s,int t)
{
    memset(dis,0x7f,sizeof(dis));
    memset(flow,0x7f,sizeof(flow));
    memset(vis,0,sizeof(vis));
    q.push(s); vis[s]=1; dis[s]=0; pre[t]=-1;

    while (!q.empty())
    {
        int now=q.front();
        q.pop();
        vis[now]=0;
        for (int i=head[now]; i!=-1; i=edge[i].next)
        {
            if (edge[i].flow>0 && dis[edge[i].to]>dis[now]+edge[i].dis)//正边 
            {
                dis[edge[i].to]=dis[now]+edge[i].dis;
                pre[edge[i].to]=now;
                last[edge[i].to]=i;
                flow[edge[i].to]=min(flow[now],edge[i].flow);//
                if (!vis[edge[i].to])
                {
                    vis[edge[i].to]=1;
                    q.push(edge[i].to);
                }
            }
        }
    }
    return pre[t]!=-1;
}

void MCMF()
{
    while (spfa(s,t))
    {
        int now=t;
        maxflow+=flow[t];
        mincost+=flow[t]*dis[t];
        while (now!=s)
        {//从源点一直回溯到汇点 
        
            edge[last[now]].flow-=flow[t];//flow和dis容易搞混 
            edge[last[now]^1].flow+=flow[t];
            now=pre[now];
        }
    }
}

int main()
{
    memset(head,-1,sizeof(head)); num_edge=0;//初始化 
    scanf("%d%d",&n,&m);
    for (int i=1; i<=m; i++)
    {
        scanf("%d%d%d",&x,&y,&f);
        add_edge(x,y,1,f); add_edge(y,x,0,-f);
        //反边的流量为0，花费是相反数 
    }
    s=1;
    t=n;
    MCMF();
    printf("%d %d",maxflow,mincost);
    return 0;
}
