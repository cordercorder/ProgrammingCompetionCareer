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
#include<set>
#include<map>

#define deb(x) cout<<"#---"<<#x<<"=="<<x<<endl
#define FC ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define FIN freopen("in.txt","r",stdin)
#define FOUT freopen("A.txt","w",stdout)

using namespace std;

const long double PI=acos(-1.0);  
const long double eps=1e-6;
const int maxw=1e9+10;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
/*head------[@cordercorder]*/

const int maxn=(1e3+10)*(1e3+10);

struct node{
    int to;
    int flow;
    int next;
}e[maxn*6]; 

int n,m,cnt;
int d[maxn],head[maxn];
int from,to;

void Init_e(){
    cnt=0;
    memset(head,-1,sizeof(head));
}

void add(int u,int v,int flow){
    e[cnt].to=v;
    e[cnt].flow=flow;
    e[cnt].next=head[u];
    head[u]=cnt++;
}

bool bfs(){
    memset(d,0,sizeof(d));
    d[from]=1;
    queue<int> q;
    q.push(from);
    int u,v;
    while(!q.empty()){
        u=q.front();
        q.pop();
        for(int i=head[u];i!=-1;i=e[i].next){
            v=e[i].to;
            if(!d[v]&&e[i].flow>0){
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
    for(int i=head[u];i!=-1;i=e[i].next){
        v=e[i].to;
        if(d[v]==d[u]+1&&e[i].flow>0){
            tmp=dfs(v,min(flow-sum,e[i].flow));
            e[i].flow-=tmp;//正向边 
            e[i^1].flow+=tmp;//反向边 
            sum+=tmp;
            if(sum==flow)
                return flow;
            else
                d[v]=-1;//加这句优化 
        }
    }
    return sum;
}

int dinic(){
    int ans=0;
    while(bfs()){
        ans+=dfs(from,maxw);
    }
    return ans;
}

int main(void){
    FC;
    cin>>n>>m;
    int u,v;
    int w;
    Init_e();
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m-1;j++){
            cin>>w;
            u=m*(i-1)+j;
            v=u+1;
            add(u,v,w);
            add(v,u,0);
        } 
    }
    for(int i=1;i<=n-1;i++){
        for(int j=1;j<=m;j++){
            cin>>w;
            u=m*(i-1)+j;
            v=u+m;
            add(u,v,w);
            add(v,u,0);
        }
    }
    for(int i=1;i<=n-1;i++){
        for(int j=1;j<=m-1;j++){
            cin>>w;
            u=m*(i-1)+j;
            v=u+1+m;
            add(u,v,w);
            add(v,u,0);
        }
    }
    from=1;
    to=n*m;
    cout<<dinic()<<'\n';
	return 0;
}
