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
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int, int>> my_nums((int)nums.size());
        for(int i = 0; i < (int)nums.size(); i++){
            my_nums[i] = pair<int, int>(nums[i], i);
        }

        sort(my_nums.begin(), my_nums.end());

        auto find = [&](int x) -> int{
            int l = 0, r = (int)my_nums.size();
            while(l < r){
                int mid = (l + r) >> 1;
                if(my_nums[mid].first < x){
                    l = mid + 1;
                }
                else{
                    r = mid;
                }
            }
            return l;
        };

        for(int i = 0; i < (int)my_nums.size(); i++){
            int y = target - my_nums[i].first;

            if(y == my_nums[i].first){
                if((i + 1) < (int)my_nums.size() && my_nums[i + 1].first == y){
                    vector<int> ret = {my_nums[i].second, my_nums[i + 1].second};
                    return ret;
                }
                continue;
            }

            int pos = find(y);
            if(pos < (int)my_nums.size() && my_nums[pos].first == y){
                vector<int> ret = {my_nums[i].second, my_nums[pos].second};
            
                return ret;
            }
        }
        return {0, 1};
    }
};


int main(void){

    int target = 9;
    vector<int> nums = {2,7,11,15};

    deb(Solution().twoSum(nums, target));

    int target2 = 6;
    vector<int> nums2 = {3,2,4};
    deb(Solution().twoSum(nums2, target2));

    int target3 = 6;
    vector<int> nums3 = {3,3};
    deb(Solution().twoSum(nums3, target3));

    return 0;
}