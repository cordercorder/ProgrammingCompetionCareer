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

const int maxn=2010;

int n;
char s[maxn][100];
int f[maxn],len[maxn];

bool check(int posx,int posy){
    int i=0;
    for(;i<=len[posx]&&i<=len[posy];i++){
        if(s[posx][i]!=s[posy][i])
            return false;
    }
    return i==(len[posy]+1);
}

void solve(){
    for(int i=1;i<=n;i++){
        f[i]=1;
        for(int j=1;j<i;j++){
            if(check(i,j)){
                f[i]=max(f[i],f[j]+1);
            }
        }
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        ans=max(ans,f[i]);
    }
    printf("%d\n",ans);
}

int main(void){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%s",s[i]+1);
        len[i]=strlen(s[i]+1);
    }
    solve();
    return 0;
}
