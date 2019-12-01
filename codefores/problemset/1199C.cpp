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

const int maxn=(int)4e5+10;

int n,I;
int a[maxn],b[maxn];
map<int,int> cnt;

int cal(int x){
    int ans=1;
    int i;
    for(i=0;ans<x;i++){
        ans=ans*2;
    }
    return i;
}

void solve(){
    I=I*8; 
    int ans=n+1,sum=0,posl,posr;
    sort(b+1,b+1+n);
    int r=0;
    for(int l=1;l<=n;l++){
        while(r<n&&cal(sum)*n<=I){
            r++;
            if(cnt[b[r]]==0){
                sum++;
            }
            cnt[b[r]]++;
            if(cal(sum)*n<=I){
                posl=lower_bound(b+1,b+1+n,b[l])-b-1;
                posr=upper_bound(b+1,b+1+n,b[r])-b;
                posr=n-posr+1;
//                deb(l,r,sum,posl,posr,b[r]);
                ans=min(ans,posl+posr);
            }
        }
        cnt[b[l]]--;
        if(cnt[b[l]]==0){
            sum--;
        }
    }
    printf("%d\n",ans);
}

int main(void){
    scanf("%d %d",&n,&I);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
        b[i]=a[i];
    }
    solve();
    return 0;
}
