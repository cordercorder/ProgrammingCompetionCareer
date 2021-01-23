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

    int makeConnected(int n, vector<vector<int>>& connections) {
        if((int)connections.size() < n - 1){
            return -1;
        }
        int pre[n];
        for(int i = 0; i < n; i++){
            pre[i] = -1;
        }

        function<int(int)> find = [&](int u) -> int{
            return pre[u] == -1? u : pre[u] = find(pre[u]);
        };

        auto merge = [&](int u, int v) -> void{
            int nu = find(u);
            int nv = find(v);
            if(nu != nv){
                pre[nu] = nv;
            }
        };
        
        for(auto& item: connections){
            int u = item[0];
            int v = item[1];
            merge(u, v);
        }
        int cnt = 0;
        for(int i = 0; i < n; i++){
            if(pre[i] == -1)
                cnt ++;
        }
        return cnt - 1;
    }
};


int main(void){

    int n = 6;
    vector<vector<int>> connections = {{0,1},{0,2},{0,3},{1,2},{1,3}};

    deb(Solution().makeConnected(n, connections));


    return 0;
}