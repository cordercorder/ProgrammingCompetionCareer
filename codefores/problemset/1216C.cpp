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

struct node{
    ll x;
    ll y;
    node():x(0),y(0){}
};
node p[6];

node* Union(const node &p1,const node &p2,const node &p3,const node &p4){
    node *ans=new node[2];
    ll left,right,up,down;
    left=max(p1.x,p3.x);
    right=min(p2.x,p4.x);
    up=min(p2.y,p4.y);
    down=max(p1.y,p3.y);
    if(left<=right&&down<=up){
        ans[0].x=left;
        ans[0].y=down;
        ans[1].x=right;
        ans[1].y=up;
    }
    return ans;
}

ll cal(node *rec){
    ll ans=(rec[1].x-rec[0].x)*(rec[1].y-rec[0].y);
    return ans;
}

void solve(){
    node *rec1=Union(p[2],p[3],p[0],p[1]);
    node *rec2=Union(p[4],p[5],p[0],p[1]);
    node *rec3=Union(rec1[0],rec1[1],rec2[0],rec2[1]);
    ll sum=(p[1].x-p[0].x)*(p[1].y-p[0].y);
    if(sum>cal(rec1)+cal(rec2)-cal(rec3)){
        puts("YES");
    }
    else{
        puts("NO");
    }
}

int main(void){
    for(int i=0;i<6;i++){
        scanf("%lld %lld",&p[i].x,&p[i].y);
    }
    solve();
    return 0;
}
