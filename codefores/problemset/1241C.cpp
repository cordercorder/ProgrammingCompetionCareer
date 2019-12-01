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

const ll maxn=(ll)2e5+10;

ll q,n;
ll p[maxn],rev[maxn];
ll x,a,y,b,k,ret;
bool isv[maxn];

ll lcm(ll a,ll b){
    ll tmp=__gcd(a,b);
    return a*b/tmp;
}

bool check(ll lim){
    ll cnt=ret,ans=0;
    ll i;
    for(i=1;i<=lim;i++){
        if(cnt<=lim){
            isv[cnt]=true;
            ans+=(x+y)*p[i];
            cnt+=ret;
        }
        else{
            break;
        }
    }
    cnt=b;
    for(;i<=lim;i++){
        if(cnt<=lim){
            if(isv[cnt]){
                cnt+=b;
                i--;
            }
            else{
                isv[cnt]=true;
                ans+=y*p[i];
                cnt+=b;
            }
        }
        else{
            break;
        }
    }
    cnt=a;
    for(;i<=lim;i++){
        if(cnt<=lim){
            if(isv[cnt]){
                cnt+=a;
                i--;
            }
            else{
                isv[cnt]=true;
                ans+=x*p[i];
                cnt+=a;
            }
        }
        else{
            break;
        }
    }
    for(ll i=1;i<=lim;i++){
        isv[i]=false;
    }
    return ans>=k*100;
}

void solve(){
    ll l=1,r=n+1,mid;
    ret=lcm(a,b);
    sort(p+1,p+1+n,greater<ll>());
    while(l<r){
        mid=(l+r)>>1;
        if(check(mid)){
            r=mid;
        }
        else{
            l=mid+1;
        }
    }
    if(r==n+1){
        r=-1;
    }
    printf("%lld\n",r);
}

int main(void){
    scanf("%lld",&q);
    while(q--){
        scanf("%lld",&n);
        for(ll i=1;i<=n;i++){
            scanf("%lld",&p[i]);
        }
        scanf("%lld %lld %lld %lld %lld",&x,&a,&y,&b,&k);
        if(x>y){
            swap(x,y);
            swap(a,b);
        }
        solve();
    }
    return 0;
}
