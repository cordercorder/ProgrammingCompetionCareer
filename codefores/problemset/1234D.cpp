#include<bits/stdc++.h>
#pragma GCC optimize ("O2")

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

int T[maxn<<2];

char s[maxn];
int q,n;

void create(int rt,int l,int r){
    if(l==r){
        int x=(int)(s[l]-'a');
        T[rt]|=(1<<x);
        return ;
    }
    int ls=rt<<1,rs=rt<<1|1;
    int mid=(l+r)>>1;
    create(ls,l,mid);
    create(rs,mid+1,r);
    T[rt]=T[ls]|T[rs];
}

void update(int rt,int l,int r,int pos,char now,char pre){
    if(l==r){
        int x=(int)(pre-'a');
        T[rt]^=(1<<x);
        x=(int)(now-'a');
        T[rt]|=(1<<x);
        return ;
    }
    int ls=rt<<1,rs=rt<<1|1;
    int mid=(l+r)>>1;
    if(pos<=mid){
        update(ls,l,mid,pos,now,pre);
    }
    else{
        update(rs,mid+1,r,pos,now,pre);
    }
    T[rt]=T[ls]|T[rs];
}

int cal(int rt,int l,int r,int L,int R){
    if(l==L&&R==r){
        return T[rt];
    }
    int ls=rt<<1,rs=rt<<1|1;
    int mid=(l+r)>>1;
    if(R<=mid){
        return cal(ls,l,mid,L,R);
    }
    else if(L>mid){
        return cal(rs,mid+1,r,L,R);
    }
    else{
        return cal(ls,l,mid,L,mid)|cal(rs,mid+1,r,mid+1,R);
    }
} 

int main(void){
    int tmp,pos;
    int l,r;
    char ch[10];
    scanf("%s",s+1);
    n=strlen(s+1);
    create(1,1,n);
    scanf("%d",&q);
    while(q--){
        scanf("%d",&tmp);
        if(tmp==1){
            scanf("%d %s",&pos,ch);
            update(1,1,n,pos,ch[0],s[pos]);
            s[pos]=ch[0];
        } 
        else{
            int ans=0,res;
            scanf("%d %d",&l,&r);
            res=cal(1,1,n,l,r);
            while(res>0){
                if(res&1){
                    ans++;
                }
                res>>=1;
            }
            printf("%d\n",ans);
        }
    }
    return 0;
}
