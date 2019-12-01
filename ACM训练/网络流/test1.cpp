#include<stdio.h>
#include<string.h>
#include<iostream>
#include<queue>
#define INF 99999999
using namespace std;
const int maxn = 1002;
struct node
{
    int to;
    int f;
    int cost;
    int flag;
    int next;
}edge[maxn*maxn/2];
int index,head[maxn],vis[maxn],dis[maxn],n,pre[maxn],fpre[maxn];//�������ڽӱ� ֱ���ҵ��㲢�����ҵ�ֵ ����fpre��ȡ���õ��index
void init()
{
    index=1;
    memset(head,-1,sizeof(head));
}
void add(int x,int y,int v,int cost)
{
    edge[index].to=y;
    edge[index].f=v;
    edge[index].cost=cost;
    edge[index].next=head[x];
    edge[index].flag=index+1;
    head[x]=index++;
    edge[index].to=x;
    edge[index].f=0;
    edge[index].cost=-cost;
    edge[index].next=head[y];
    edge[index].flag=index-1;
    head[y]=index++;
}
bool spfa(int s,int t)
{
    int i,j;
    queue<int>q;
    memset(pre,-1,sizeof(pre));//pre��¼·��
    memset(vis,0,sizeof(vis));
    for(i=0;i<=t;i++)
        dis[i]=INF;
    dis[s]=0;
    vis[s]=1;
    pre[s]=0;
    q.push(s);
    while(!q.empty())
    {
        int temp=q.front();
        q.pop();
        vis[temp]=0;
        for(i=head[temp];i!=-1;i=edge[i].next)
        {
            if(edge[i].f&&dis[edge[i].to]>dis[temp]+edge[i].cost)//�����ɳڲ��ҿ�����
            {
                dis[edge[i].to]=dis[temp]+edge[i].cost;
                if(!vis[edge[i].to])
                {
                    vis[edge[i].to]=1;
                    q.push(edge[i].to);
                }
                pre[edge[i].to]=temp;
                fpre[edge[i].to]=i;
            }
        }
    }
    cout<<dis[t]<<endl;
    if(dis[t]>=INF)
        return false;
    return true;
}
void MCMF(int s,int t)//��С������
{
    int i,j;
    int ans=0;
    while(spfa(s,t))//���·Ѱ��С�ķ��� ���Ƿ�������·
    {
        int minflow=INF;
        for(i=t;i!=0;i=pre[i])//�ڷ�����С������� Ѱ�ҿ��е�����
        {
            if(minflow>edge[fpre[i]].f)
                minflow=edge[fpre[i]].f;
        }
        ans+=minflow*dis[t];//����
        for(i=t;i!=0;i=pre[i])
        {
            edge[fpre[i]].f-=minflow;//����ļ�
            edge[edge[fpre[i]].flag].f+=minflow;//�����
        }
        std::cout<<ans<<endl;
    }
    printf("%d\n",ans);
}
int main()
{
    int i,j,m;
    while(~scanf("%d%d",&n,&m))
    {
        init();
        int x,y,z;
        for(i=0;i<m;i++)
        {
            scanf("%d%d%d",&x,&y,&z);
            add(x,y,1,z);
            add(y,x,1,z);
        }
        int s=0,t=n+1;
        add(s,1,2,0);//Դ�㵽����������Ϊ2 ����0
        add(n,t,2,0);//����������Ϊ2,����0
        MCMF(s,t);
    }
}
