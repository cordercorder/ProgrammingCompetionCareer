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

vector<int> e[maxn];
int n,m;
int pre[maxn],c[maxn];

int Find(int x){
    return pre[x]==0?x:pre[x]=Find(pre[x]);
}

void Union(int u,int v){
    int nu=Find(u),nv=Find(v);
    if(nu!=nv){
        pre[nu]=nv;
    }
}

bool check(vector<int> &V1,vector<int> &V2){
    for(int u:V1){
        for(int v:V2){
            if(!binary_search(e[u].begin(),e[u].end(),v)){
                return false;
            }
        }
    }
    return true;
}

void solve(){
    int ans=0;
    for(int i=1;i<=n;i++){
        if(pre[i]==0){
            ans++;
        }
    }
    if(ans>1){
        puts("-1");
        return ;
    }
    for(int i=1;i<=n;i++){
        c[i]=1;
    }
    for(int i=1;i<=n;i++){
        for(int v:e[i]){
            if(c[v]==c[i]){
                c[v]++;
                if(c[v]>3){
                    puts("-1");
                    return ;
                }
            }
        }
    }
    int sum[]={0,0,0};
    for(int i=1;i<=n;i++){
        sum[c[i]-1]++;
    }
    if(sum[0]==0||sum[1]==0||sum[2]==0){
        puts("-1");
        return ;
    }
    for(int i=1;i<=n;i++){
        for(int v:e[i]){
            if(c[v]==c[i]){
                puts("-1");
                return ;
            }
        }
    }
    vector<int> V1,V2,V3;
    for(int i=1;i<=n;i++){
        if(c[i]==1){
            V1.push_back(i);
        }
        else if(c[i]==2){
            V2.push_back(i);
        }
        else{
            V3.push_back(i);
        }
        sort(e[i].begin(),e[i].end());
    }
    if(check(V1,V2)&&check(V2,V3)&&check(V1,V3)){
        for(int i=1;i<=n;i++){
            printf("%d ",c[i]);
        }
    }
    else{
        puts("-1");
    }
}

int main(void){
    int u,v;
    scanf("%d %d",&n,&m);
    for(int i=0;i<m;i++){
        scanf("%d %d",&u,&v);
        Union(u,v); 
        e[u].push_back(v);
        e[v].push_back(u);
    }
    solve();
    return 0;
}
