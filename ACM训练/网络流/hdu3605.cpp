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
const int maxw=1e7+10;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
/*head------[@cordercorder]*/

const int maxn=1e5+100;

int n,m;

struct node{
    int to;
    int next;
    int flow;
}e[1000100*2];

int head[2000],d[2000];
int cnt;
int a[20];
int from,to;
int num[1100];

void Init_e(){
    cnt=0;
    memset(head,-1,sizeof(head));
}

void add(int u,int v,int flow){
    e[cnt].to=v;
    e[cnt].next=head[u];
    e[cnt].flow=flow;
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
    int sum=0,v,tmp;
    for(int i=head[u];i!=-1;i=e[i].next){
        v=e[i].to;
        if(d[v]==d[u]+1&&e[i].flow>0){
            tmp=dfs(v,min(flow-sum,e[i].flow));
            e[i].flow-=tmp;
            e[i^1].flow+=tmp;
            sum+=tmp;
            if(sum==flow)
                return flow;
            else
                d[v]=-1;
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
    int tmp;
    int ret;
    while(scanf("%d %d",&n,&m)!=EOF){
        Init_e();
        int state=(1<<m);
        memset(num,0,sizeof(num));
        for(int i=1;i<=n;i++){
            ret=0;
            for(int j=1;j<=m;j++){
                scanf("%d",&tmp);
                if(tmp==1){
                    ret|=(1<<(j-1));
                }
            }
            num[ret]++;
        }
        from=0;
        to=state+m+1;
        for(int i=1;i<=m;i++){
            scanf("%d",&a[i]);
            add(i+state,to,a[i]);
            add(to,i+state,0);
        }
        for(int i=1;i<state;i++){
            if(num[i]){
                add(from,i,num[i]);
                add(i,from,0);
                for(int j=0;j<m;j++){
                    if(i&(1<<j)){
                        add(i,state+j+1,num[i]);
                        add(state+j+1,i,0);
                    }
                }
            }
        }
        if(dinic()==n)
            puts("YES");
        else
            puts("NO");
    }
	return 0;
}
