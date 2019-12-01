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

using namespace std;

const long double PI=acos(-1.0);  
const long double eps=1e-6;
const long long maxw=(long long)1e17+(long long)10;

typedef long long ll;

/*head------[@cordercorder]*/

const ll maxn=(ll)1e5+10ll;
const ll inf=(ll)1e18;

struct node{
    ll to;
    ll w;
    ll f;
    node(ll _to=0,ll _w=0,ll _f=0):to(_to),w(_w),f(_f){}
    
    bool operator<(const node &a)const{
        return w>a.w;
    }
};
ll N,R;
vector<node> e[maxn];
ll dis[maxn][2];
bool isv[maxn][2];

void solve(){
    priority_queue<node> q;
    for(ll i=1;i<=N;i++){
        dis[i][0]=inf;
        dis[i][1]=inf;
        isv[i][0]=false;
        isv[i][1]=false;
    }
    dis[1][0]=0;
    q.push(node(1,dis[1][0],0));
    node now;
    ll u,v,w;
    while(!q.empty()){
        now=q.top();
        q.pop();
        u=now.to;
        if(isv[u][now.f])
            continue;
        isv[u][now.f]=true;
        for(ll i=0;i<(ll)e[u].size();i++){
            v=e[u][i].to;
            w=now.w+e[u][i].w;
            if(w<dis[v][0]){
                dis[v][1]=dis[v][0];
                dis[v][0]=w;
                q.push(node(v,dis[v][1],1));
                q.push(node(v,dis[v][0],0));
            }
            else if(w==dis[v][0]){
                dis[v][1]=dis[v][0];
                q.push(node(v,dis[v][1],1));
            }
            else if(w<dis[v][1]){
                dis[v][1]=w;
                q.push(node(v,dis[v][1],1));
            }
        }
    }
    printf("%lld\n",dis[N][1]);
}

int main(void){
    ll u,v,w;
    scanf("%lld %lld",&N,&R);
    for(ll i=1;i<=R;i++){
        scanf("%lld %lld %lld",&u,&v,&w);
        e[u].push_back({v,w,-1});
        e[v].push_back({u,w,-1});
    }
    solve();
    return 0;
}
