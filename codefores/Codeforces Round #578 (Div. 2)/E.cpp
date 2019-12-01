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
const long long maxw=(long long)1e17+(long long)10;
 
using ll=long long;
using ull=unsigned long long;
using pii=pair<int,int>;
 
/*head------[@cordercorder]*/

const int maxn=(int)1e6+10;

int n;
string s;
int nxt[maxn],extend[maxn];
int len;
vector<string> rev;

void pre_kmp(const string &ss){
    nxt[0]=(int)ss.length();
    int j=0;
    while(j+1<(int)ss.length()&&ss[j]==ss[j+1]){
        j++;
    }
    nxt[1]=j;
    int k=1;
    for(int i=2;i<(int)ss.length();i++){
        int p=nxt[k]+k-1;
        int L=nxt[i-k];
        if(i+L<p+1){
            nxt[i]=L;
        }
        else{
            j=max(0,p-i+1);
            while(i+j<(int)ss.length()&&ss[i+j]==ss[j]){
                j++;
            }
            nxt[i]=j;
            k=i;
        }
    }
}

void ekmp(const string &s1,const string &s2){
    pre_kmp(s1);
    int j=0;
    while(j<(int)s2.length()&&j<(int)s1.length()&&s1[j]==s2[j]){
        j++;
    }
    extend[0]=j;
    int k=0;
    for(int i=1;i<(int)s2.length();i++){
        int p=extend[k]+k-1;
        int L=nxt[i-k];
        if(i+L<p+1){
            extend[i]=L;
        }
        else{
            j=max(0,p-i+1);
            while(i+j<(int)s2.length()&&j<(int)s1.length()&&s2[i+j]==s1[j]){
                j++;
            }
            extend[i]=j;
            k=i;
        }
    }
}

void solve(){
    string now=rev[0],tmp;
    for(int i=1;i<(int)rev.size();i++){
        tmp=now.substr(max(0,(int)now.length()-(int)rev[i].length()),(int)rev[i].length());
        ekmp(rev[i],tmp);
        len=0;
        for(int j=0;j<(int)tmp.length();j++){
            if((int)tmp.length()==extend[j]+j){
                len=extend[j];
                break;
            }
        }
        now+=rev[i].substr(len,(int)rev[i].length()-len);
    }
    cout<<now<<'\n';
}

int main(void){
    FC;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>s;
        rev.push_back(s);
    }
    solve();
    return 0;
}
