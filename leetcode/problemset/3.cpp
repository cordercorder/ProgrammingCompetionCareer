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
    int lengthOfLongestSubstring(string s) {
        map<char, int> cnt;

        int l = 0, r = 0, ans = 0;
        while(true){
            while(r < (int)s.length() && cnt[s[r]] == 0){
                cnt[s[r]] = 1;
                r ++;
            }
            // deb(l, r);
            ans = max(ans, r - l);
            if(r == (int)s.length()){
                break;
            }

            cnt[s[l]] --;
            l++;
        }
        return ans;
    }
};


int main(void){

    string s = "abcabcbb";
    deb(Solution().lengthOfLongestSubstring(s));
    

    string s2 = "bbbbb";
    deb(Solution().lengthOfLongestSubstring(s2));


    string s3 = "pwwkew";
    deb(Solution().lengthOfLongestSubstring(s3));
    string s4 = "";
    deb(Solution().lengthOfLongestSubstring(s4));
    return 0;
}