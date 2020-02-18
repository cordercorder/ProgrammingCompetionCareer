#include<bits/stdc++.h>

using namespace std;

#define FC ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define deb(args...) std::cerr<< "DEBUG------" << '\n'; std::cerr << #args << "------>"; err(args)

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

char s[maxn];
ll f[2][26][26], cnt[26], n;

int main(void){
    scanf("%s", s+1);
    n = strlen(s+1);

    function<ll(void)> solve = [](){

        for(ll i = 1; i <= n; i++){
            ll tmp = s[i] - 'a';
            for(ll j = 0; j < 26; j++){
                for(ll k = 0; k < 26; k++){
                    f[i%2][j][k] = f[(i-1)%2][j][k];
                }
            }
            for(ll j = 0; j < 26; j++){
                f[i%2][j][tmp] += cnt[j];
            }
            cnt[tmp]++;
        }

        ll ans = 0;
        for(ll i = 0; i < 26; i++){
            ans = max(ans, cnt[i]);
            for(ll j = 0; j < 26; j++){
                ans = max(ans, f[n%2][i][j]);
            }
        }

        return ans;
    };

    printf("%lld", solve());
    return 0;
}