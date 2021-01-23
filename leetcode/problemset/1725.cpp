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
    int countGoodRectangles(vector<vector<int>>& rectangles) {
        int max_len = 0;
        for(auto& item: rectangles){
            int val = min(item[0], item[1]);
            max_len = max(max_len, val);
        }
        int ans = 0;
        for(auto& item: rectangles){
            int val = min(item[0], item[1]);
            if(max_len == val){
                ans ++;
            }
        }
        return ans;
    }
};



int main(void){

    
    

    return 0;
}