#include<bits/stdc++.h>

using namespace std;

#define FC ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define deb(args...) std::cerr<<"DEBUG------"<<'\n';std::cerr<<#args<<"------>";err(args)

void err(){
    std::cerr<<'\n'<<"END OF DEBUG"<<'\n'<<'\n';
}

template<typename T,typename... Args>
void err(T a,Args... args){
    std::cerr<<a<<", ";
    err(args...);
}

template<template<typename...> class T,typename t,typename... Args>
void err(T<t> a, Args... args){
    for(auto x: a){
        std::cerr<<x<<", ";
    }
    err(args...);
}

const long double PI=acos(-1.0);  
const long double eps=1e-6;
 
using ll=long long;
using ull=unsigned long long;
using pii=pair<int,int>;
 
/*head------[@cordercorder]*/

int T;
string s[6];
bool cnt[6][30];

void solve(){
    vector<int> id={0,1,2,3,4,5};
    string ss="harbin";
    for(int i=0;i<6;i++){
        for(int j=0;j<(int)s[i].length();j++){
            cnt[i][s[i][j]-'a']=true;
        }
    }
    bool f;
    int sum;
    do{
        sum=0;
        for(int i=0;i<6;i++){
            f=cnt[id[i]][ss[i]-'a'];
            if(f)
                sum++;
        }
        if(sum==6){
            cout<<"Yes"<<'\n';
            return ;
        }
    }while(next_permutation(id.begin(),id.end()));
    cout<<"No"<<'\n';
}

int main(void){
    FC;
    cin>>T;
    while(T--){
        for(int i=0;i<6;i++){
            cin>>s[i];
        }
        solve();
        for(int i=0;i<6;i++){
            for(int j=0;j<(int)s[i].length();j++){
                cnt[i][s[i][j]-'a']=false;
            }
        }
    }
    return 0;
}
