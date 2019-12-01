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

const int maxn=(int)5e5+10;

int n,m,ans[maxn],cnt;
pii res[maxn];
int Y[maxn],T[maxn<<2];

void Add(int rt,int l,int r,int pos,int val){
    if(l==r){
        T[rt]+=val;
        return ;
    }
    int mid=(l+r)>>1;
    int ls=rt<<1,rs=ls+1;
    if(pos<=mid){
        Add(ls,l,mid,pos,val);
    }
    else{
        Add(rs,mid+1,r,pos,val);
    }
    T[rt]=T[ls]+T[rs];
}

int query(int rt,int l,int r,int L,int R){
    if(l==L&&R==r){
        return T[rt];
    }
    int mid=(l+r)>>1;
    int ls=rt<<1,rs=ls+1;
    if(R<=mid){
        return query(ls,l,mid,L,R);
    }
    else if(L>mid){
        return query(rs,mid+1,r,L,R);
    }
    else{
        return query(ls,l,mid,L,mid)+query(rs,mid+1,r,mid+1,R);
    }
}

struct node{
    int x;
    int y;
    int id;
    int val;
}Q[maxn*4];

int main(void){
    int x,y,a,b,c,d,tot,pos1,pos2;
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%d %d",&x,&y);
        x++;
        y++;
        Y[i]=y;
        res[i]=pii(x,y);
    }
    sort(Y+1,Y+1+n);
    int len=unique(Y+1,Y+1+n)-Y-1;
    for(int i=1;i<=m;i++){
        scanf("%d %d %d %d",&a,&b,&c,&d);
        a++;
        b++;
        c++;
        d++;
        pos1=upper_bound(Y+1,Y+1+len,d)-Y-1;
        pos2=upper_bound(Y+1,Y+1+len,b-1)-Y-1;
        Q[cnt++]={c,pos1,i,1};
        Q[cnt++]={a-1,pos1,i,-1};
        Q[cnt++]={c,pos2,i,-1};
        Q[cnt++]={a-1,pos2,i,1};
    }
    sort(res+1,res+1+n,[](const pii &a,const pii &b)->bool{
        return a.first<b.first;
    });
    sort(Q,Q+cnt,[](const node &a,const node &b)->bool{
        return a.x<b.x;
    });
    tot=1;
    for(int i=0;i<cnt;i++){
        while(tot<=n&&res[tot].first<=Q[i].x){
            pos1=lower_bound(Y+1,Y+1+len,res[tot].second)-Y;
            Add(1,1,len,pos1,1);
            tot++;
        }
        if(Q[i].y!=0){
            assert(Q[i].y<=len&&Q[i].y>=1);
            ans[Q[i].id]+=Q[i].val*query(1,1,len,1,Q[i].y);
        }
    }
    for(int i=1;i<=m;i++){
        printf("%d\n",ans[i]);
    }
    return 0;
}
