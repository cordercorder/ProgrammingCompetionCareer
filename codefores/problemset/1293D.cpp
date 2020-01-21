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
using pii=pair<int,int>;

/*head------[@cordercorder]*/

ll x0,y0,ax,ay,bx,by;
ll xs,ys,t;

struct node{
    ll x;
    ll y;
};
vector<node> res;

void datanodes(){
    ll x=x0,y=y0;
    ll detax,detay;
    res.push_back({x,y});
    while(true){
        x=ax*x+bx;
        y=ay*y+by;
        detax=abs(x-xs);
        detay=abs(y-ys);
        // deb(detax,detay);
        if((x>xs||y>ys)&&(detax>t||detay>t||detax+detay>t))
            break;
        res.push_back({x,y});
    }
}

void solve(){
    datanodes();
    // deb(res.size());
    // for(auto item:res){
    //     deb(item.x,item.y);
    // }
    ll ans=0;
    ll sum;
    for(ll i=0;i<(ll)res.size();i++){
        for(ll j=i;j<(ll)res.size();j++){
            sum=abs(res[j].x-res[i].x)+abs(res[j].y-res[i].y);
            ll tmp1=0,tmp2=0;
            for(ll k=i;k<=j;k++){
                tmp1=abs(res[j].x-res[k].x)+abs(res[j].y-res[k].y)+sum;
                tmp2=abs(res[k].x-res[i].x)+abs(res[k].y-res[i].y)+sum;
                if(min(tmp1,tmp2)+abs(res[k].x-xs)+abs(res[k].y-ys)<=t){
                    // deb(tmp1,tmp2,sum);
                    ans=max(ans,j-i+1);
                }
            }
        }
    }
    printf("%lld\n",ans);
}

int main(void){
    scanf("%lld %lld %lld %lld %lld %lld",&x0,&y0,&ax,&ay,&bx,&by);
    scanf("%lld %lld %lld",&xs,&ys,&t);
    solve();
    return 0;
}