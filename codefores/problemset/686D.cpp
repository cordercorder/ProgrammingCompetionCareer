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
const int inf=(int)1e9;

namespace IO {
    const int MT = 50 * 1024 * 1024;//50mb
    char IO_BUF[MT];
    int IO_PTR, IO_SZ;
    void begin() {
        IO_PTR = 0;
        IO_SZ = fread (IO_BUF, 1, MT, stdin);
    }
    template<typename T>
    inline bool scan_d (T & t) {
        while (IO_PTR < IO_SZ && IO_BUF[IO_PTR] != '-' && (IO_BUF[IO_PTR] < '0' || IO_BUF[IO_PTR] > '9'))
            IO_PTR ++;
        if (IO_PTR >= IO_SZ) return false;
        bool sgn = false;
        if (IO_BUF[IO_PTR] == '-') sgn = true, IO_PTR ++;
        for (t = 0; IO_PTR < IO_SZ && '0' <= IO_BUF[IO_PTR] && IO_BUF[IO_PTR] <= '9'; IO_PTR ++)
            t = t * 10 + IO_BUF[IO_PTR] - '0';
        if (sgn) t = -t;
        return true;
    }
    inline bool scan_s (char s[]) {
        while (IO_PTR < IO_SZ && (IO_BUF[IO_PTR] == ' ' || IO_BUF[IO_PTR] == '\n') ) IO_PTR ++;
        if (IO_PTR >= IO_SZ) return false;
        int len = 0;
        while (IO_PTR < IO_SZ && IO_BUF[IO_PTR] != ' ' && IO_BUF[IO_PTR] != '\n')
            s[len ++] = IO_BUF[IO_PTR], IO_PTR ++;
        s[len] = '\0';
        return true;
    }
    template<typename T>
    void print(T x) {
        static char s[33], *s1; s1 = s;
        if (!x) *s1++ = '0';
        if (x < 0) putchar('-'), x = -x;
        while(x) *s1++ = (x % 10 + '0'), x /= 10;
        while(s1-- != s) putchar(*s1);
    }
    template<typename T>
    void println(T x) {
        print(x); putchar('\n');
    }
};

vector<int> e[maxn];
int n,q;
int cnt,sum[maxn],pre[maxn],biggest[maxn];
int ans[maxn];

void dfs(int u,int fa){
    sum[u]=1;
    pre[u]=fa;
    biggest[u]=0;
    for(int v:e[u]){
        if(v==fa)
            continue;
        dfs(v,u);
        sum[u]+=sum[v];
        biggest[u]=max(biggest[u],sum[v]);
    }
}

bool check(int u,int fa){
    if(2*(sum[fa]-sum[u])<=sum[fa]&&2*biggest[u]<=sum[fa])
        return true;
    return false;
}

void dfs2(int u,int fa){
    if(sum[u]==1){
        ans[u]=u;
        return ;
    }
    int ret=-1,tmp=0;
    for(int v:e[u]){
        if(v==fa)
            continue ;
        dfs2(v,u);
        if(sum[v]>tmp){
            tmp=sum[v];
            ret=v;
        }
    }
    int x=ans[ret];
    while(!check(x,u)){
        x=pre[x];
    }
    ans[u]=x;
}

int main(void){
    int u;
    IO::begin();
    IO::scan_d(n);
    IO::scan_d(q);
//    scanf("%d %d",&n,&q);
    for(int i=2;i<=n;i++){
        IO::scan_d(u);
//        scanf("%d",&u);
        e[u].push_back(i);
        e[i].push_back(u);
    }
    dfs(1,0);
    dfs2(1,0);
    while(q--){
        IO::scan_d(u);
//        scanf("%d",&u);
        IO::println(ans[u]);
    }
    return 0;
}
