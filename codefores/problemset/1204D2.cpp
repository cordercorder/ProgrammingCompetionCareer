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

const int maxn=(int)1e5+10;

char s[maxn],ans[maxn];
int res[maxn][2];

void solve(){
    multiset<int> S;
    int cnt=0,sum[2],len=strlen(s+1),ret;
    for(int i=1;i<=len;i++){
        res[i][0]=res[i-1][0]+(int)(s[i]=='0');
        res[i][1]=res[i-1][1]+(int)(s[i]=='1');
        S.insert(res[i][0]-res[i][1]);
    }
    bool f;
    for(int i=1;i<=len;i++){
        if(s[i]=='0'){
            ans[++cnt]='0';
        }
        else{
            ret=res[i][0]-res[i][1];
            if(S.upper_bound(ret)!=S.end()){
                ans[++cnt]='1';
            }
            else{
                ans[++cnt]='0';
            }
        }
        auto it=S.find(res[i][0]-res[i][1]);
        S.erase(it); 
    }
    ans[cnt+1]='\0';
    puts(ans+1);
}

int main(void){
    scanf("%s",s+1); 
    solve();
    return 0;
}
