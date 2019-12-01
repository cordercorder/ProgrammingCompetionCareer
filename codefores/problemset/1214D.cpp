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

int n,m;
char **s;
bool **isv;

bool dfs(int x,int y){
    if(x==n&&y==m){
        return true;
    }
    isv[x][y]=true;
    if(y+1<=m&&!isv[x][y+1]&&s[x][y+1]=='.'){
        if(dfs(x,y+1))
            return true;
    }
    if(x+1<=n&&!isv[x+1][y]&&s[x+1][y]=='.'){
        if(dfs(x+1,y))
            return true;
    }
    return false;
}

void solve(){
    isv=new bool*[n+10];
    for(int i=1;i<=n;i++){
        isv[i]=new bool[m+10];
    } 
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            isv[i][j]=false;
        }
    }
    int ans=0;
    if(2<=m&&s[1][2]=='.'&&dfs(1,2)){
        ans++;
    }
    if(2<=n&&s[2][1]=='.'&&dfs(2,1)){
        ans++;
    }
    printf("%d\n",ans);
}

int main(void){
    scanf("%d %d",&n,&m);
    s=new char*[n+10];
    for(int i=1;i<=n;i++){
        s[i]=new char[m+10];
        scanf("%s",s[i]+1);
    }
    solve();
    return 0;
}
