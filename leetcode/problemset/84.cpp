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
    int largestRectangleArea(vector<int>& heights) {
        stack<int> left, right;
        vector<int> L(heights.size()), R(heights.size());

        for(int i = 0; i < (int)heights.size(); i++){
            while(!left.empty() && heights[left.top()] >= heights[i]){
                left.pop();
            }

            if(left.empty())
                L[i] = -1;
            else
                L[i] = left.top();
            left.push(i);
        }

        for(int i = (int)heights.size() - 1; i >= 0; i--){
            while(!right.empty() && heights[right.top()] >= heights[i]){
                right.pop();
            }

            if(right.empty())
                R[i] = (int)heights.size();
            else
                R[i] = right.top();
            right.push(i);
        }

        int ans = 0;
        for(int i = 0; i < (int)heights.size(); i++){
            ans = max(ans, (R[i] - L[i] - 1) * heights[i]);
        }
        return ans;
    }
};



int main(void){
    vector<int> heights = {2,1,5,6,2,3};
    deb(Solution().largestRectangleArea(heights));
    return 0;
}