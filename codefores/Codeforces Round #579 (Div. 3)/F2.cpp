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
 
int n,r;
 
struct node{
    int a;
    int b;
    bool operator<(const node &o)const{
        return b>o.b;
    }
}res[maxn];

bool cmp(const node &o1,const node &o2){
    return o1.a+o1.b>o2.a+o2.b;
}

node rev[maxn];
int dp[maxn][30010],cnt;

int dfs(int pos,int sum){
    if(pos==cnt+1){
        return 0;
    }
    if(dp[pos][sum]>=0){
        return dp[pos][sum];
    }
    int res1,res2;
    if(sum>=rev[pos].a&&sum+rev[pos].b>=0){
        res1=dfs(pos+1,sum+rev[pos].b)+1;
        res2=dfs(pos+1,sum);
        return dp[pos][sum]=max(res1,res2);
    }
    else{
        res1=dfs(pos+1,sum);
        return dp[pos][sum]=res1;
    }
}

void solve(){
    multiset<node> S1;
    multiset<node>::iterator it1;
    for(int i=1;i<=n;i++){
        if(res[i].b>=0){
            S1.insert({res[i].a,res[i].b});
        }
        else{
            rev[++cnt]=res[i];
        }
    }
    int now=r,ans=0;
    bool f;
    while(!S1.empty()){
        f=false;
        for(it1=S1.begin();it1!=S1.end();it1++){
            if(it1->a<=now){
                now+=it1->b;
                S1.erase(it1);
                ans++;
                f=true;
                break;
            }
        }
        if(!f){
            break;
        }
    }
    sort(rev+1,rev+1+cnt,cmp);
    memset(dp,-1,sizeof(dp));
    ans+=dfs(1,now);
    printf("%d\n",ans);
}

int main(void){
    scanf("%d %d",&n,&r);
    for(int i=1;i<=n;i++){
    	scanf("%d %d",&res[i].a,&res[i].b);
	}
    solve();
    return 0;
}
