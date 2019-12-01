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

const int maxn=(int)3e5+10;
const int inf=(int)1e9;

int n,a[maxn],ans[maxn];
int T[maxn<<2][2];

struct node{
    int to;
    int w;
};
vector<node> e[maxn];
bool isv[maxn];

void create(int rt,int l,int r){
    if(l==r){
        T[rt][0]=a[l];
        T[rt][1]=a[l];
        return ;
    }
    int mid=(l+r)>>1;
    create(rt<<1,l,mid);
    create(rt<<1|1,mid+1,r);
    T[rt][0]=max(T[rt<<1][0],T[rt<<1|1][0]);
    T[rt][1]=min(T[rt<<1][1],T[rt<<1|1][1]);
}

int Find(int rt,int l,int r,int val){
    if(T[rt][1]>val)
        return inf;
    if(l==r){
        return l;
    }
    int mid=(l+r)>>1;
    if(T[rt<<1][1]<=val)
        return Find(rt<<1,l,mid,val);
    return Find(rt<<1|1,mid+1,r,val);
}

int cal_pos(int rt,int l,int r,int L,int R,int val){
    if(T[rt][1]>val)
        return inf;
    if(l==L&&R==r){
        return Find(rt,l,r,val);
    }
    int mid=(l+r)>>1;
    if(R<=mid){
        return cal_pos(rt<<1,l,mid,L,R,val);
    }
    else if(L>mid){
        return cal_pos(rt<<1|1,mid+1,r,L,R,val);
    }
    else{
        return min(cal_pos(rt<<1,l,mid,L,mid,val),cal_pos(rt<<1|1,mid+1,r,mid+1,R,val));
    }
}

int Find_max_pos(int rt,int l,int r,int val){
    if(T[rt][0]<=val)
        return inf;
    if(l==r)
        return l;
    int mid=(l+r)>>1;
    if(T[rt<<1][0]>val)
        return Find_max_pos(rt<<1,l,mid,val);
    return Find_max_pos(rt<<1|1,mid+1,r,val);
}

int cal_max_pos(int rt,int l,int r,int L,int R,int val){
    if(T[rt][0]<=val)
        return inf;
    if(l==L&&R==r){
        return Find_max_pos(rt,l,r,val);
    }
    int mid=(l+r)>>1;
    if(R<=mid){
        return cal_max_pos(rt<<1,l,mid,L,R,val);
    }
    else if(L>mid){
        return cal_max_pos(rt<<1|1,mid+1,r,L,R,val);
    }
    else{
        return min(cal_max_pos(rt<<1,l,mid,L,mid,val),cal_max_pos(rt<<1|1,mid+1,r,mid+1,R,val));
    }
}

int cal_max(int rt,int l,int r,int L,int R){
    if(l==L&&R==r)
        return T[rt][0];
    int mid=(l+r)>>1;
    if(R<=mid)
        return cal_max(rt<<1,l,mid,L,R);
    else if(L>mid)
        return cal_max(rt<<1|1,mid+1,r,L,R);
    else
        return max(cal_max(rt<<1,l,mid,L,mid),cal_max(rt<<1|1,mid+1,r,mid+1,R));
}

void dfs(int u){
    isv[u]=true;
    for(node E:e[u]){
        int v=E.to;
        int w=E.w;
        if(!isv[v]){
            ans[v]=ans[u]+w;
            dfs(v);
        }
    }
}

void solve(){
    int pos,tmp;
    vector<int> S;
    create(1,1,3*n);
    for(int i=1;i<=n;i++){
        if(a[i]%2==1){
            tmp=a[i]/2;
        }
        else{
            tmp=a[i]/2-1;
        }
        pos=cal_pos(1,1,3*n,i,3*n,tmp);
        if(pos!=inf){
            if(cal_max(1,1,3*n,i,pos)<=a[i]){
                ans[i]=pos-i;
                ans[i+n]=ans[i];
                ans[i+n+n]=ans[i];
                S.push_back(i);
            }
        }
        if(ans[i]==0){
            pos=cal_max_pos(1,1,3*n,i,3*n,a[i]);
            int v=(pos-1)%n+1;
            e[v].push_back({i,pos-i});
            e[i].push_back({v,pos-i});
        }
    }
    for(int x:S){
        dfs(x);
    }
    for(int i=1;i<=n;i++){
        if(i>1)
            printf(" ");
        printf("%d",ans[i]);
    }
}

int main(void){
    int mine=inf+10,maxe=0;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        mine=min(mine,a[i]);
        maxe=max(maxe,a[i]);
        a[i+n]=a[i];
        a[i+n+n]=a[i];
    }
    if(maxe%2==1)
        maxe=maxe/2;
    else
        maxe=maxe/2-1;
    if(mine>maxe){
        for(int i=1;i<=n;i++){
            if(i>1)
                printf(" ");
            printf("-1");
        }
        return 0;
    }
    solve();
    return 0;
}
