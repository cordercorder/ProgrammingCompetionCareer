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
        int count[26];
        memset(count, 0, sizeof(count));
        
        bool f = true;
        int l = 0, r = 0, ans = 0, max_item = 0;
        while(true){
            f = true;
            while(r < (int)s.length()){
                count[s[r] - 'A'] ++;
                max_item = max(max_item, count[s[r] - 'A']);
                r ++;
                if((r - l) - max_item > k){
                    ans = max(ans, r - l - 1);
                    f = false;
                    break;
                }
            }
            if(f){
                ans = max(ans, r - l);
                break;
            }
            count[s[l] - 'A'] --;
            l ++;
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