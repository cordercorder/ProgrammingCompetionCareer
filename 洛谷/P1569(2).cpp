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

const int maxn=1010;
const int inf=(int)1e9;

int a[maxn],n,sum[maxn],f[maxn];
int T[maxn<<2];

void create(int rt,int l,int r){
    T[rt]=-inf;
    if(l==r){
        return ;
    }
    int mid=(l+r)>>1;
    create(rt<<1,l,mid);
    create(rt<<1|1,mid+1,r);
}

int query(int rt,int l,int r,int L,int R){
    if(l==L&&R==r)
        return T[rt];
    int mid=(l+r)>>1;
    if(R<=mid)
        return query(rt<<1,l,mid,L,R);
    else if(L>mid)
        return query(rt<<1|1,mid+1,r,L,R);
    else
        return max(query(rt<<1,l,mid,L,mid),query(rt<<1|1,mid+1,r,mid+1,R));
}

void upd(int rt,int l,int r,int pos,int val){
    if(l==r){
        T[rt]=val;
        return ;
    }
    int mid=(l+r)>>1;
    if(pos<=mid)
        upd(rt<<1,l,mid,pos,val);
    else
        upd(rt<<1|1,mid+1,r,pos,val);
    T[rt]=max(T[rt<<1],T[rt<<1|1]);
}

void solve(){
    vector<int> id;
    id.push_back(0);
    for(int i=1;i<=n;i++){
        sum[i]=sum[i-1]+a[i];
        id.push_back(sum[i]);
    }
    if(sum[n]<0){
        puts("Impossible");
        return ;
    }
    create(1,1,n+1);
    sort(id.begin(),id.end());
    id.erase(unique(id.begin(),id.end()),id.end());
    int pos,tmp;
    pos=lower_bound(id.begin(),id.end(),0)-id.begin()+1;
    upd(1,1,n+1,pos,0);
    for(int i=1;i<=n;i++){
        pos=lower_bound(id.begin(),id.end(),sum[i])-id.begin()+1;
        tmp=query(1,1,n+1,1,pos);
        if(tmp==-inf)
            continue;
        f[i]=tmp+1;
        upd(1,1,n+1,pos,f[i]);
    }
    printf("%d\n",f[n]);
}

int main(void){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    solve();
    return 0;
}
