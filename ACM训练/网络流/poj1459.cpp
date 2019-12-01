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

const int maxn=1e2+10;
const int from=101;
const int to=102;

int n,np,nc,m;
char s[10000];

struct node{
    int to;
    int next;
    int flow;
}e[(maxn*maxn+maxn+maxn)*2];

int head[maxn];
int cnt;
int d[maxn];

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

void handle(){
    int len=strlen(s);
    int i;
    int u=0,v=0,w=0;
    for(i=1;i<len;i++){
        if(s[i]>='0'&&s[i]<='9'){
            u=u*10+(int)(s[i]-'0');
        }
        else{
            i++;
            break;
        }
    }
    for(;i<len;i++){
        if(s[i]>='0'&&s[i]<='9'){
            v=v*10+(int)(s[i]-'0');
        }
        else{
            i++;
            break;
        }
    }
    for(;i<len;i++){
        if(s[i]>='0'&&s[i]<='9'){
            w=w*10+(int)(s[i]-'0');
        }
        else{
            break;
        }
    }
    add(u,v,w);
    add(v,u,0);
}

void handle1(bool f){
    int len=strlen(s);
    int u=0,w=0;
    int i;
    for(i=1;i<len;i++){
        if(s[i]>='0'&&s[i]<='9'){
            u=u*10+(int)(s[i]-'0'); 
        }
        else{
            i++;
            break;
        }
    }
    for(;i<len;i++){
        if(s[i]>='0'&&s[i]<='9'){
            w=w*10+(int)(s[i]-'0');
        }
        else{
            break;
        }
    }
    if(f){
        add(from,u,w);
        add(u,from,0);
    }
    else{
        add(u,to,w);
        add(to,u,0);
    }
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
        for(int i=head[u];~i;i=e[i].next){
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
    for(int i=head[u];~i;i=e[i].next){
        v=e[i].to;
        if(d[v]==d[u]+1&&e[i].flow>0){
            tmp=dfs(v,min(flow-sum,e[i].flow));
            e[i].flow-=tmp;
            e[i^1].flow+=tmp;
            sum+=tmp;
            if(tmp==flow)
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
    while(scanf("%d %d %d %d",&n,&np,&nc,&m)!=EOF){
        Init_e();
        for(int i=0;i<m;i++){
            scanf("%s",s);
            handle();
        }
        for(int i=0;i<np;i++){
            scanf("%s",s);
            handle1(true);
        }
        for(int i=0;i<nc;i++){
            scanf("%s",s);
            handle1(false);
        }
        printf("%d\n",dinic());
    }
	return 0;
}
