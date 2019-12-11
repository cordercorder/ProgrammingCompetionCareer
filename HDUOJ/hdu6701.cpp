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

const int maxn=(int)3e5+10;

int T,n,k;
int a[maxn];
int arr[maxn][25],Log[maxn],arr_pos[maxn][25];
int posl[maxn],posr[maxn];
bool isv[maxn];

void handle(){
    Log[0]=-1;
    for(int i=1;i<=n;i++){
        arr[i][0]=a[i];
        arr_pos[i][0]=i;
        Log[i]=Log[i/2]+1;
    }
    for(int j=1;(1<<j)<=n;j++){
        for(int i=1;i+(1<<j)-1<=n;i++){
            if(arr[i][j-1]>=arr[i+(1<<(j-1))][j-1]){
                arr_pos[i][j]=arr_pos[i][j-1];
                arr[i][j]=arr[i][j-1];
            }
            else{
                arr[i][j]=arr[i+(1<<(j-1))][j-1];
                arr_pos[i][j]=arr_pos[i+(1<<(j-1))][j-1];
            }
        }
    }
    int pos=0;
    for(int i=1;i<=n;i++){
        while(pos<n){
            if(isv[a[pos+1]]){
                break;
            }
            pos++;
            isv[a[pos]]=true;
        }
        isv[a[i]]=false;
        posr[i]=pos;
    }
    pos=n+1;
    for(int i=n;i>=1;i--){
        while(pos>1){
            if(isv[a[pos-1]]){
                break;
            }
            pos--;
            isv[a[pos]]=true;
        }
        isv[a[i]]=false;
        posl[i]=pos;
    }
}

int query(int l,int r){
    int k=Log[r-l+1];
    if(arr[l][k]>=arr[r-(1<<k)+1][k])
        return arr_pos[l][k];
    return arr_pos[r-(1<<k)+1][k];
}

ll Div(ll l,ll r){
    if(l==r){
        return a[l]-1<=k;
    }
    if(r<l)
        return 0;
    ll pos=query(l,r),ans=0;
    if(pos-l<r-pos){
        for(ll i=l;i<=pos;i++){
            ll R=a[pos]+i-1-k;
            R=max(pos,R);
            ll tmpr=min(r,(ll)posr[i]);
            if(tmpr>=R){
                ans+=tmpr-R+1;
            }
        }
    }
    else{
        for(ll i=pos;i<=r;i++){
            ll L=k-a[pos]+i+1;
            L=min(L,pos);
            ll tmpl=max(l,(ll)posl[i]);
            if(L>=tmpl){
                ans+=L-tmpl+1;
            }
        }
    }
    ans+=Div(l,pos-1);
    ans+=Div(pos+1,r);
    return ans;
}

void solve(){
    handle();
    printf("%lld\n",Div(1,n));
}

int main(void){
    scanf("%d",&T);
    while(T--){
        scanf("%d %d",&n,&k);
        for(int i=1;i<=n;i++)
            scanf("%d",&a[i]);
        solve();
    }
    return 0;
}