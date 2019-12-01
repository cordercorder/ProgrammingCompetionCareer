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

int n,k;
queue<int> q;
vector<int> ans;
map<int,bool> isv;

int main(void){
    int id;
    scanf("%d %d",&n,&k);
    for(int i=1;i<=n;i++){
        scanf("%d",&id);
        if(isv[id]){
            continue;
        }
        if((int)q.size()==k){
            isv[q.front()]=false;
            q.pop();
        }
        isv[id]=true;
        q.push(id);
    }
    while(!q.empty()){
        ans.push_back(q.front());
        q.pop();
    }
    reverse(ans.begin(),ans.end());
    printf("%d\n",(int)ans.size());
    for(auto v:ans){
        printf("%d ",v);
    }
    return 0;
}
