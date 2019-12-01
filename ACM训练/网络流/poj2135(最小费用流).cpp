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
const int maxw=1e8+10;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
/*head------[@cordercorder]*/

const int maxn=2e3+10;

int n,m;
int dis[maxn],pre[maxn],fpre[maxn];
bool isv[maxn];
int st,ed;

struct node{
    int to;
    int next;
    int flow;
    int dis;
    node(){}
    node(int a,int b,int c,int d):to(a),next(b),flow(c),dis(d){}
}e[(10000+100)*4];

int head[maxn];
int cnt;

void Init_e(){
    cnt=0;
    memset(head,-1,sizeof(head));
}

void add(int from,int to,int flow,int dis){
    e[cnt].next=head[from];
    e[cnt].to=to;
    e[cnt].flow=flow;
    e[cnt].dis=dis;
    head[from]=cnt++;
}

bool spfa(int st,int ed){
    queue<int> q;
    memset(pre,-1,sizeof(pre));
    memset(isv,false,sizeof(isv));
    for(int i=0;i<=ed;i++){
        dis[i]=maxw;
    }
    q.push(st);
    isv[st]=true;
    dis[st]=0;
    pre[st]=0;
    int now;
    while(!q.empty()){
        now=q.front();
        q.pop();
        isv[now]=false;
        for(int i=head[now];i!=-1;i=e[i].next){
            if(e[i].flow>0&&dis[e[i].to]>dis[now]+e[i].dis){
                dis[e[i].to]=dis[now]+e[i].dis;
                pre[e[i].to]=now;
                fpre[e[i].to]=i;
                if(isv[e[i].to]==false){
                    isv[e[i].to]=true;
                    q.push(e[i].to);
                }
            }
        }
    }
    if(dis[ed]>=maxw)
        return false;
    return true;
}

void min_cost_flow(){
    int ans=0,minflow;
    int now;
    while(spfa(st,ed)){
        minflow=maxw;
        for(int i=ed;i!=0;i=pre[i]){
            if(minflow>e[fpre[i]].flow)
                minflow=e[fpre[i]].flow;
        }
        ans+=minflow*dis[ed];
        for(int i=ed;i!=0;i=pre[i]){
            e[fpre[i]].flow-=minflow;
            e[fpre[i]^1].flow+=minflow;
        }
    }
    printf("%d\n",ans);
}

int main(void){
    int u,v,cost;
    while(scanf("%d %d",&n,&m)!=EOF){
        Init_e();   
        for(int i=0;i<m;i++){
            scanf("%d %d %d",&u,&v,&cost);
            add(u,v,1,cost);
            add(v,u,0,-cost);
            add(v,u,1,cost);
            add(u,v,0,-cost);
        }
        st=0;
        ed=n+1;
        add(st,1,2,0);
        add(1,st,0,0);
        add(n,ed,2,0);
        add(ed,n,0,0);
        min_cost_flow();
    }
	return 0;
}
