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

const ll maxn=1010;

ll T,Q;
ll arr[maxn][maxn];

ll lowbit(ll x){
    return x&(-x);
}

ll query(ll x,ll y){
    ll ans=0;
    for(ll i=x;i>0;i-=lowbit(i)){
        for(ll j=y;j>0;j-=lowbit(j))
            ans+=arr[i][j];
    }
    return ans;
}

void add(ll x,ll y,ll val){
    for(ll i=x;i<=1001;i+=lowbit(i)){
        for(ll j=y;j<=1001;j+=lowbit(j)){
            arr[i][j]+=val;
        }
    }
}

void del(ll x,ll y,ll val){
    for(ll i=x;i<=1001;i+=lowbit(i)){
        for(ll j=y;j<=1001;j+=lowbit(j)){
            arr[i][j]-=min(arr[i][j],val);
        }
    }
}

int main(void){
    char ch[10];
    ll l1,r1,l2,r2,ans,num,tmp;
    scanf("%lld",&T);
    for(ll ca=1;ca<=T;ca++){
        scanf("%lld",&Q);
        for(ll i=1;i<=1001;i++){
            for(ll j=1;j<=1001;j++)
                add(i,j,1);
        }
        printf("Case %lld:\n",ca);
        while(Q--){
            scanf("%s",ch);
            if(ch[0]=='S'){
                scanf("%lld %lld %lld %lld",&l1,&r1,&l2,&r2);
                l1++;
                r1++;
                l2++;
                r2++;
                
                ll tmpl1,tmpl2,tmpr1,tmpr2;
                tmpl1=min(l1,l2);
                tmpr1=min(r1,r2);
                
                tmpl2=max(l1,l2);
                tmpr2=max(r1,r2);
                l1=tmpl1;
                l2=tmpl2;
                r1=tmpr1;
                r2=tmpr2; 
                ans=query(l2,r2)-query(l1-1,r2)-query(l2,r1-1)+query(l1-1,r1-1);
                printf("%lld\n",ans);
            }
            else if(ch[0]=='A'){
                scanf("%lld %lld %lld",&l1,&r1,&num);
                l1++;
                r1++;
                add(l1,r1,num);
            }
            else if(ch[0]=='D'){
                scanf("%lld %lld %lld",&l1,&r1,&num);
                l1++;
                r1++;
                tmp=query(l1,r1)-query(l1-1,r1)-query(l1,r1-1)+query(l1-1,r1-1);
                tmp=min(tmp,num);
                del(l1,r1,tmp);
            }
            else{
                scanf("%lld %lld %lld %lld %lld",&l1,&r1,&l2,&r2,&num);
                l1++;
                r1++;
                l2++;
                r2++;
                tmp=query(l1,r1)-query(l1-1,r1)-query(l1,r1-1)+query(l1-1,r1-1);
                tmp=min(tmp,num);
                del(l1,r1,tmp);
                add(l2,r2,tmp);
            }
        }
        memset(arr,0,sizeof(arr));
    }
    return 0;
}
