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

const int maxn=(int)2e5+10;

char s[maxn];
int n,k;
int ans[maxn],a[maxn],tmp[maxn];

bool check(){
    for(int i=1;i<=n;i++){
        if(ans[i]>a[i]){
            return true;
        }
        else if(ans[i]<a[i]){
            return false;
        }
    }
    return true;
}

void solve(){
    for(int i=1;i<=k;i++){
        for(int j=i;j<=n;j+=k){
            ans[j]=a[i];
        }
    }
    // for(int i=1;i<=n;i++){
    //     printf("%d",ans[i]);
    // }
    // puts("");
    if(!check()){
        int i=k;
        ans[i]++;
        while(ans[i]>9){
            ans[i]=0;
            ans[i-1]++;
            i--;
        }
        for(i=1;i<=k;i++){
            for(int j=i;j<=n;j+=k){
                tmp[j]=ans[i];
            }
        }
        for(i=1;i<=n;i++)
            ans[i]=tmp[i];
    }
    printf("%d\n",n);
    for(int i=1;i<=n;i++){
        printf("%d",ans[i]);
    }

}

int main(void){
    
    scanf("%d %d",&n,&k);
    scanf("%s",s+1);
    for(int i=1;i<=n;i++){
        a[i]=(int)(s[i]-'0');
    }
    solve();
    return 0;
}