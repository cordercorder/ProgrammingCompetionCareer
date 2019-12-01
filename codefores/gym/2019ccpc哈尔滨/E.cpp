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
 
using ll=long long;
using ull=unsigned long long;
using pii=pair<ll,ll>;
 
/*head------[@cordercorder]*/

const ll maxn=(ll)1e6+10;

ll T,n;
ll res[maxn],k[maxn];
vector<ll> cnt[maxn],num[maxn];

void handle(ll pos){
    ll sum;
    map<ll,ll> isv;
    for(ll i=0;i<k[pos];i++){
        isv[res[i]]++;
    }
    ll maxe=0;
    for(pii e:isv){
        maxe=max(maxe,e.second);
    }
    for(pii e:isv){
        if(maxe==e.second){
            num[pos].push_back(e.first);
            cnt[pos].push_back(e.second);
        }
    }
}

void Union(ll x,ll y,ll pos){
    ll i=0,j=0;
    bool f=false;
    deb(num[x]);
    deb(num[y]);
    while(i<(ll)num[x].size()&&j<(ll)num[y].size()){
        if(num[x][i]<num[y][j]){
            i++;
        }
        else if(num[x][i]>num[y][j]){
            j++;
        }
        else{
            cnt[pos].push_back(cnt[x][i]+cnt[y][j]);
            num[pos].push_back(num[x][i]); 
            i++;
            j++;
            f=true;
        }
    }
    if(!f){
        if(cnt[x][0]>cnt[y][0]){
            swap(x,y);
        }
        if(cnt[x][0]==cnt[y][0]){
            i=0;
            j=0;
            while(i<(ll)num[x].size()&&j<(ll)num[y].size()){
                if(num[x][i]<num[y][i]){
                    num[pos].push_back(num[x][i]);
                    cnt[pos].push_back(cnt[x][i]);
                    i++;
                }
                else{
                    num[pos].push_back(num[y][j]);
                    cnt[pos].push_back(cnt[y][j]);
                    j++;
                }
            }
            while(i<(ll)num[x].size()){
                num[pos].push_back(num[x][i]);
                cnt[pos].push_back(cnt[x][i]);
                i++;
            }
            while(j<(ll)num[y].size()){
                num[pos].push_back(num[y][j]);
                cnt[pos].push_back(cnt[y][j]);
                j++;
            }
        }
        else{
            cnt[pos]=cnt[y];
            num[pos]=num[y];
        }
    }
}

void solve(){
    ll len=k[n];
    ll x=cnt[n][0];
    ll ans;
    if(x*2ll<=len){
        ans=len;
    }
    else{
        ans=2ll*(len-x);
    }
    printf("%lld\n",ans);
}

int main(void){
    ll tmp,x,y;
    scanf("%lld",&T);
    while(T--){
        scanf("%lld",&n);
        for(ll i=1;i<=n;i++){
            scanf("%lld",&tmp);
            if(tmp==1ll){
                scanf("%lld",&k[i]);
                for(ll j=0;j<k[i];j++){
                    scanf("%lld",&res[j]);
                }
                handle(i);
            }
            else{
                scanf("%lld %lld",&x,&y);
                Union(x,y,i);
                k[i]=k[x]+k[y];
            }
        }
        puts("start");
        for(ll e:num[n]){
            printf("%lld ",e);
        }
        puts("");
        for(ll e:cnt[n]){
            printf("%lld ",e);
        }
        puts("");
        puts("end");
        solve();
        for(ll i=1;i<=n;i++){
            cnt[i].clear();
            num[i].clear();
        }
    }
    return 0;
}
