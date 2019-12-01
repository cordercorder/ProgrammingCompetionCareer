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
using pii=pair<ll,ll>;
 
/*head------[@cordercorder]*/

const ll base=3;

ll q,n,m;
vector<pii> res;
ll p[50],cnt,ans;
bool isv[40];

void pre_handle(){
    ll ret=1;
    cnt=0;
    for(ll i=0;;i++){
        res.push_back(pii(ret,i));
        p[cnt++]=ret;
        ret=ret*base;
        if(ret>(ll)1e18){
            res.push_back(pii(ret,i+1));
            p[cnt++]=ret;
            break;
        }
    }
    sort(res.begin(),res.end(),[](const pii &a,const pii &b)->bool{
        return a.first>b.first;
    });
}

void solve(){
    ll tmp=n,ans=0,sum,tot=0,maxbit=0;
    ll j=0;
    for(ll i=0;i<40;i++){
        isv[i]=false;
    }
    while(tmp>0&&j<(ll)res.size()){
        if(tmp>=res[j].first){
            isv[res[j].second]=true;
            maxbit=max(maxbit,res[j].second);
            tmp-=res[j].first;
            ans+=res[j].first;
            tot++;
        }
        j++;
    }
    if(ans>=n){
        sum=*(lower_bound(p,p+cnt,n));
        ans=min(ans,sum);
        printf("%lld\n",ans);
        return ;
    }
    sum=0;
    for(int i=0;i<cnt;i++){
        if(!isv[i]){
            ans-=sum;
            ans+=p[i];
            if(ans>=n){
                printf("%lld\n",ans);
                return ;
            }
        }
        else{
            sum+=p[i];
        }
    }
}

int main(void){
    freopen("1.in","r",stdin);
    freopen("my.out","w",stdout);
    pre_handle();
    scanf("%lld",&q);
    while(q--){
        scanf("%lld",&n);
        solve();
    }
    return 0;
}
