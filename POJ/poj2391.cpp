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

const long double PI=acos(-1.0);  
const long double eps=1e-6;
const long long maxw=(long long)1e17+(long long)10;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll,ll> pii;
 
/*head------[@cordercorder]*/

const int maxn=210;
const int inf=(ll)1e9;
const ll INF=(ll)1e18;

int n,m;
int cow[maxn],hold[maxn],sum;
ll ma[maxn][maxn];

struct node{
    int to;
    int flow;
    int next;
};
node g[maxn*maxn*2+4*maxn];
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

bool check(ll x){
    Init_e();
    for(int i=1;i<=n;i++){
        add(from,i,cow[i]);
        add(i,from,0);
    }
    for(int i=1;i<=n;i++){
        add(i+n,to,hold[i]);
        add(to,i+n,0);
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(ma[i][j]<=x){
                add(i,j+n,inf);
                add(j+n,i,0);
            }
        }
    }
    int maxflow=dinic();
    if(maxflow==sum){
        return true;
    }
    return false;
}

void solve(){
    from=0,to=2*n+1;
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                ma[i][j]=min(ma[i][j],ma[i][k]+ma[k][j]);
            }
        }
    }
    ll l=0,r=INF,mid;
    while(l<r){
        mid=(l+r)>>1;
        if(check(mid)){
            r=mid;
        }
        else{
            l=mid+1;
        }
    }
    if(l==INF){
        puts("-1");
    }
    else{
        printf("%lld\n",l);
    }
}

int main(void){
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%d %d",&cow[i],&hold[i]);
        sum+=cow[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i==j){
                ma[i][j]=0;
            }
            else{
                ma[i][j]=INF;
            }
        }
    }
    int tmp,u,v;
    for(int i=1;i<=m;i++){
        scanf("%d %d %d",&u,&v,&tmp);
        if(ma[u][v]>tmp){
            ma[u][v]=tmp;
            ma[v][u]=tmp;
        }
    }
    solve();
    return 0;
}
