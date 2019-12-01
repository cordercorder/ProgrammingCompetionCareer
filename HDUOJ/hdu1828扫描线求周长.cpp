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

const int maxn=5100*2;

int n;
struct node{
    int l;
    int r;
    int h;
    int d;
    bool operator<(const node &a)const{//注意有重边的情况 
        if(h<a.h){
            return true;
        }
        else if(h==a.h&&d>a.d){
            return true;
        }
        return false;
    }
    
}res[maxn],resy[maxn];

int x[maxn],cnt,tot,y[maxn],cnt1,tot1;
int add[maxn<<2],len[maxn<<2];
bool f;

void pushup(int rt,int l,int r){
    if(add[rt]){
        if(f){
            len[rt]=x[r+1]-x[l];
        }
        else{
            len[rt]=y[r+1]-y[l];
        }
    }
    else{
        if(l==r){
            len[rt]=0;
        }
        else{
            len[rt]=len[rt<<1]+len[rt<<1|1];
        }
    }
}

void update(int rt,int l,int r,int L,int R,int d){
    if(l==L&&R==r){
        add[rt]+=d;
        pushup(rt,l,r);
        return ;
    }
    int mid=(l+r)>>1;
    if(R<=mid){
        update(rt<<1,l,mid,L,R,d);
    }
    else if(L>mid){
        update(rt<<1|1,mid+1,r,L,R,d);
    }
    else{
        update(rt<<1,l,mid,L,mid,d);
        update(rt<<1|1,mid+1,r,mid+1,R,d);
    }
    pushup(rt,l,r);
}

int main(void){
    int x1,y1,x2,y2;
    int l,r,ans,lst;
    while(scanf("%d",&n)!=EOF){
        cnt=0;
        tot=0;
        lst=0;
        ans=0;
        cnt1=0;
        tot1=0;
        for(int i=1;i<=n;i++){
            scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
            x[tot++]=x1;
            x[tot++]=x2;
            y[tot1++]=y1;
            y[tot1++]=y2;
            res[cnt++]={x1,x2,y1,1};
            res[cnt++]={x1,x2,y2,-1};
            resy[cnt1++]={y1,y2,x1,1};
            resy[cnt1++]={y1,y2,x2,-1};
        }
        sort(res,res+cnt);
        sort(x,x+tot);
        tot=unique(x,x+tot)-x;
        f=true;
        for(int i=0;i<cnt;i++){
            l=lower_bound(x,x+tot,res[i].l)-x;
            r=lower_bound(x,x+tot,res[i].r)-x-1;
            update(1,0,tot-1,l,r,res[i].d);
            ans+=abs(len[1]-lst);
            lst=len[1];
        }
        sort(resy,resy+cnt1);
        sort(y,y+tot1);
        tot1=unique(y,y+tot1)-y;
        lst=0;
        f=false;
        for(int i=0;i<cnt1;i++){
            l=lower_bound(y,y+tot1,resy[i].l)-y;
            r=lower_bound(y,y+tot1,resy[i].r)-y-1;
            update(1,0,tot1-1,l,r,resy[i].d);
            ans+=abs(len[1]-lst);
            lst=len[1];
        }
        printf("%d\n",ans);
    }
    return 0;
}
