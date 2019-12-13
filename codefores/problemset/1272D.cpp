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

int n,a[maxn],tmp[maxn],len[maxn];

void solve(){
    int ans=0,cnt,tot=0;
    vector<int> res,lst;
    for(int i=1;i<=n;){
        int j=i;
        cnt=0;
        while(j+1<=n&&a[j+1]>a[j]){
            tmp[++cnt]=a[j];
            j++;
        }
        // deb(i,j);
        tmp[++cnt]=a[j];
        len[++tot]=cnt;
        ans=max(ans,cnt);
        if(!res.empty()){
            // deb(i,cnt);
            // deb(res.back());
            if(len[tot-1]>=2&&tmp[1]>res.back()){
                // deb(i,j,cnt);
                ans=max(ans,len[tot]+len[tot-1]-1);
            }
        }
        // deb(tmp[cnt],cnt,tmp[cnt-1]);
        if(cnt>=2){
            if(!lst.empty()&&tmp[2]>lst.back()){
                ans=max(ans,len[tot]+len[tot-1]-1);
            }
            res.push_back(tmp[cnt-1]);
        }
        lst.push_back(a[j]);
        i=j+1;
    }
    printf("%d\n",ans);
}

int main(void){
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    solve();
    return 0;
}