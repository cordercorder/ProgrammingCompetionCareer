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
const long double eps=(long double)1e-10;
 
using ll=long long;
using ull=unsigned long long;
using pii=pair<int,int>;
 
/*head------[@cordercorder]*/

const ll maxn=(ll)1e5+10ll;

struct node{
    ll L;
    ll W;
    ll area;
}rec[maxn];

struct Node{
    long double l;
    long double r;
};

ll N;

ll sign(long double x){
    if(x>eps)
        return 1;
    else if(x<-eps)
        return -1;
    return 0;
}

bool check(ll x){
    for(ll i=1;i<=N;i++){
        if(rec[i].area>=x)
            return true;
    }
    vector<ll> pos;
    for(ll i=1;i<=N;i++){
        if(2ll*rec[i].area>=x){
            pos.push_back(i);
        }
    }
    long double half=(long double)x/(long double)2.0;
    Node now;
    vector<Node> ls;
    for(ll id:pos){
        now.r=rec[id].L;
        now.l=half/(long double)rec[id].W;
        ls.push_back(now);
//        printf("%.6f %.6f\n",now.l,now.r);
    }
    sort(ls.begin(),ls.end(),[](const Node &a,const Node &b)->bool{
        ll x=sign(a.l-b.l);
        if(x==-1)
            return true;
        else if(x==0){
            return sign(a.r-b.r)==-1;
        }
        else
            return false;
    });
    for(ll i=0;i+1<(ll)ls.size();i++){
        if(sign(ls[i+1].l-ls[i].r)<=0){
//            deb(ls[i+1].l-ls[i].r);
//            deb(sign(ls[i+1].l-ls[i].r));
//            printf("%.6f %.6f\n",ls[i].r,ls[i+1].l);
            return true;
        }
    }
    return false;
}

void solve(){
    ll l=0,r=(ll)2e18+10,mid;
    while(l<r){
        mid=(l+r)>>1;
        if(check(mid)){
            l=mid+1;
        }
        else{
            r=mid;
        }
    }
    l--;
    if(l%2==0){
        printf("%lld.0\n",l/2ll);
    }
    else{
        printf("%lld.5\n",l/2ll);
    }
}

int main(void){
    scanf("%lld",&N);
    for(ll i=1;i<=N;i++){
        scanf("%lld %lld",&rec[i].L,&rec[i].W);
        if(rec[i].L>rec[i].W){
            swap(rec[i].L,rec[i].W);
        }
        rec[i].area=rec[i].L*rec[i].W;
    }
    solve();
    return 0;
}
