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

int T,n;
int rev[maxn],cnt;
ll sum[maxn];

struct node{
    int hp;
    int cnt;
    int atk;
}res[maxn];

bool cmp(const node &a,const node &b){
    return (ll)a.cnt*(ll)b.atk<(ll)b.cnt*(ll)a.atk;
}

void pre_handle(){
    for(int i=1;;i++){
        rev[++cnt]=i*(i+1)/2;
        if(rev[i]>=100000){
            break;
        }
    }
}

void solve(){
    ll ans=0;
    int pos;
    for(int i=1;i<=n;i++){
        res[i].cnt=lower_bound(rev+1,rev+1+cnt,res[i].hp)-rev;
    }
    sort(res+1,res+1+n,cmp);
    sum[n+1]=0;
    for(ll i=n;i>=1;i--){
        sum[i]=sum[i+1]+(ll)res[i].atk;
    }
    for(int i=1;i<=n;i++){
        ans+=(ll)res[i].cnt*sum[i];
    }
    printf("%lld\n",ans);
}

int main(void){
    pre_handle();
    scanf("%d",&T);
    for(int ca=1;ca<=T;ca++){
        scanf("%d",&n);
        for(int i=1;i<=n;i++){
            scanf("%d %d",&res[i].hp,&res[i].atk);
        }
        printf("Case #%d: ",ca);
        solve();
    }
    return 0;
}
