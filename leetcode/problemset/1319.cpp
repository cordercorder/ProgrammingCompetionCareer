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
        vector<int> g[n];
        bool isv[n];
        for(int i = 0; i < n; i++){
            isv[i] = false;
        }

        for(auto& item: connections){
            int u = item[0];
            int v = item[1];
            g[u].push_back(v);
            g[v].push_back(u);
        }
        int num_group = 0;

        function<void(int, int)> dfs = [&](int u, int num_group) -> void {
            isv[u] = true;
            for(auto&v : g[u]){
                if(!isv[v]){
                    dfs(v, num_group);
                }
            }
        };

        for(int i = 0; i < n; i++){
            if(!isv[i]){
                dfs(i, num_group);
                num_group ++;
            }
        }
        int need = num_group - 1;
        return need;
    }
};


int main(void){

    int n = 6;
    vector<vector<int>> connections = {{0,1},{0,2},{0,3},{1,2},{1,3}};

    deb(Solution().makeConnected(n, connections));


    return 0;
}