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

const int N=(int)1e5+10;
const int maxn=N*2;

int n;
struct node{
    int l;
    int r;
    int h;
    int d;
    bool operator<(const node &a)const{
        return h<a.h;
    }
};
node res[maxn];
int cnt;
vector<int> x;
int add[maxn<<2],T[maxn<<2];

void pushup(int rt,int l,int r){
    if(add[rt]==0){
        if(l==r){
            T[rt]=0;
        }
        else{
            T[rt]=T[rt<<1]+T[rt<<1|1];
        }
    }
    else{
        T[rt]=x[r+1]-x[l];
    }
}

void update(int rt,int l,int r,int L,int R,int val){
    if(l==L&&r==R){
        add[rt]+=val;
        pushup(rt,l,r);
        return ;
    }
    int mid=(l+r)>>1;
    if(R<=mid){
        update(rt<<1,l,mid,L,R,val);
    }
    else if(L>mid){
        update(rt<<1|1,mid+1,r,L,R,val);
    }
    else{
        update(rt<<1,l,mid,L,mid,val);
        update(rt<<1|1,mid+1,r,mid+1,R,val);
    }
    pushup(rt,l,r);
}

void solve(){
    sort(x.begin(),x.end());
    sort(res,res+cnt);
    int len=unique(x.begin(),x.end())-x.begin(),xx,yy;
    ll ans=0ll;
    for(int i=0;i<cnt;i++){
        xx=lower_bound(x.begin(),x.begin()+len,res[i].l)-x.begin();
        yy=lower_bound(x.begin(),x.begin()+len,res[i].r)-x.begin()-1;
        update(1,0,len-1,xx,yy,res[i].d);
        ans+=(ll)T[1]*(ll)(res[i+1].h-res[i].h);
    }
    printf("%lld\n",ans);
}

int main(void){
    int x1,x2,y1,y2;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
        if(x1==x2){
            if(y1>y2){
                swap(y1,y2);
            }
            res[cnt++]={x1,x1+1,y1,1};
            res[cnt++]={x1,x1+1,y2+1,-1};
            x.push_back(x1);
            x.push_back(x1+1);
        }
        else if(y1==y2){
            if(x1>x2){
                swap(x1,x2);
            }
            res[cnt++]={x1,x2+1,y1,1};
            res[cnt++]={x1,x2+1,y1+1,-1};
            x.push_back(x1);
            x.push_back(x2+1);
        }
    }
    solve();
    return 0;
}
