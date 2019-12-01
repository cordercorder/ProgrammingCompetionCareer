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

const ll maxn=(ll)1e5+10;
const ll mod=1000000007ll;

struct node{
    ll ma[2][2];
    node(char ch){
        for(ll i=0;i<2;i++){
            for(ll j=0;j<2;j++)
                ma[i][j]=1;
        }
        if(ch=='A')
            ma[0][1]=0;
        else
            ma[1][0]=0;
    }
    node(){
        for(ll i=0;i<2;i++){
            for(ll j=0;j<2;j++)
                ma[i][j]=0;
        }
    }
    node operator*(const node &a)const{
        node ans;
        for(ll i=0;i<2;i++)
            for(ll j=0;j<2;j++)
                for(ll k=0;k<2;k++)
                    ans.ma[i][j]=(ans.ma[i][j]+ma[i][k]*a.ma[k][j])%mod;
        return ans;
    }
    void change(){
        swap(ma[0][0],ma[1][1]);
        swap(ma[0][1],ma[1][0]);
    }
}; 

ll N,Q;
char s[maxn];
node T[maxn<<2];
bool isv[maxn<<2];

void create(int rt,int l,int r){
    if(l==r){
        T[rt]=node(s[l]);
        return ;
    }
    int mid=(l+r)>>1;
    create(rt<<1,l,mid);
    create(rt<<1|1,mid+1,r);
    T[rt]=T[rt<<1]*T[rt<<1|1];
}

void pushdown(int rt){
    if(isv[rt]){
        T[rt<<1].change();
        T[rt<<1|1].change();
        isv[rt<<1]^=true;
        isv[rt<<1|1]^=true;
        isv[rt]=false;
    }
}

void update(int rt,int l,int r,int L,int R){
    if(l==L&&R==r){
        isv[rt]=isv[rt]^(true);
        T[rt].change();
        return ;
    }
    pushdown(rt);
    int mid=(l+r)>>1;
    if(R<=mid){
        update(rt<<1,l,mid,L,R);
    }
    else if(L>mid){
        update(rt<<1|1,mid+1,r,L,R);
    }
    else{
        update(rt<<1,l,mid,L,mid);
        update(rt<<1|1,mid+1,r,mid+1,R);
    }
    T[rt]=T[rt<<1]*T[rt<<1|1];
}

node query(int rt,int l,int r,int L,int R){
    if(l==L&&R==r){
        return T[rt];
    }
    pushdown(rt);
    int mid=(l+r)>>1;
    if(R<=mid){
        return query(rt<<1,l,mid,L,R);
    }
    else if(L>mid){
        return query(rt<<1|1,mid+1,r,L,R);
    }
    else{
        return query(rt<<1,l,mid,L,mid)*query(rt<<1|1,mid+1,r,mid+1,R);
    }
}

int main(void){
    ll l,r;
    ll A,B;
    ll tmp;
    scanf("%lld %lld",&N,&Q);
    scanf("%s",s+1);
    create(1,1,N);
    while(Q--){
        scanf("%lld",&tmp);
        if(tmp==1){
            scanf("%lld %lld",&l,&r);
            update(1,1,N,l,r);
        }
        else{
           scanf("%lld %lld %lld %lld",&l,&r,&A,&B);
           node res=query(1,1,N,l,r);
           ll ansA=res.ma[0][0]*A%mod+res.ma[1][0]*B%mod;
           ansA=ansA%mod;
           ll ansB=res.ma[0][1]*A%mod+res.ma[1][1]*B%mod;
           ansB=ansB%mod;
           printf("%lld %lld\n",ansA,ansB);
        }
    }
    return 0;
}
