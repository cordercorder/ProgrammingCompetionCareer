#include<bits/stdc++.h>

using namespace std;

#define FC ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define deb(args...) std::cerr<<"DEBUG------"<<'\n'; std::cerr<<#args<<"------>"; err(args)

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

const long double PI = acos(-1.0);  
const long double eps = 1e-6;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int,int>;

/*head------[@cordercorder]*/

const int maxn = 5010;

struct node{
    int a;
    int b;
    int g;
};

int n, m;
int ma[maxn][maxn];
vector<node> description;
vector<int> e[maxn];
vector<pii> edges;

int main(void){
    int u, v, a, b, g;
    scanf("%d", &n);

    for(int i = 1; i < n; i++){
        scanf("%d %d", &u, &v);
        edges.push_back(pii(u, v));
        e[u].push_back(v);
        e[v].push_back(u);
        ma[u][v] = 1000000;
        ma[v][u] = 1000000;
    }

    scanf("%d", &m);
    for(int i = 0; i < m; i++){
        scanf("%d %d %d", &a, &b, &g);
        description.push_back({a, b, g});
    }

    sort(description.begin(), description.end(), [](const node &a, const node &b){
        return a.g > b.g;
    });

    function<bool(int, int, int, int)> find_path = [&find_path](int u, int pre, int target, int weight){
        if(u == target){
            return true;
        }
        for(int v : e[u]){
            if(v == pre)
                continue;

            if(find_path(v, u, target, weight)){
                if(ma[u][v] == 1000000){
                    ma[u][v] = weight;
                    ma[v][u] = weight;
                }
                return true;
            }
        }
        return false;
    };

    for(node item : description){
        find_path(item.a, -1, item.b, item.g);
    }

    int min_w;
    function<bool(int, int, int)> check = [&check, &min_w](int u, int pre, int target){
        if(u == target){
            return true;
        }
        int v;
        for(int v : e[u]){
            if(v == pre)
                continue;

            if(check(v, u, target)){
                min_w = min(min_w, ma[u][v]);
                return true;
            }
        }
        return false;
    };

    for(node item : description){
        min_w = 1000000;
        check(item.a, -1, item.b);
        if(min_w != item.g){
            printf("-1");
            return 0;
        }
    }
    for(pii item : edges){
        printf("%d ",ma[item.first][item.second]);
    }

    return 0;
}