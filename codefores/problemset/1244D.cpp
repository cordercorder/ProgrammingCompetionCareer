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

const ll maxn=(ll)1e5+10;

ll n;
ll c[maxn][3],lv[maxn];
vector<ll> e[maxn];
ll deg[maxn];
bool f;
vector<ll> rev;

void dfs(ll u,ll fa){
    rev.push_back(u);
    ll ans=0;
    for(ll v:e[u]){
        if(v!=fa){
            dfs(v,u);
            ans++;
        }
    }
    if(ans>1){
        f=false;
    }
}

void solve(){
    f=true;
    for(ll i=1;i<=n;i++){
        if(deg[i]==1){
            dfs(i,0);
            break;
        }
    }
    if(!f){
        puts("-1");
        return ;
    }
    vector<ll> per={0,1,2};
    vector<ll> ans=per;
    ll sum=0,ANS=(ll)1e18;
    do{
        ll tot=0;
        sum=0;
        for(ll i=0;i<n;i++,tot=(tot+1)%3){
            sum+=c[rev[i]][per[tot]];
        }
        if(sum<ANS){
            ANS=sum;
            ans=per;
        }
    }while(next_permutation(per.begin(),per.end()));
    printf("%lld\n",ANS);
    for(ll i=0,j=0;i<n;i++,j=(j+1)%3){
        lv[rev[i]]=ans[j]+1;
    }
    for(ll i=1;i<=n;i++){
        printf("%lld ",lv[i]);
    }
}

int main(void){
    scanf("%lld",&n);
    for(ll i=0;i<3;i++){
        for(ll j=1;j<=n;j++){
            scanf("%lld",&c[j][i]);
        }
    }
    ll u,v;
    for(ll i=1;i<n;i++){
        scanf("%lld %lld",&u,&v);
        e[u].push_back(v);
        e[v].push_back(u);
        deg[v]++;
        deg[u]++;
    }
    solve();
    return 0;
}
