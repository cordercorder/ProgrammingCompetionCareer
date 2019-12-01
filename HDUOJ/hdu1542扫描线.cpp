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

const int maxn=210;//�ռ�ǵÿ����� 

struct node{
    double l;//��˵� 
    double r;//�Ҷ˵� 
    double h;//�߶� 
    int d;// dΪ��߻���߱��, 1���, -1���� 
    bool operator<(const node &a)const{
        return h<a.h;
    }
}; 
node res[maxn];
double Hash[maxn];
int n,cnt,tot;
int add[maxn<<2];
double len[maxn<<2];//ÿһ���ڵ�[L,R]ά��x[R+1]-x[L]��ֵ 

void pushup(int rt,int l,int r){
    if(add[rt]){
        len[rt]=Hash[r+1]-Hash[l];
    }
    else{
        if(l==r){
            len[rt]=0;
        }
        else{
            len[rt]=len[rt<<1]+len[rt<<1|1];
        }
    }
}

void update(int rt,int l,int r,int L,int R,int val){
    if(L==l&&R==r){
        add[rt]+=val;
        pushup(rt,l,r);
        return ;
    }
    int mid=(l+r)>>1;
    if(R<=mid){
        update(rt<<1,l,mid,L,R,val);
    }
    else if(L>mid){
        update(rt<<1|1,mid+1,r,L,R,val);
    }
    else{
        update(rt<<1,l,mid,L,mid,val);
        update(rt<<1|1,mid+1,r,mid+1,R,val);
    }
    pushup(rt,l,r);
}

int main(void){
    int ca=0;
    double x1,x2,y1,y2,ans;
    int l,r;
    while(scanf("%d",&n)!=EOF){
        if(n==0){
            break;
        } 
        cnt=0;
        tot=0;
        ans=0.0;
        ca++;
        for(int i=0;i<n;i++){
            scanf("%lf %lf %lf %lf",&x1,&y1,&x2,&y2);
            res[cnt++]={x1,x2,y1,1};
            res[cnt++]={x1,x2,y2,-1};
            Hash[tot++]=x1;
            Hash[tot++]=x2;
        }
        sort(res,res+cnt);//���ո߶����� 
        sort(Hash,Hash+tot);//��ɢ�� 
        tot=unique(Hash,Hash+tot)-Hash;//ȥ�� 
        printf("Test case #%d\n",ca);
        for(int i=0;i<cnt;i++){
            l=lower_bound(Hash,Hash+tot,res[i].l)-Hash;
            r=lower_bound(Hash,Hash+tot,res[i].r)-Hash-1;//�ǵ�-1 
            update(1,0,tot-1,l,r,res[i].d);//����tot-1��tot-2���ɣ�ϰ����tot-1 
            ans+=len[1]*(res[i+1].h-res[i].h);
        } 
        printf("Total explored area: %.2f\n\n",ans);
    }
    return 0;
}
