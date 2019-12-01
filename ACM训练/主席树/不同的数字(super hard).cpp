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

const int maxn=(int)1e5+10;

namespace PT{
    
    const int maxn=(int)1e5+10;
    
    int root[maxn],cnt;
    
    struct node{
    	int l;
    	int r;
    	int sum;
    }T[maxn*50];
    
    void Init(){
        cnt=0;
        root[0]=0;
    }
    
    void update(int l,int r,int &x,int y,int pos,int val){
    	T[++cnt]=T[y];
    	T[cnt].sum+=val;
    	x=cnt;
    	if(l==r){
    		return ;
    	}
    	int mid=(l+r)>>1;
    	if(pos<=mid){
    		update(l,mid,T[x].l,T[y].l,pos,val);
    	}
    	else{
    		update(mid+1,r,T[x].r,T[y].r,pos,val);
    	}
    }
    
    //在线求区间内不同的数的个数：从头到尾添加到主席树
    //如果此数之前出现过就先减去，接着再加，最后在区间(l,r)中找到root[r]这个历史版本
    int queryN(int l,int r,int rt,int L,int R){
        if(l==L&&R==r){
            return T[rt].sum;
        }
        int mid=(l+r)>>1;
        if(R<=mid){
            return queryN(l,mid,T[rt].l,L,R);
        }
        else if(L>mid){
            return queryN(mid+1,r,T[rt].r,L,R);
        }
        else{
            return queryN(l,mid,T[rt].l,L,mid)+queryN(mid+1,r,T[rt].r,mid+1,R);
        }
    }
    
}

int n,m,a[maxn],pre[1000010];
int lastans=1,d;

int main(void){
    int l,r,pos,lst;
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    for(int i=1;i<=1000000;i++){
        pre[i]=-1;
    }
    PT::Init();
    for(int i=1;i<=n;i++){
        if(pre[a[i]]==-1){
            PT::update(1,n,PT::root[i],PT::root[i-1],i,1);
        }
        else{
            PT::update(1,n,lst,PT::root[i-1],pre[a[i]],-1);
            PT::update(1,n,PT::root[i],lst,i,1);
        }
        pre[a[i]]=i;
    }
    while(m--){
        scanf("%d",&d);
        l=lastans;
        r=min(l+d,n);
//        deb(l,r);
        lastans=PT::queryN(1,n,PT::root[r],l,r);
        printf("%d\n",lastans);
    }
    return 0;
}
