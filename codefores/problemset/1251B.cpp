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

const int maxn=55;

int Q,n,len[maxn];

struct node{
    char s[maxn];
    int len;
}res[maxn];

bool cmp(const node &a,const node &b){
    return a.len<b.len; 
}

void solve(){
    sort(res+1,res+1+n,cmp);
    int sum[2]={0,0};
    for(int i=1;i<=n;i++){
        for(int j=0;j<res[i].len;j++){
            sum[res[i].s[j]-'0']++;
        }
    }
    int ans=0;
    for(int i=1;i<=n;i++){
//        deb(sum[0],sum[1]);
//        deb(res[i].len);
        bool f=true;
        for(int j=0,k=res[i].len-1;j<=k;j++,k--){
            if(j<k){
                if(sum[0]>=2){
                    sum[0]-=2;
                }
                else if(sum[1]>=2){
                    sum[1]-=2;
                }
                else{
                    f=false;
                    break;
                }
            }
            else{
                if(res[i].len%2==1){
                    if(sum[0]%2==1){
                        sum[0]--;
                    }
                    else if(sum[1]%2==1){
                        sum[1]--;
                    }
                    else{
                        if(sum[0]>0){
                            sum[0]--;
                        }
                        else if(sum[1]>0){
                            sum[1]--;
                        }
                        else{
                            f=false;
                            break;
                        }
                    }
                }
                else{
                    if(sum[0]>0){
                        sum[0]--;
                    }
                    else if(sum[1]>0){
                        sum[1]--;
                    }
                    else{
                        f=false;
                        break;
                    }
                }
            }
        }
        if(f)
            ans++;
    }
    printf("%d\n",ans);
}

int main(void){
    scanf("%d",&Q);
    while(Q--){
        scanf("%d",&n);
        for(int i=1;i<=n;i++){
            scanf("%s",res[i].s);
            res[i].len=strlen(res[i].s);
        }
        solve();
    }
    return 0;
}
