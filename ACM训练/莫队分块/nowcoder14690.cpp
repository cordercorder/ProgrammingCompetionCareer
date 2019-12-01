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

const int maxn=(int)5e4+10;

struct node{
    int l;
    int r;
    int id; 
}Q[maxn];

int T;
int n,q,k;
int a[maxn],block,sum[maxn],b[maxn],len,cnt[maxn],belong[maxn];
ll ans[maxn];

bool cmp(const node &a,const node &b){
    int x1=a.l/block,x2=b.l/block;
    if(x1<x2){
        return true;
    }
    else if(x1==x2&&a.r<b.r){
        return true;
    }
    return false;
}

int getid(int x){
    int pos=lower_bound(b,b+1+len,x)-b;
    return pos;
}

void solve(){
    sort(Q+1,Q+1+q,cmp);
    for(int i=0;i<=n;i++){
        b[i]=sum[i];
    }
    sort(b,b+n+1);
    len=unique(b,b+n+1)-b-1;
    for(int i=0;i<=n;i++){
        belong[i]=getid(sum[i]);
    }
    int L=0,R=-1,pos;
    ll S=0ll;
    for(int i=1;i<=q;i++){
        while(R<Q[i].r){
            R++;
            pos=belong[R];
            S+=(ll)cnt[pos];
            cnt[pos]++;
        }
        while(R>Q[i].r){
            pos=belong[R];
            S+=(-1ll*cnt[pos]+1ll);
            cnt[pos]--;
            R--;
        }
        while(L<Q[i].l){
            pos=belong[L];
            S+=(-1ll*cnt[pos]+1ll);
            cnt[pos]--;
            L++;
        }
        while(L>Q[i].l){
            L--;
            pos=belong[L];
            S+=(ll)cnt[pos];
            cnt[pos]++;
        }
//        deb(cnt[0],cnt[1],Q[i].l,Q[i].r);
        ans[Q[i].id]=S;
    }
    for(int i=1;i<=q;i++){
        printf("%lld\n",ans[i]);
    }
    for(int i=0;i<=len;i++){
        cnt[i]=0;
    }
}

int main(void){
    int l,r;
    scanf("%d",&T);
    while(T--){
        scanf("%d %d %d",&n,&q,&k);
        block=(int)(sqrt(n));
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i]);
            sum[i]=sum[i-1]+a[i];
            sum[i]=sum[i]%k;
        }
        for(int i=1;i<=q;i++){
            scanf("%d %d",&Q[i].l,&Q[i].r);
            Q[i].l--;
            Q[i].id=i;
        }
        solve();
    }
    return 0;
}
