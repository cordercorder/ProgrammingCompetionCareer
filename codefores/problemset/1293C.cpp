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

bool maze[3][maxn];
int n,q;
int sum;

int main(void){
    int r,c;
    scanf("%d %d",&n,&q);
    for(int i=1;i<=q;i++){
        scanf("%d %d",&r,&c);
        maze[r][c]=!maze[r][c];
        for(int j=-1;j<=1;j++){
            if(j==0)
                continue;
            for(int k=-1;k<=1;k++){
                int x=r+j;
                int y=c+k;
                if(x>=1&&x<=2&&y>=1&&y<=n){
                    if(maze[x][y]){
                        if(maze[r][c])
                            sum++;
                        else
                            sum--;
                    }
                }
            }
        }
        if(sum>0){
            puts("No");
        }
        else{
            puts("Yes");
        }
        // deb(sum);
    }
    return 0;
}