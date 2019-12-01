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

const ll maxn=(ll)2e5+10ll;

ll q,n; 
char s[maxn],t[maxn];
ll cnt[30][2],arr[30];

ll lowbit(ll x){
    return x&(-x);
}

void add(ll x,ll val){
    while(x<=26){
        arr[x]+=val;
        x+=lowbit(x);
    }
}

ll cal(ll x){
    ll ans=0;
    while(x>0){
        ans+=arr[x];
        x-=lowbit(x);
    }
    return ans;
}

ll Count(char *ss){
    ll ans=0;
    for(ll i=1;i<=n;i++){
        ans+=cal(26)-cal(ss[i]-'a');
        add(ss[i]-'a'+1,1);
    }
    for(ll i=1;i<=26;i++){
        arr[i]=0;
    }
    return ans;
}

void solve(){
    for(ll i=1;i<=n;i++){
        cnt[s[i]-'a'][0]++;
    }
    for(ll i=1;i<=n;i++){
        cnt[t[i]-'a'][1]++;
    }
    for(ll i=0;i<26;i++){
        if(cnt[i][0]!=cnt[i][1]){
            puts("NO");
            return ;
        }
    }
    for(ll i=0;i<26;i++){
        if(cnt[i][0]>1){
            puts("YES");
            return ;
        }
    }
    ll inversionS=Count(s),inversionT=Count(t);
//    deb(inversionS,inversionT);
    if(inversionS%2==inversionT%2){
        puts("YES");
    }
    else{
        puts("NO");
    }
}

int main(void){
    scanf("%lld",&q);
    while(q--){
        scanf("%lld",&n);
        scanf("%s %s",s+1,t+1);
        solve();
        for(ll i=0;i<26;i++){
            for(ll j=0;j<2;j++){
                cnt[i][j]=0;
            }
        }
    }
    return 0;
}
