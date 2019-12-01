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

const int maxn=110;

int q,n;
int a[maxn*4];
int cnt[10010];
map<int,int>res;

bool check(int x,vector<int> &id){
    for(int e:id){
        res[e]++;
    }
    for(int e:id){
        if(x%e==0){
            if(res[e]>0&&res[x/e]>0){
                res[e]--;
                res[x/e]--;
            }
            else if(res[e]==0&&res[x/e]==0){
                continue;
            }
            else{
                res.clear();
                return false;
            }
        }
        else{
            res.clear();
            return false;
        }
    }
    res.clear();
    return true;
}

void solve(){
    vector<int> id;
    int lim=4*n,tmp;
    for(int i=1;i<=lim;i++){
        cnt[a[i]]++;
    }
    for(int i=1;i<=10000;i++){
        if(cnt[i]%2==1){
            puts("NO");
            return ;
        }
    }
    for(int i=1;i<=10000;i++){
        if(cnt[i]>0){
            while(cnt[i]>0){
                id.push_back(i);
                cnt[i]-=2;
            }
        }
    }
    if(check(id[0]*id.back(),id)){
        puts("YES");
    }
    else{
        puts("NO");
    }
}

int main(void){
    int lim;
    scanf("%d",&q);
    while(q--){
        scanf("%d",&n);
        lim=4*n;
        for(int i=1;i<=lim;i++){
            scanf("%d",&a[i]);
        } 
        solve();
        for(int i=1;i<=10000;i++){
            cnt[i]=0;
        }
    }
    return 0;
}
