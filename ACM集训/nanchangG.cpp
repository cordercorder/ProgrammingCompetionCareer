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

const ll maxn=(ll)1e5+10ll;

const ll mod=998857459ll;

ll f[maxn],n,m,a[maxn];

struct node{
    ll pos;
    ll val;
};

struct Node{
    ll l;
    ll r;
    ll val;
};

vector<node> res;
vector<Node> rev;
ll mine[3010*3010];

void pre_handle(){
    f[0]=1;
    for(ll i=1;i<=100000;i++){
        f[i]=f[i-1]*i%mod;
    }
}

bool cmp(const Node &a,const Node &b){
    return a.val<b.val;
}

void solve(){
    for(ll i=1;i<=n;i++){
        if(f[a[i]]>0){
            res.push_back({i,f[a[i]]});
        }
    }
    ll sum;
    for(ll i=0;i<(ll)res.size();i++){
        sum=0;
        for(ll j=i;j<(ll)res.size();j++){
            sum=(sum+res[j].val)%mod;
            rev.push_back({res[i].pos,res[j].pos,sum});
        }
    }
    sort(rev.begin(),rev.end(),cmp);
    mine[(ll)rev.size()-1]=rev.back().r-rev.back().l+1;
    for(ll i=(ll)rev.size()-2;i>=0;i--){
        mine[i]=min(rev[i].r-rev[i].l+1,mine[i+1]);
    }
}

int main(void){
    pre_handle();
    scanf("%lld %lld",&n,&m);
    for(ll i=1;i<=n;i++){
        scanf("%lld",&a[i]);
    }
    solve();
    Node now;
    while(m--){
        scanf("%lld",&now.val);
        auto pos=lower_bound(rev.begin(),rev.end(),now,cmp);
        if(pos==rev.end()){
            puts("-1");
        }
        else{
            ll x=pos-rev.begin();
            // deb(x);
            printf("%lld\n",mine[x]);
        }
    }
    return 0;
}