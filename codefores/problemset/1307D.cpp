#include<bits/stdc++.h>

using namespace std;

#define FC ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define deb(args...) std::cerr<< "DEBUG------" << '\n'; std::cerr << #args << "------>" ; err(args)

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

const int maxn = (int)2e5 + 10;
const int inf = (int)1e9 + 10;

int n, m, k;
vector<int> e[maxn];
int special[maxn];
int d_1[maxn], d_n[maxn];
bool isv[maxn];


int main(void){
    int u, v, x;
    scanf("%d %d %d", &n, &m, &k);
    for(int i = 1; i <= k; i++){
        scanf("%d", &special[i]);
    }

    for(int i = 0; i < m; i++){
        scanf("%d %d", &u, &v);
        e[u].push_back(v);
        e[v].push_back(u);
    }

    function<void(int*, int)> bfs = [](int *d, int source){
        for(int i = 1; i <= n; i++){
            d[i] = inf;
            isv[i] = false;
        }

        d[source] = 0;
        queue<int> q;
        q.push(source);
        isv[source] = true;
        int now;

        while(!q.empty()){
            now = q.front();
            q.pop();

            for(int v : e[now]){
                if(!isv[v]){
                    d[v] = d[now] + 1;
                    isv[v] = true;
                    q.push(v);
                }
            }
        }

    };

    bfs(d_1, 1);
    bfs(d_n, n);

    vector<pii> res;
    for(int i = 1; i <= k; i++){
        int id = special[i];
        if(d_1[id] != inf && d_n[id] != inf)
            res.push_back(pii(d_1[id] - d_n[id], id));
    }

    sort(res.begin(), res.end(), [](const pii &a, const pii &b){
        return a.first<b.first;
    });

    int ans = d_1[n], tmp = -1, pre_max = -1;
    for(pii item : res){
        int id = item.second;
        // deb(id, d_1[id], d_n[id], pre_max);
        if(pre_max != -1)
            tmp = max(tmp, pre_max + d_n[id] + 1);
        pre_max = max(pre_max, d_1[id]);
    }

    // deb(ans, tmp);
    if(tmp != -1)
        ans = min(ans, tmp);
    printf("%d", ans);
    return 0;
}