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

const int maxn=101000;

int n;
vector<int> g[maxn+maxn],e[maxn],rev;
bool isv[maxn+maxn];
int link[maxn+maxn];
vector<vector<int>> ANS;

bool is_sq(int x){
    int tmp=sqrt(x);
    return tmp*tmp==x;
}

void pre_handle(int N){
    for(int i=1;i<=N;i++){
        for(int j=i+1;j<=N;j++){
            if(is_sq(i+j)){
                g[2*i].push_back(2*j+1);
            }
        }
    }
}

bool dfs(int u){
    isv[u]=true;
    for(int v:g[u]){
        if(!isv[v]){
            if(link[v]==-1||dfs(link[v])){
                link[v]=u;
                return true;
            }
        }
    }
    return false;
}

void dfs2(int u){
    isv[u]=true;
    rev.push_back(u);
    for(int v:e[u]){
        if(!isv[v]){
            dfs2(v); 
        }
    }
}

void solve(){
    int ans=11;
    int cnt;
    pre_handle(ans);
    while(true){
        cnt=0;
        for(int i=1;i<=2*ans+1;i++){
            link[i]=-1;
        }
        for(int i=1;i<=ans;i++){
            for(int j=1;j<=2*ans+1;j++){
                isv[j]=false;
            }
            if(dfs(2*i)){
                cnt++;
            }
        }
        cnt=ans-cnt;
        if(cnt>n){
            break;
        }
        ans++;
        for(int i=1;i<ans;i++){
            if(is_sq(i+ans)){
                g[2*i].push_back(2*ans+1);
            }
        }
    }
    printf("%d\n",ans-1);
    for(int i=1;i<ans;i++){
        for(int v:g[2*i]){
            if(link[v]==2*i){
                e[i].push_back((v-1)/2);
            }
        }
    }
    for(int i=1;i<=ans;i++){
        isv[i]=false;
    }
    for(int i=1;i<ans;i++){
        if(!isv[i]){
            dfs2(i);
            ANS.push_back(rev);
            rev.clear();
        }
    }
    for(auto &E:ANS){
        for(int i=0;i<(int)E.size();i++){
            if(i>0){
                printf(" ");
            }
            printf("%d",E[i]);
        }
        puts("");
    }
}

int main(void){
    scanf("%d",&n);
    solve();
    return 0;
}
