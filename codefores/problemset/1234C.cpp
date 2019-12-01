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

const int maxn=(int)2e5+10; 

int q;
int n;
char ma[3][maxn];

bool dfs(int x,int y){
    if(y==n){
        return x==2;
    }
    if(ma[x][y+1]=='1'){
        return dfs(x,y+1);
    }
    else{
        if(x==1){
            if(ma[x][y+1]=='2'&&ma[x+1][y+1]=='2')
                return dfs(x+1,y+1);
        }
        else{
            if(ma[x][y+1]=='2'&&ma[x-1][y+1]=='2')
                return dfs(x-1,y+1);
        }
    }
    return false;
}

void solve(){
    if(dfs(1,0)){
        puts("YES");
    }
    else{
        puts("NO");
    }
}

int main(void){
    scanf("%d",&q);
    while(q--){
        scanf("%d",&n);
        for(int i=1;i<=2;i++){
            scanf("%s",ma[i]+1);
        }
        for(int i=1;i<=2;i++){
            for(int j=1;j<=n;j++){
                if(ma[i][j]=='1'||ma[i][j]=='2'){
                    ma[i][j]='1';
                }
                else{
                    ma[i][j]='2';
                }
            } 
        } 
        solve();
    }
    return 0;
}
