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

ll n,p,w,d;

ll exgcd(ll a,ll b,ll &x,ll &y){
	if(b==0){
		x=1;
		y=0;
		return a;
	}
	ll d=exgcd(b,a%b,x,y);
	ll tmp=x;
	x=y;
	y=tmp-a/b*y;
	return d;
}

void solve(){
    ll nw=w,nd=d,x,y,d1,d2;
    ll tmp=__gcd(nw,nd);
    if(p%tmp!=0){
        puts("-1");
        return ;
    }
    exgcd(nw,nd,x,y);
    d1=nd/tmp;
    d2=nw/tmp;
    x=(x%d1+d1)%d1;
    y=(tmp-nw*x)/nd;
    x*=p/tmp;
    y*=p/tmp;
    while(true){
        if(y>=0){
            if(n-x-y>=0){
                printf("%lld %lld %lld",x,y,n-x-y);
                return ;
            }
        }
        else{
            break;
        }
        x+=d1;
        y-=d2;
    }
    puts("-1");
}

int main(void){
    scanf("%lld %lld %lld %lld",&n,&p,&w,&d);
    if(p==0){
        printf("0 0 %lld\n",n);
        return 0;
    }
    solve();
    return 0;
}
