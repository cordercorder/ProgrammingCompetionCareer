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

const int maxn=2e5+10;

string s,t;

int pref[maxn],suf[maxn];

void solve(){
    int ans=0,j=0;
    for(int i=0;i<(int)s.length();i++){
        if(j<(int)t.length()&&t[j]==s[i]){
            pref[j]=i;
            j++;
        }
    }
    j=(int)t.length()-1;
    for(int i=(int)s.length()-1;i>=0;i--){
        if(j>=0&&t[j]==s[i]){
            suf[j]=i;
            j--;
        }
    }
    ans=max(ans,suf[0]);
    ans=max(ans,(int)s.length()-pref[(int)t.length()-1]-1);
    for(int i=0;i<(int)t.length();i++){
        ans=max(ans,suf[i+1]-pref[i]-1);
    }
    printf("%d\n",ans);
}

int main(void){
    FC;
    cin>>s>>t;
    solve();
    return 0;
}
