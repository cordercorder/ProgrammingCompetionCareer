#include<bits/stdc++.h>
 
using namespace std;
 
#define FC ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define deb(args...) std::cerr<<"DEBUG------"<<'\n';std::cerr<<#args<<"------>";err(args)

void err(){
    std::cerr<<'\n'<<"END OF DEBUG"<<'\n'<<'\n';
}

template<typename T,typename... Args>
void err(T a,Args... args){
    std::cerr<<a<<", ";
    err(args...);
}

template<template<typename...> class T,typename t,typename... Args>
void err(T<t> a, Args... args){
    for(auto x: a){
        std::cerr<<x<<", ";
    }
    err(args...);
}

const long double PI=acos(-1.0);  
const long double eps=1e-6;
const long long maxw=(long long)1e17+(long long)10;
 
using ll=long long;
using ull=unsigned long long;
using pii=pair<int,int>;
 
/*head------[@cordercorder]*/

namespace mincost{
    
    const ll maxn=1010*2;
    const ll inf=(ll)1e11;
    using pii=pair<ll,ll>;
    
    struct node{
        ll to;
        ll cap;
        ll cost;
        ll rev;
        node(){}
        node(ll _to,ll _cap,ll _cost,ll _rev):to(_to),cap(_cap),cost(_cost),rev(_rev){}
    };
    
    vector<node> e[maxn];
    ll preV[maxn],preE[maxn],h[maxn],dis[maxn];
    ll N;
    
    // N is the max index of the node in the graph
    void Init(ll _N){
        N=_N;
        for(int i=0;i<=N;i++){
            e[i].clear();
        }
    }
    
    void add(ll u,ll v,ll cap,ll cost){
        e[u].push_back(node(v,cap,cost,e[v].size()));
        e[v].push_back(node(u,0,-cost,e[u].size()-1));
    }
    
    ll min_cost_max_flow(ll s,ll t,ll f,ll &flow){
        ll ans=0,v;
        for(int i=0;i<=N;i++){
            h[i]=0;
        }
        while(f){
            priority_queue<pii,vector<pii>,greater<pii>> q;
            for(int i=0;i<=N;i++){
                dis[i]=inf;
            }
            dis[s]=0;
            q.push(pii(0,s));
            pii now;
            while(!q.empty()){
                now=q.top();
                q.pop();
                v=now.second;
                if(dis[v]<now.first)
                    continue;
                for(int i=0;i<(int)e[v].size();i++){
                    node &edge=e[v][i];
                    if(edge.cap>0&&dis[edge.to]>dis[v]+edge.cost+h[v]-h[edge.to]){
                        dis[edge.to]=dis[v]+edge.cost+h[v]-h[edge.to];
                        preV[edge.to]=v;
                        preE[edge.to]=i;
                        q.push(pii(dis[edge.to],edge.to));
                    }
                }
            }
            if(dis[t]==inf)
                break;
            for(int i=0;i<=N;i++){
                h[i]+=dis[i];
            }
            ll d=f;
            for(int i=t;i!=s;i=preV[i]){
                d=min(d,e[preV[i]][preE[i]].cap);
            }
            f-=d;
            flow+=d;
            ans+=d*h[t];
            for(int i=t;i!=s;i=preV[i]){
                node &edge=e[preV[i]][preE[i]];
                edge.cap-=d;
                e[i][edge.rev].cap+=d;
            }
        }
        return ans;
    }
}

const ll maxn=2010;

ll N;
ll p,m,f,n,s;
ll r[maxn];

void solve(){
    ll from=0,to=2*N+1;
    for(int i=1;i<=N;i++){
        mincost::add(from,i,mincost::inf,p);
        mincost::add(from,i+N,r[i],0);
        mincost::add(i,to,r[i],0);
    }
    for(int i=1;i<=N;i++){
        if(i+m<=N)
            mincost::add(i+N,i+m,mincost::inf,f);
        if(i+n<=N)
            mincost::add(i+N,i+n,mincost::inf,s);
        if(i+1<=N)
            mincost::add(i+N,i+N+1,mincost::inf,0);
    }
    ll flow=0;
    printf("%lld\n",mincost::min_cost_max_flow(from,to,mincost::inf,flow));
}

int main(void){
    scanf("%lld",&N);
    mincost::Init(2*N+1);
    for(int i=1;i<=N;i++){
        scanf("%lld",&r[i]);
    }
    scanf("%lld %lld %lld %lld %lld",&p,&m,&f,&n,&s);
    solve();
    return 0;
}
