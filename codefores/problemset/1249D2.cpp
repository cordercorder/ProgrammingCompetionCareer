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

vector<int> L[maxn],R[maxn];
int l[maxn],r[maxn];
int n,k,maxr;

struct node{
    int r;
    int id;
    bool operator<(const node &a)const{
        return r>a.r;
    }
};

void solve(){
    vector<int> ans;
    multiset<node> S; 
    for(int i=1;i<=maxr;i++){
        for(int id:L[i]){
            S.insert({r[id],id});
        }
        for(int id:R[i]){
            auto it=S.find({r[id],id});
            if(it!=S.end()){
                S.erase(it);
            }
        }
        while((int)S.size()>k){
            ans.push_back(S.begin()->id);
            S.erase(S.begin());
        }
    }
    printf("%d\n",(int)ans.size());
    for(int i=0;i<(int)ans.size();i++){
        if(i>0)
            printf(" ");
        printf("%d",ans[i]);
    }
}

int main(void){
    scanf("%d %d",&n,&k);
    for(int i=1;i<=n;i++){
        scanf("%d %d",&l[i],&r[i]);
        maxr=max(maxr,r[i]);
        L[l[i]].push_back(i);
        R[r[i]+1].push_back(i);
    }
    solve();
    return 0;
}
