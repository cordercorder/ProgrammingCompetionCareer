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

const int maxn=(int)1e6+10;

char s[maxn],str[maxn];
int n;
int ans[maxn];
int T[maxn<<2],add[maxn<<2],Tmin[maxn<<2];
bool isv[maxn];

void pushdown(int rt){
    if(add[rt]!=0){
        T[rt<<1]+=add[rt];
        T[rt<<1|1]+=add[rt];
        Tmin[rt<<1]+=add[rt];
        Tmin[rt<<1|1]+=add[rt];
        add[rt<<1]+=add[rt];
        add[rt<<1|1]+=add[rt];
        add[rt]=0;
    }
}

void upd(int rt,int l,int r,int L,int R,int val){
    if(l==L&&R==r){
        T[rt]+=val;
        Tmin[rt]+=val;
        add[rt]+=val;
        return ;
    }
    pushdown(rt);
    int mid=(l+r)>>1;
    if(R<=mid)
        upd(rt<<1,l,mid,L,R,val);
    else if(L>mid)
        upd(rt<<1|1,mid+1,r,L,R,val);
    else{
        upd(rt<<1,l,mid,L,mid,val);
        upd(rt<<1|1,mid+1,r,mid+1,R,val);
    } 
    T[rt]=max(T[rt<<1],T[rt<<1|1]);
    Tmin[rt]=min(Tmin[rt<<1],Tmin[rt<<1|1]);
}

int cal(int rt,int l,int r,int L,int R,bool f){
    if(l==L&&R==r){
        if(f)
            return T[rt];
        else
            return Tmin[rt];
    }
    pushdown(rt);
    int mid=(l+r)>>1;
    if(R<=mid)
        return cal(rt<<1,l,mid,L,R,f);
    else if(L>mid)
        return cal(rt<<1|1,mid+1,r,L,R,f);
    else{
        if(f){
            return max(cal(rt<<1,l,mid,L,mid,f),cal(rt<<1|1,mid+1,r,mid+1,R,f));
        }
        else{
            return min(cal(rt<<1,l,mid,L,mid,f),cal(rt<<1|1,mid+1,r,mid+1,R,f)); 
        }
    }
}

void solve(){
    int pos=1,cnt=0;
    for(int i=1;i<=n;i++){
        if(s[i]=='L'){
            pos--;
            pos=max(pos,1);
        }
        else if(s[i]=='R'){
            pos++;
        }
        else{
            if(s[i]=='('){
                if(!isv[pos]){
                    upd(1,1,n,pos,n,1);
                    isv[pos]=true;
                }
                else{
                    if(str[pos]==')'){
                        upd(1,1,n,pos,n,2);
                    }
                    else if(str[pos]!='('){
                        upd(1,1,n,pos,n,1);
                    }
                }
            }
            else if(s[i]==')'){
                if(!isv[pos]){
                    upd(1,1,n,pos,n,-1);
                    isv[pos]=true;
                }
                else{
                    if(str[pos]=='('){
                        upd(1,1,n,pos,n,-2);
//                        deb(pos,i);
                    }
                    else if(str[pos]!=')'){
                        upd(1,1,n,pos,n,-1);
                    }
                }
            }
            else{
                if(!isv[pos]){
                    isv[pos]=true;
                }
                else{
                    if(str[pos]=='('){
                        upd(1,1,n,pos,n,-1);
                    }
                    else if(str[pos]==')'){
                        upd(1,1,n,pos,n,1);
                    }
//                    deb(pos,i);
//                    deb(str[pos]);
                }
            }
            str[pos]=s[i];
        }
        if(cal(1,1,n,n,n,true)==0&&cal(1,1,n,1,n,false)>=0){
            ans[i]=T[1];
        }
        else{
            ans[i]=-1;
        }
    }
    for(int i=1;i<=n;i++){
        if(i>1)
            printf(" ");
        printf("%d",ans[i]);
    }
}

int main(void){
    scanf("%d",&n);
    getchar();
    for(int i=1;i<=n;i++)
        s[i]=getchar();
    solve();
    return 0;
}
