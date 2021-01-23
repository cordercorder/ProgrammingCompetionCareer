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
    int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships) {
        bool flag[(int)languages.size()][n + 1];

        for(int i = 0; i < (int)languages.size(); i++){
            for(int j = 0; j <= n; j++)
                flag[i][j] = false;
        }

        for(int i = 0; i < (int)languages.size(); i++){
            for(auto& j: languages[i]){
                flag[i][j] = true;
            }
        }

        int ans = (int)languages.size() + 10;

        for(int i = 1; i <= n; i++){

            vector<int> people;
            for(auto& item: friendships){
                int u = item[0] - 1;
                int v = item[1] - 1;

                bool has_common = false;

                for(int j = 1; j <= n; j++){
                    if(flag[u][j] && flag[v][j]){
                        has_common = true;
                        break;
                    }
                }

                if(!has_common){
                    if(!flag[u][i]){
                        flag[u][i] = true;
                        people.push_back(u);
                    }
                    if(!flag[v][i]){
                        flag[v][i] = true;
                        people.push_back(v);
                    }
                }
            }
            // deb(people);
            ans = min(ans, (int)people.size());
            for(auto& p: people){
                flag[p][i] = false;
            }
        }

        return ans;
    }
};



int main(void){
    int n = 3;
    vector<vector<int>> languages = {{2},{1,3},{1,2},{3}};
    vector<vector<int>> friendships = {{1,4},{1,2},{3,4},{2,3}};
        
    deb(Solution().minimumTeachings(n, languages, friendships));

    int n2 = 17;
    vector<vector<int>> languages2 = {{4,7,2,14,6},{15,13,6,3,2,7,10,8,12,4,9},{16},{10},{10,3},{4,12,8,1,16,5,15,17,13},{4,13,15,8,17,3,6,14,5,10},{11,4,13,8,3,14,5,7,15,6,9,17,2,16,12},{4,14,6},{16,17,9,3,11,14,10,12,1,8,13,4,5,6},{14},{7,14},{17,15,10,3,2,12,16,14,1,7,9,6,4}};
    vector<vector<int>> friendships2 = {{4,11},{3,5},{7,10},{10,12},{5,7},{4,5},{3,8},{1,5},{1,6},{7,8},{4,12},{2,4},{8,9},{3,10},{4,7},{5,12},{4,9},{1,4},{2,8},{1,2},{3,4},{5,10},{2,7},{1,7},{1,8},{8,10},{1,9},{1,10},{6,7},{3,7},{8,12},{7,9},{9,11},{2,5},{2,3}};
    deb(Solution().minimumTeachings(n2, languages2, friendships2));

    return 0;
}