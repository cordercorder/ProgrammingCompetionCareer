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

const int inf=(int)1e9;
const int maxn=450;

int m,n,sum;
vector<int> rev[maxn];
pii r[maxn],c[maxn];
int cnt[maxn];
bool isv[maxn];

bool cmp(const pii &a,const pii &b){
    return a.first>b.first;
}

void solve(){
    sort(r+1,r+1+m,cmp);
    sort(c+1,c+1+n,cmp);
    bool f;
    for(int i=1;i<=m;i++){
        int k=1;
        for(int j=1;j<=n;j++){
            isv[j]=false;
        }
        for(int j=1;j<=r[i].first;j++){
            f=false;
            for(int k=1;k<=n;k++){
                if(!isv[k]&&cnt[k]<c[k].first){
                    cnt[k]++;
                    rev[r[i].second].push_back(c[k].second);
                    f=true;
                    isv[k]=true;
                    break;
                }
            }
            if(!f){
                puts("0");
                return ;
            }
        }
    }
    puts("1");
    for(int i=1;i<=m;i++){
        for(int j=0;j<(int)rev[i].size();j++){
            if(j>0){
                printf(" ");
            }
            printf("%d",rev[i][j]);
        }
        puts("");
    }
}

int main(void){
    int x;
    scanf("%d %d",&m,&n);
    for(int i=1;i<=m;i++){
        scanf("%d",&r[i].first);
        r[i].second=i;
    }
    for(int i=1;i<=n;i++){
        scanf("%d",&c[i].first);
        c[i].second=i;
    }
    solve();
    return 0;
}
