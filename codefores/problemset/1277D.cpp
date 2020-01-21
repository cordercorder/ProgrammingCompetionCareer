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

// #define local

const int maxn=(int)2e5+10;

int t,n;
string s[maxn];

void solve(){
    vector<int> id;
    map<string,bool> isv;
    for(int i=1;i<=n;i++){
        if((int)s[i].length()>=2){
            if(s[i][0]!=s[i].back()){
                id.push_back(i);
                isv[s[i]]=true;
            }
        }
    }
    if(id.empty()){
        int cnt=0;
        for(int i=1;i<=n;i++){
            if(s[i][0]=='0'){
                cnt++;
            }
        }
        if(cnt==n||cnt==0){
            cout<<"0"<<'\n';
        }
        else{
            cout<<"-1"<<'\n';
        }
    }
    else{
        int sum[2]={0,0};
        vector<int> ls[2];
        for(int to:id){
            if(s[to][0]=='0'&&s[to].back()=='1'){
                sum[0]++;
                ls[0].push_back(to);
            }
            else{
                sum[1]++;
                ls[1].push_back(to);
            }
        }
        int x=abs(sum[0]-sum[1]);
        if(x<=1){
            cout<<"0"<<'\n';
        }
        else{
            if(sum[0]>sum[1]){
                int k=(sum[0]-sum[1])/2,cnt=0;
                string tmp;
                vector<int> ans;
                for(int i=0;i<(int)ls[0].size()&&cnt<k;i++){
                    tmp=s[ls[0][i]];
                    reverse(tmp.begin(),tmp.end());
                    if(isv[tmp]){
                        continue;
                    }
                    else{
                        ans.push_back(ls[0][i]);
                        cnt++;
                    }
                }
                if(cnt==k){
                    cout<<cnt<<'\n';
                    for(int i=0;i<cnt;i++){
                        cout<<ans[i]<<" ";
                    }
                    cout<<'\n';
                }
                else{
                    cout<<"-1"<<'\n';
                }
            }
            else{
                int k=(sum[1]-sum[0])/2,cnt=0;
                string tmp;
                vector<int> ans;
                for(int i=0;i<(int)ls[1].size()&&cnt<k;i++){
                    tmp=s[ls[1][i]];
                    reverse(tmp.begin(),tmp.end());
                    if(isv[tmp]){
                        continue;
                    }
                    else{
                        ans.push_back(ls[1][i]);
                        cnt++;
                    }
                }
                if(cnt==k){
                    cout<<cnt<<'\n';
                    for(int i=0;i<k;i++){
                        cout<<ans[i]<<" ";
                    }
                    cout<<'\n';
                }
                else{
                    cout<<"-1"<<'\n';
                }
            }
        }
    }
}

int main(void){

#ifdef local
    freopen("a.in","r",stdin);
#endif
    FC;
    cin>>t;
    while(t--){
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>s[i];
        }
        solve();
    }
    return 0;
}