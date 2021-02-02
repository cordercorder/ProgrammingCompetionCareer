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
    int characterReplacement(string s, int k) {
        int count[(int)s.length() + 10][26];
        memset(count, 0, sizeof(count));
        for(int i = 0; i < (int)s.length(); i++){
            for(int j = 0; j < 26; j++){
                count[i + 1][j] = count[i][j] + ((s[i] - 'A') == j);
            }
        }

        auto find = [&](int col, int value){
            int l = 1, r = (int)s.length() + 1, mid;
            while(l < r){
                mid = (l + r) >> 1;
                if(mid - count[mid][col] <= value){
                    l = mid + 1;
                }
                else{
                    r = mid;
                }
            }
            return l - 1;
        };

        int ans = 0;
        for(int j = 0; j < 26; j++){
            for(int i = 0; i < (int)s.length(); i++){
                int tmp = k + i - count[i][j];
                int pos = find(j, tmp);
                ans = max(ans, pos - i);
            }
        }
        return ans;
    }
};



int main(void){

    string s1 = "ABAB";
    int k1 = 2;

    deb(Solution().characterReplacement(s1, k1));
    string s2 = "AABABBA";
    int k2 = 1;
    deb(Solution().characterReplacement(s2, k2));

    return 0;
}