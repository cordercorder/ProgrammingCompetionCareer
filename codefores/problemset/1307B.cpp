#include<bits/stdc++.h>

using namespace std;

#define FC ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define deb(args...) std::cerr<< "DEBUG------" << '\n'; std::cerr << #args << "------>" ; err(args)

void err(){
    std::cerr << '\n' << "END OF DEBUG" << '\n' << '\n';
}

template<typename T, typename... Args>
void err(T a, Args... args){
    std::cerr << a << ", ";
    err(args...);
}

template<template<typename...> class T, typename t, typename... Args>
void err(T<t> a, Args... args){
    for(auto x: a){
        std::cerr << x << ", ";
    }
    err(args...);
}

const long double PI = acos(-1.0);  
const long double eps = 1e-6;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int,int>;

/*head------[@cordercorder]*/

const int maxn = (int)1e5 + 10;

int t;
ll n, x;
set<ll> favorite;


int main(void){

    scanf("%d", &t);

    while(t--){

        ll tmp;

        scanf("%lld %lld", &n, &x);

        for(int i = 1; i <= n; i++){
            scanf("%lld", &tmp);
            favorite.insert(tmp);
        }

        auto is_find = favorite.find(x);
        if(is_find != favorite.end()){
            puts("1");
        }
        else{
            ll tmp = *(--favorite.end());
            ll ans = x / tmp;
            if(x % tmp != 0){
                ans++;
            }

            ans = max(ans, 2ll);
            printf("%lld\n", ans);

        }

        favorite.clear();
    }

    return 0;
}