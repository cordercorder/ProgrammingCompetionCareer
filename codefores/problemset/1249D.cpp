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

const int maxn=210;

struct node{
    int id;
    int l;
    bool operator<(const node &a)const{
        return l<a.l;
    }
};

int n,k,maxr;
multiset<node> p[maxn];
int sum[maxn];

void solve(){
    for(int i=1;i<=maxr;i++){
        sum[i]+=sum[i-1];
    }
    vector<int> ans;
    for(int i=1;i<=maxr;i++){
        if(sum[i]>k){
            for(int j=maxr;j>=i&&sum[i]>k;j--){
                for(set<node>::iterator it=p[j].begin();it!=p[j].end()&&sum[i]>k;){
                    if(it->l<=i){
                        int l=it->l,r=j;
                        ans.push_back(it->id);
                        p[j].erase(it++);
                        for(int u=l;u<=r;u++){
                            sum[u]--;
                        }
                    }
                    else{
                        break;
                    }
                }
            }
        }
    }
    printf("%d\n",(int)ans.size());
    for(int i=0;i<(int)ans.size();i++){
        if(i>0)
            printf(" ");
        printf("%d",ans[i]);
    }
}

int main(void){
    int l,r;
    scanf("%d %d",&n,&k);
    for(int i=1;i<=n;i++){
        scanf("%d %d",&l,&r);
        sum[l]+=1;
        sum[r+1]-=1;
        p[r].insert({i,l});
        maxr=max(maxr,r);
    }
    solve();
    return 0;
}
