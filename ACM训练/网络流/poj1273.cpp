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
const long long maxw=1e11+10;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
/*head------[@cordercorder]*/

const ll maxn=2e2+10;

struct node{
    ll to;
    ll flow;
    ll next;
}e[maxn*4];

ll cnt;
ll head[maxn];
ll n,m;
ll from,to;
ll d[maxn];

void Init_e(){
    cnt=0;
    memset(head,-1,sizeof(head));
}

void add(ll u,ll v,ll flow){
    e[cnt].to=v;
    e[cnt].flow=flow;
    e[cnt].next=head[u];
    head[u]=cnt++;
}

bool bfs(){
    memset(d,0,sizeof(d));
    d[from]=1;
    queue<ll> q;
    q.push(from);
    ll u,v;
    while(!q.empty()){
        u=q.front();
        q.pop();
        for(ll i=head[u];i!=-1;i=e[i].next){
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

ll dfs(ll u,ll flow){
    if(u==to||flow==0)
        return flow;
    ll sum=0,v,tmp;
    for(ll i=head[u];i!=-1;i=e[i].next){
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

ll solve(){
    ll ans=0;
    while(bfs()){
        ans+=dfs(from,maxw);
    }
    return ans;
}

int main(void){
    while(scanf("%lld %lld",&n,&m)!=EOF){
        Init_e();
        ll u,v,w;
        for(ll i=0;i<n;i++){
            scanf("%lld %lld %lld",&u,&v,&w);
            add(u,v,w);
            add(v,u,0);
        }
        from=1;
        to=m;
        printf("%lld\n",solve());
    }
	return 0;
}
