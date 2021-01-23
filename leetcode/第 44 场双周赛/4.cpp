#include<bits/stdc++.h>

using namespace std;

#define FC ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define deb(args...) std::cerr << "DEBUG------" << '\n'; std::cerr << #args << "------>"; err(args)

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
//header

class Solution {
public:

    using ll=long long;
    using pii=pair<int,int>;

    vector<int> waysToFillArray(vector<vector<int>>& queries) {
        const int mod = 1000000007;
        const int N = 20000;

        ll F[N], Finv[N], inv[N];
        auto init = [&](){
            inv[1] = 1;
            for(int i = 2; i < N; i++){
                inv[i] = (mod - mod / i) * 1ll * inv[mod % i] % mod;
            }
            F[0] = Finv[0] = 1;
            for(int i = 1; i < N; i++){
                F[i] = F[i-1] * 1ll * i % mod;
                Finv[i] = Finv[i-1] * 1ll * inv[i] % mod;
            }
        };

        auto comb = [&](int n, int m) ->ll {
            if(m < 0 || m > n)
                return 0;
            return F[n] * 1ll *Finv[n-m] % mod * Finv[m] % mod;
        };

        auto factorize = [](int x) -> vector<pii>{
            vector<pair<int, int>> ans;
            for(int i = 2; i * i <= x; i++){
                if(x % i == 0){
                    int cnt = 0;
                    while(x % i == 0){
                        x /= i;
                        cnt ++;
                    }
                    ans.push_back(pii(i, cnt));
                }
            }
            if(x != 1){
                ans.push_back(pii(x, 1));
            }
            return ans;
        };

        init();

        vector<int> answer;

        for(auto& query: queries){
            int n = query[0];
            int k = query[1];
            auto fac = factorize(k);
            ll ans = 1;

            for(auto& item: fac){
                ans = ans * comb(item.second + n - 1, n - 1) % mod;
            }
            answer.push_back((int)ans);
        }
        return answer;
    }
};



int main(void){

    
    vector<vector<int>> queries = {{2,6},{5,1},{73,660}};
    deb(Solution().waysToFillArray(queries));

    vector<vector<int>> queries2 = {{1,1},{2,2},{3,3},{4,4},{5,5}};
    deb(Solution().waysToFillArray(queries2));
    return 0;
}