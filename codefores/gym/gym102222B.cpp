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

const int maxn=55;

int T;
int n;
double x[maxn],y[maxn],qx,qy;

double dot(double xx1,double yy1,double xx2,double yy2){
    return xx1*xx2+yy1*yy2;
}

double len(double xx1,double yy1,double xx2,double yy2){
    double ans=(xx2-xx1)*(xx2-xx1)+(yy2-yy1)*(yy2-yy1);
    ans=sqrt(ans);
    return ans;
}

void solve(){
    double ret,res,angle,r,ans=0;
    for(int i=1;i<=n;i++){
        ret=dot(x[i%n+1]-x[i],y[i%n+1]-y[i],x[(i+1)%n+1]-x[i%n+1],y[(i+1)%n+1]-y[i%n+1]);
        res=len(x[i%n+1],y[i%n+1],x[i],y[i])*len(x[(i+1)%n+1],y[(i+1)%n+1],x[i%n+1],y[i%n+1]);
        angle=ret/res;
        angle=acos(angle);
        r=len(x[i%n+1],y[i%n+1],qx,qy);
        ans+=angle*r;
    }
    printf("%.3f\n",ans);
}

int main(void){
    scanf("%d",&T);
    for(int ca=1;ca<=T;ca++){
        scanf("%d",&n);
        for(int i=1;i<=n;i++){
            scanf("%lf %lf",&x[i],&y[i]);
        }
        scanf("%lf %lf",&qx,&qy);
        printf("Case #%d: ",ca);
        solve();
    }
    return 0;
}
