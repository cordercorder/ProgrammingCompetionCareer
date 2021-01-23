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
    int tupleSameProduct(vector<int>& nums) {
        // vector<int> ab;
        map<int, int> my_nums;
        for(int i = 0; i < (int)nums.size(); i++){
            for(int j = i + 1; j < (int)nums.size(); j++){
                my_nums[nums[i] * nums[j]] ++;
            }
        }
        int ans = 0;
        for(auto& item: my_nums){
            // deb(item.first);
            ans += 4 * item.second * (item.second - 1);
        }
        // deb(my_nums);
        return ans;
    }
};



int main(void){
    vector<int> nums = {2,3,4,6};
    
    deb(Solution().tupleSameProduct(nums));

    return 0;
}