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

ll T;
ll x,y;

int main(void){
    scanf("%lld",&T);
    while(T--){
        scanf("%lld %lld",&x,&y);
        if(y<=x){
            puts("YES");
            continue;
        }
        else{
            if(x%2==1){
                x--;
            }
            map<ll,bool> isv;
            isv[x]=true;
            while(x>0){
                if(x%2==0){
                    x=x/2ll*3ll;
                }
                else{
                    x--;
                }
                if(x>=y)
                    break;
                if(isv[x])
                    break;
                isv[x]=true;
            }
            if(x>=y){
                puts("YES");
            }
            else{
                puts("NO");
            }
        }
    }
    return 0;
}
