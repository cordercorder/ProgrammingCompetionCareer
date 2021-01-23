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
    vector<int> decode(vector<int>& encoded) {
        int n = (int)encoded.size() + 1;
        int s = 0;
        for(int i = 1; i <= n; i++)
            s ^= i;
        int res = 0, tmp = encoded[0], prefix_s[n];
        res = encoded[0];
        prefix_s[1] = encoded[0];

        for(int i = 1; i < (int)encoded.size(); i++){
            tmp ^= encoded[i];
            res ^= tmp;
            prefix_s[i + 1] = tmp;
        }

        vector<int> ans(n);
        ans[0] = res ^ s;
        for(int i = 1; i < n; i++){
            ans[i] = prefix_s[i] ^ ans[0];
        }
        return ans;
    }
};


int main(void){

    vector<int> encoded = {6,5,4,6};
    
    deb(Solution().decode(encoded));
    return 0;
}