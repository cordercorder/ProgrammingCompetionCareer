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

template<typename T>
void _read(T &ret){
	char ch=getchar();
	bool f=0;
    ret=0;
    while(ch<'0'||ch>'9'){
    	if(ch=='-'){
    		f=1;
		}
    	ch=getchar();
	}
    while(ch>='0'&&ch<='9'){
    	ret=ret*10+(ch-'0');
    	ch=getchar();
	}
    if(f)
    	ret=-ret;
}

template<typename T>
void print(T ret){
	if(ret<0){
		putchar('-');
		ret=-ret;
	}
	if(ret>9){
		print(ret/10);
	}
	putchar(ret%10+'0');
}

int N,M;

struct PT{
    int l;
    int r;
    int v;
}T[maxn*50];
int root[maxn],a[maxn],tot;

int create(int l,int r){
    int pos=++tot;
    if(l==r){
        T[pos].v=a[l];
        return pos;
    }
    int mid=(l+r)>>1;
    T[pos].l=create(l,mid);
    T[pos].r=create(mid+1,r);
    return pos;
}

// modify element in position p of edition edi
int update(int edi,int l,int r,int p,int val){
    int pos=++tot;
    if(l==r){
        T[pos].v=val;
        return pos;
    }
    T[pos]=T[edi];
    int mid=(l+r)>>1;
    if(p<=mid){
        T[pos].l=update(T[edi].l,l,mid,p,val);
    }
    else{
        T[pos].r=update(T[edi].r,mid+1,r,p,val);
    }
    return pos;
}

//search the element in position p of edition edi
int cal(int edi,int l,int r,int p){
    if(l==r){
        return T[edi].v;
    }
    int mid=(l+r)>>1;
    if(p<=mid){
        return cal(T[edi].l,l,mid,p);
    }
    else{
        return cal(T[edi].r,mid+1,r,p);
    }
}

int main(void){
    int v,loc,value,tmp;
    _read(N),_read(M);
    for(int i=1;i<=N;i++){
        _read(a[i]);
    }
    tot=0;
    root[0]=create(1,N);
    for(int i=1;i<=M;i++){
        _read(v),_read(tmp);
        if(tmp==1){
            _read(loc),_read(value);
            root[i]=update(root[v],1,N,loc,value);
        }
        else{
            _read(loc);
            root[i]=root[v];
            print(cal(root[v],1,N,loc));
            putchar('\n');
        }
    }
    
    return 0;
}
