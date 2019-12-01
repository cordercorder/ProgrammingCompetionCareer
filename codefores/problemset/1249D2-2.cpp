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

const int maxn=(int)2e5+10;

struct node{
    int l;
    int r;
    int id;
}Q[maxn]; 

int n,k,maxr;
int T[maxn<<2],add[maxn<<2];

void pushdown(int rt){
    if(add[rt]>0){
        T[rt<<1]+=add[rt];
        T[rt<<1|1]+=add[rt];
        add[rt<<1]+=add[rt];
        add[rt<<1|1]+=add[rt];
        add[rt]=0;
    }
}

void ADD(int rt,int l,int r,int L,int R){
    if(L==l&&r==R){
        T[rt]+=1;
        add[rt]+=1;
        return ; 
    }
    pushdown(rt);
    int mid=(l+r)>>1;
    if(R<=mid)
        ADD(rt<<1,l,mid,L,R);
    else if(L>mid)
        ADD(rt<<1|1,mid+1,r,L,R);
    else{
        ADD(rt<<1,l,mid,L,mid);
        ADD(rt<<1|1,mid+1,r,mid+1,R);
    }
    T[rt]=max(T[rt<<1],T[rt<<1|1]);
}

int query(int rt,int l,int r,int L,int R){
    if(l==L&&R==r)
        return T[rt];
    int mid=(l+r)>>1;
    pushdown(rt);
    if(R<=mid)
        return query(rt<<1,l,mid,L,R);
    else if(L>mid)
        return query(rt<<1|1,mid+1,r,L,R);
    else
        return max(query(rt<<1,l,mid,L,mid),query(rt<<1|1,mid+1,r,mid+1,R));
}

void solve(){
    vector<int> ans;
    sort(Q+1,Q+1+n,[](const node &a,const node &b)->bool{
        if(a.r<b.r)
            return true;
        else if(a.r==b.r&&a.l<b.l)
            return true;
        return false;
    });
    for(int i=1;i<=n;i++){
        if(query(1,1,maxr,Q[i].l,Q[i].r)<k){
            ADD(1,1,maxr,Q[i].l,Q[i].r);
        }
        else{
            ans.push_back(Q[i].id);
        }
    }
    printf("%d\n",(int)ans.size());
    for(int i=0;i<(int)ans.size();i++){
        if(i>0)
            printf(" ");
        printf("%d",ans[i]);
    }
}

int main(void){
    int l,r;
    scanf("%d %d",&n,&k);
    for(int i=1;i<=n;i++){
        scanf("%d %d",&l,&r);
        maxr=max(maxr,r);
        Q[i]={l,r,i};
    }
    solve();
    return 0;
}
