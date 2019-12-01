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

int n,tot;
char s[5],t[5],ans[maxn*3];
char rev[20][5];

void pre_handle(){
    bool f;
    char p[]="abc";
    do{
        f=false;
        for(int i=0;i<3;i++){
            if(i+1<3&&p[i]==s[1]&&p[i+1]==s[2]){
                f=true;
                break;
            }
            if(i+1<3&&p[i]==t[1]&&p[i+1]==t[2]){
                f=true;
                break;
            }
        }
        if(f)
            continue;
        tot++;
//        deb(p);
        for(int i=0;i<3;i++){
            rev[tot][i+1]=p[i];
        }
    }while(next_permutation(p,p+3));
}

void solve(){
    bool f=true;
    int id[3];
    for(int i=1;i<=tot&&f;i++){
        for(int j=i;j<=tot&&f;j++){
            for(int k=j;k<=tot&&f;k++){
                if(n>=2&&((rev[i][3]==s[1]&&rev[j][1]==s[2])||(rev[i][3]==t[1]&&rev[j][1]==t[2]))){
                    continue;
                }
                if(n>=3&&((rev[j][3]==s[1]&&rev[k][1]==s[2])||(rev[j][3]==t[1]&&rev[k][1]==t[2]))){
                    continue;
                }
                if(n>=4&&((rev[k][3]==s[1]&&rev[i][1]==s[2])||(rev[k][3]==t[1]&&rev[i][1]==t[2]))){
                    continue;
                }
                else{
                    f=false;
                    id[0]=i;
                    id[1]=j;
                    id[2]=k;
                }
            }
        }
    }
    int cnt=0;
    if(f){
        cnt=0;
        char p[]="abc";
        do{
            bool fa=true;
            cnt=0;
            for(int i=0;i<3;i++){
                for(int k=0;k<n;k++){
                    ans[++cnt]=p[i];
                }
            }
            for(int i=1;i+1<=cnt;i++){
                if((ans[i]==s[1]&&ans[i+1]==s[2])||(ans[i]==t[1]&&ans[i+1]==t[2])){
                    fa=false;
                    break;
                }
            }
            if(fa){
                ans[cnt+1]='\0';
                puts("YES");
                puts(ans+1);
                return ;
            }
        }while(next_permutation(p,p+3));
        puts("NO");
        return ;
    }
    for(int i=0;i<n;i++){
        for(int j=1;j<=3;j++){
            ans[++cnt]=rev[id[i%3]][j];
        }
    }
    ans[cnt+1]='\0';
    puts("YES");
    puts(ans+1);
}

int main(void){
    scanf("%d",&n);
    scanf("%s %s",s+1,t+1);
    pre_handle();
    solve();
    return 0;
}
