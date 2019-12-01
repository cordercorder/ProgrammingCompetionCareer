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

const ll maxn=(ll)1e5+10ll;

ll a,b,c,d,k;
ll mu[maxn],prime[maxn],sum[maxn];
bool isv[maxn];

void Moblus(ll x){
    mu[1]=1;
    int tot=0;
    for(int i=2;i<=x;i++){
        if(!isv[i]){
            prime[tot++]=i;
            mu[i]=-1;
        }
        for(int j=0;j<tot;j++){
            if(i*prime[j]>x){
                break;
            }
            isv[i*prime[j]]=true;
            if(i%prime[j]==0){
                mu[i*prime[j]]=0;
                break;
            }
            else{
                mu[i*prime[j]]=-mu[i];
            }
        }
    }
    for(int i=1;i<=x;i++){
        sum[i]=sum[i-1]+mu[i];
    }
}

ll solve(ll n,ll m){
    ll N=min(n,m);
    ll ans=0;
    for(ll l=1,r;l<=N;l=r+1){
        r=min(n/(n/l),m/(m/l));
        ans=ans+(sum[r]-sum[l-1])*(n/l)*(m/l);
    }
    return ans;
}

int main(void){
    Moblus(100000);
    int T;
    scanf("%d",&T);
    ll ans,ans1,ans2;
    for(int ca=1;ca<=T;ca++){
        scanf("%lld %lld %lld %lld %lld",&a,&b,&c,&d,&k);
        printf("Case %d: ",ca);
        if(k==0){
            puts("0");
            continue;
        }
        ans1=solve(b/k,d/k);
        ans2=solve(min(b/k,d/k),min(b/k,d/k));
        if(b>=k&&d>=k){
            ans2--;
        }
        ans=ans1-ans2/2;
        printf("%lld\n",ans);
    }
    return 0;
}
