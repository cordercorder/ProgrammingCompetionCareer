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

const int maxn=(int)1e6+10;

int n,a[maxn],b[maxn],T[maxn<<2];
int L[maxn],R[maxn];

void clr(int rt,int l,int r){
    T[rt]=0;
    if(l==r){
        return ;
    }
    int mid=(l+r)>>1;
    clr(rt<<1,l,mid);
    clr(rt<<1|1,mid+1,r);
}

void add(int rt,int l,int r,int pos){
    if(l==r){
        T[rt]++;
        return ;
    }
    int mid=(l+r)>>1;
    if(pos<=mid){
        add(rt<<1,l,mid,pos);
    }
    else{
        add(rt<<1|1,mid+1,r,pos);
    }
    T[rt]=T[rt<<1]+T[rt<<1|1];
}

int cal(int rt,int l,int r,int L,int R){
    if(l==L&&R==r){
        return T[rt];
    }
    int mid=(l+r)>>1;
    if(R<=mid){
        return cal(rt<<1,l,mid,L,R);
    }
    else if(L>mid){
        return cal(rt<<1|1,mid+1,r,L,R);
    }
    else{
        return cal(rt<<1,l,mid,L,mid)+cal(rt<<1|1,mid+1,r,mid+1,R);
    }
}

void solve(){
    sort(b+1,b+1+n);
    int len=unique(b+1,b+1+n)-b-1,pos;
    for(int i=1;i<=n;i++){
        pos=lower_bound(b+1,b+1+len,a[i])-b;
        add(1,1,len,pos);
        if(pos+1>len){
            L[i]=0;
        }
        else{
            L[i]=cal(1,1,n,pos+1,len);
        }
    }
    clr(1,1,n);
    for(int i=n;i>=1;i--){
        pos=lower_bound(b+1,b+1+len,a[i])-b;
        add(1,1,len,pos);
        if(pos-1<1){
            R[i]=0;
        }
        else{
            R[i]=cal(1,1,len,1,pos-1);
        }
    }
    ll ans=0ll;
    for(ll i=1;i<=n;i++){
        ans=ans+(ll)L[i]*(ll)R[i];
    }
    printf("%lld\n",ans);
}

int main(void){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        b[i]=a[i];
    }
    solve();
    return 0;
}
