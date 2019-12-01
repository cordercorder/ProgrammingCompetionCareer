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

const int maxn=(int)5e4+10;

int K,N;
int a[maxn];
map<int,int> cnt;

struct node{
    int x;
    int y;
    node(int _x=0,int _y=0):x(_x),y(_y){}
    bool operator<(const node &a)const{
        if(x<a.x){
            return true;
        }
        else if(x==a.x&&y<a.y){
            return true;
        }
        return false;
    }
};

void solve(){
    set<node> ans;
    for(int i=1;i<=N;i++){
        cnt[a[i]]++;
    }
    int x,y;
    map<int,int>::iterator it;
    for(int i=1;i<=N;i++){
        it=cnt.find(K-a[i]);
        if(it!=cnt.end()&&(it->first)!=a[i]){
            x=it->first;
            y=a[i];
            if(x>y){
                swap(x,y);
            }
            ans.insert(node(x,y));
        }
    }
    if(ans.empty()){
        puts("No Solution");
    }
    else{
        for(set<node>::iterator i=ans.begin();i!=ans.end();i++){
            printf("%d %d\n",i->x,i->y);
        }
    }
}

int main(void){
    
    scanf("%d %d",&K,&N);
    for(int i=1;i<=N;i++){
        scanf("%d",&a[i]);
    }
    solve();
    return 0;
}
