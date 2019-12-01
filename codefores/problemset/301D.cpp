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
using pii=pair<ll,ll>;
 
/*head------[@cordercorder]*/

const ll maxn=(ll)2e5+10;

ll n,m; 
pii p[maxn];
vector<pii> res;
ll ans[maxn],arr[maxn];

struct node{
    ll x;
    ll y;
    ll val;
    ll id;
};
vector<node> Q;

bool cmp(const pii &a,const pii &b){
    return a.first<b.first;
}

void pre_handle(){
    pii now,tmp;
    ll u,v;
    sort(p+1,p+1+n,cmp);
    for(ll i=1;i<=n;i++){
        now.first=i;
        u=(lower_bound(p+1,p+1+n,now,cmp))->second;
        for(ll j=i;j<=n;j+=i){
            tmp.first=j;
            v=(lower_bound(p+1,p+1+n,tmp,cmp))->second;
            res.push_back(pii(u,v));
        }
    }
}

ll lowbit(ll x){
    return x&(-x);
}

void Add(ll x,ll val){
    while(x<=n){
        arr[x]+=val;
        x+=lowbit(x);
    }
}

ll Sum(ll x){
    ll ans=0;
    while(x>0){
        ans+=arr[x];
        x-=lowbit(x);
    }
    return ans;
}

void solve(){
    sort(res.begin(),res.end(),cmp);
    sort(Q.begin(),Q.end(),[](const node &a,const node &b)->bool{
        return a.x<b.x;
    });
    ll tot=0;
    for(ll i=0;i<(ll)Q.size();i++){
        while(tot<(ll)res.size()&&res[tot].first<=Q[i].x){
            Add(res[tot].second,1);
            tot++;
        }
        ans[Q[i].id]+=Q[i].val*Sum(Q[i].y);
    }
    for(ll i=1;i<=m;i++){
        printf("%lld\n",ans[i]);
    }
}

int main(void){
    ll l,r;
    scanf("%lld %lld",&n,&m);
    for(ll i=1;i<=n;i++){
        scanf("%lld",&p[i].first);
        p[i].second=i;
    }
    pre_handle();
    for(ll i=1;i<=m;i++){
        scanf("%lld %lld",&l,&r);
        Q.push_back({r,r,1,i});
        Q.push_back({l-1,r,-1,i});
        Q.push_back({r,l-1,-1,i});
        Q.push_back({l-1,l-1,1,i});
    }
    solve();
    return 0;
}
