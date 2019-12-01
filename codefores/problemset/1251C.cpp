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

const int maxn=(int)3e5+10;

int t;
char s[maxn],res1[maxn],res2[maxn],ans[maxn];
bool isv[15];

bool cmp1(const char &a,const char &b){
    int na=a-'0';
    int nb=b-'0';
    if((na%2==0)&&(nb%2)!=0)
        return true;
    return false;
}

bool cmp2(const char &a,const char &b){
    int na=a-'0';
    int nb=b-'0';
    if((na%2!=0)&&(nb%2)==0)
        return true;
    return false;
}

void solve(){
    int len=strlen(s);
    for(int i=0;i<len;i++){
        isv[s[i]-'0']=true;
    }
    for(int i=0;i<10;i++){
        if(isv[i]){
            if(i%2==0){
                stable_sort(s,s+len,cmp1);
            }
            else{
                stable_sort(s,s+len,cmp2);
            }
            break;
        }
    }
    int cnt1=0,cnt2=0,tot=0;
    int x=(s[0]-'0')%2;
    int i;
    for(i=0;i<len;i++){
        if((s[i]-'0')%2==x){
            res1[cnt1++]=s[i];
        }
        else{
            break;
        }
    }
    res1[cnt1]='\0';
    for(;i<len;i++){
        res2[cnt2++]=s[i];
    }
    res2[cnt2]='\0';
//    puts(res1);
//    puts(res2);
    int j=0;
    for(i=0;i<cnt1;i++){
        if(j<cnt2&&res1[i]>res2[j]){
            ans[tot++]=res2[j++];
            i--;
        }
        else{
            ans[tot++]=res1[i];
        }
    }
    while(j<cnt2){
        ans[tot++]=res2[j++];
    }
    ans[tot]='\0';
    puts(ans);
}

int main(void){
    scanf("%d",&t);
    while(t--){
        scanf("%s",s);
        solve();
        for(int i=0;i<10;i++){
            isv[i]=false;
        }
    }
    return 0;
}
