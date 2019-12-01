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

const int maxn=510;

int t;
char s[maxn];

int main(void){
    scanf("%d",&t);
    while(t--){
        vector<bool> isv(26,false);
        scanf("%s",s);
        int len=strlen(s);
        for(int i=0;i<len;i++){
            isv[s[i]-'a']=false;
        }
        for(int i=0;i<len;){
            int j=i,cnt=0;
            while(j<len&&s[j]==s[i]){
                j++;
                cnt++;
            }
            if(cnt%2==1){
                isv[s[i]-'a']=true;
            }
            i=j;
        }
        for(int i=0;i<26;i++){
            if(isv[i]){
                printf("%c",i+'a');
            }
        }
        puts("");
    }
    return 0;
}
