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

const ll maxn=(ll)1e5+10ll;

ll a[maxn],N,n;
ll cnt[70],len;
ll dis[210][210],ma[210][210];

void handle(ll x){
    ll tmp,tot=0;
    for(tmp=x;tmp>0;tmp/=2){
        if(tmp%2==1){
            cnt[tot++]++;
        }
        else{
            tot++;
        }
    }
}

void solve(){
    for(ll i=1;i<=n;i++){
        handle(a[i]);
    }
    vector<ll> id;
    for(ll i=0;i<64;i++){
        if(cnt[i]>=3){
            puts("3");
            return ;
        }
    }
    for(ll i=1;i<=n;i++){
        id.push_back(a[i]);
    }
    sort(id.begin(),id.end());
    id.erase(unique(id.begin(),id.end()),id.end());
    len=(ll)id.size();
    ll u,v;
    for(ll i=1;i<=len;i++){
        for(ll j=1;j<=len;j++){
            ma[i][j]=(ll)1e10;
            dis[i][j]=(ll)1e10;
        }
    }
    for(ll i=1;i<=n;i++){
        for(ll j=i+1;j<=n;j++){
            if((a[i]&a[j])>0){
                u=lower_bound(id.begin(),id.end(),a[i])-id.begin();
                v=lower_bound(id.begin(),id.end(),a[j])-id.begin();
                ma[u+1][v+1]=1;
                ma[v+1][u+1]=1;
                dis[u+1][v+1]=1;
                dis[v+1][u+1]=1;
            }
        }
    }
    ll ans=(ll)1e10;
    for(ll ii=1;ii<=len;ii++){
        for(ll i=1;i<=len;i++){
            for(ll j=i+1;j<=len;j++){
                ans=min(ans,dis[i][j]+ma[i][ii]+ma[ii][j]);
            }
        }
        for(ll i=1;i<=len;i++){
            for(ll j=1;j<=len;j++){
                dis[i][j]=min(dis[i][j],dis[i][ii]+dis[ii][j]);
            }
        }
    }
    if(ans==(ll)1e10){
        puts("-1");
    }
    else{
        printf("%lld\n",ans);
    }
}

int main(void){
    ll tmp;
    scanf("%lld",&N);
    for(ll i=1;i<=N;i++){
        scanf("%lld",&tmp);
        if(tmp>0){
            a[++n]=tmp;
        }
    }
    solve();
    return 0;
}
