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

const int maxn=(int)2e5+10;

int n;
vector<int> e[maxn],res;
int maxe,id;
int ans[3],d[maxn];
bool isv[maxn];
int prefix[maxn];
int sum;

int main(void){
    int u,v;
    scanf("%d",&n);
    for(int i=1;i<n;i++){
        scanf("%d %d",&u,&v);
        e[u].push_back(v);
        e[v].push_back(u);
    }

    maxe=0;
    id=-1;

    function<void(int,int,int)> dfs_pre=[&dfs_pre](int u,int pre,int depth){
        if(depth>maxe){
            maxe=depth;
            id=u;
        }
        prefix[u]=pre;
        for(int v:e[u]){
            if(v==pre)
                continue;
            dfs_pre(v,u,depth+1);
        }
    };


    dfs_pre(1,0,0);
    ans[0]=id;

    maxe=0;
    dfs_pre(id,0,0);
    ans[1]=id;

    sum=-1;
    int tmp=id;
    while(tmp!=0){
        res.push_back(tmp);
        sum++;
        tmp=prefix[tmp];
    }

    function<void(int,int)> dfs=[&dfs](int u,int pre){
        d[u]=d[pre]+1;
        prefix[u]=pre;
        for(int v:e[u]){
            if(v==pre||isv[v])
                continue;
            isv[v]=true;
            dfs(v,u);
        }
    };

    for(int item:res){
        isv[item]=true;
    }
    d[0]=-1;
    for(int item:res){
        dfs(item,0);
    }

    id=1;
    for(int i=1;i<=n;i++){
        if(d[i]>d[id]){
            id=i;
        }
    }

    vector<int> select;
    for(int i=1;i<=n;i++){
        if(d[i]==d[id]){
            select.push_back(i);
        }
    }

    sum+=d[id];

    for(int item:select){
        if(item!=ans[0]&&item!=ans[1]){
            id=item;
            break;
        }
    }

    ans[2]=id;
    printf("%d\n",sum);
    for(int i=0;i<3;i++){
        if(i>0)
            printf(" ");
        printf("%d",ans[i]);
    }
    return 0;
}