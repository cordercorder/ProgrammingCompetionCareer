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

const int maxn=(int)1e5+10;
const double inf=1e18;

struct node{
    double x;
    double y;
};
node res[maxn],tmp[maxn];
int n;

bool cmpx(const node &a,const node &b){
    return a.x<b.x;
}

bool cmpy(const node &a,const node &b){
    return a.y<b.y;
}

double dis(const node &a,const node &b){
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}

double Conquer(int l,int r){
    if(l==r){
        return inf;
    }
    int mid=(l+r)>>1;
    double d1=Conquer(l,mid);
    double d2=Conquer(mid+1,r);
    double x=res[mid].x;
    d1=min(d1,d2);
    int cnt=0;
    for(int i=l;i<=r;i++){
        if(abs(res[i].x-x)<d1){
            tmp[++cnt]=res[i];
        }
    }
    sort(tmp+1,tmp+1+cnt,cmpy);
    for(int i=1;i<=cnt;i++){
        for(int j=i+1;j<=cnt;j++){
            if(abs(tmp[i].y-tmp[j].y)>=d1)
                break;
            d1=min(d1,dis(tmp[i],tmp[j]));
        }
    }
    return d1;
}

void solve(){
    sort(res+1,res+1+n,cmpx);
    printf("%.2f\n",Conquer(1,n)/2.0);
}

int main(void){
    while(scanf("%d",&n)!=EOF){
        if(n==0)
            break;
        for(int i=1;i<=n;i++){
            scanf("%lf %lf",&res[i].x,&res[i].y);
        }
        solve();
    }
    return 0;
}
