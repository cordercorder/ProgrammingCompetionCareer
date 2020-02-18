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

int t, n, d;
int a[110];


int main(void){

    scanf("%d", &t);

    while(t--){

        scanf("%d %d", &n, &d);
        for(int i = 1; i <= n; i++){
            scanf("%d", &a[i]);
        }

        function<void(void)> solve = [](){

            if(n == 1)
                return ;

            int sum = 0;

            while(sum < d){
                if(a[2] > 0){
                    a[2]--;
                    a[1]++;
                }
                else{
                    for(int i = 3; i <= n; i++){
                        if(a[i] > 0){
                            a[i]--;
                            a[i-1]++;
                            break;
                        }
                    }
                }
                sum++;
            }
        };
        solve();
        printf("%d\n",a[1]);
    }

    return 0;
}