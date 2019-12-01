#include<bits/stdc++.h>

using namespace std;

#define FC ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define FIN freopen("in.txt","r",stdin)
#define FOUT freopen("out.txt","w",stdout)
#define deb(x) cerr<<"DEBUG------"<<'\n';cerr<<#x<<"------>";err(x)

template<typename T>
void err(T a){
    for(auto i:a){
        cerr<<i<<" ";
    }
    cerr<<'\n'<<"END OF DEBUG"<<'\n'<<'\n';
}
void err(int a){
    cerr<<a<<'\n';
    cerr<<"END OF DEBUG"<<'\n'<<'\n';
}

const long double PI=acos(-1.0);  
const long double eps=1e-6;
const long long maxw=(long long)1e17+(long long)10;

using ll=long long;
using ull=unsigned long long;
using pii=pair<int,int>; 

/*head------[@cordercorder]*/

const int maxn=(int)1e5+10;

int a[maxn];
int n,m;
int l,r,k,x;
int T[2][maxn<<2],add[maxn<<2];
ll sum[maxn<<2];

void pushup(int rt){
    T[0][rt]=max(T[0][rt<<1],T[0][rt<<1|1]);
    T[1][rt]=min(T[1][rt<<1],T[1][rt<<1|1]);
    sum[rt]=sum[rt<<1]+sum[rt<<1|1];
}

void create(int rt,int l,int r){
    if(l==r){
        T[0][rt]=a[l];
        T[1][rt]=a[l];
        sum[rt]=a[l];
        return ;
    }
    int mid=(l+r)>>1;
    create(rt<<1,l,mid);
    create(rt<<1|1,mid+1,r);
    pushup(rt);
}

void pushdown(int rt,int l,int r){
    if(add[rt]){
        int mid=(l+r)>>1;
        T[0][rt<<1]%=add[rt];
        T[0][rt<<1|1]%=add[rt];
        T[1][rt<<1]%=add[rt];
        T[1][rt<<1|1]%=add[rt];
        sum[rt<<1]=(ll)T[0][rt<<1]*(ll)(mid-l+1);
        sum[rt<<1|1]=(ll)T[0][rt<<1|1]*(ll)(r-mid);
        add[rt<<1]=add[rt];
        add[rt<<1|1]=add[rt];
        add[rt]=0;
    }
}

void update(int rt,int l,int r,int pos){
    if(l==r){
        T[0][rt]=x;
        T[1][rt]=x;
        sum[rt]=x;
        return ;
    }
    pushdown(rt,l,r);
    int mid=(l+r)>>1;
    if(pos<=mid){
        update(rt<<1,l,mid,pos);
    }
    else{
        update(rt<<1|1,mid+1,r,pos);
    }
    pushup(rt);
}

void update(int rt,int l,int r,int L,int R){
    if(T[0][rt]<x)
        return ;
    if(l==L&&R==r&&T[0][rt]==T[1][rt]){
        T[0][rt]=T[0][rt]%x;
        T[1][rt]=T[1][rt]%x;
        sum[rt]=(ll)T[0][rt]*(ll)(r-l+1ll);
        add[rt]=x;
        return ;
    }
    pushdown(rt,l,r);
    int mid=(l+r)>>1;
    if(R<=mid){
        update(rt<<1,l,mid,L,R);
    }
    else if(L>mid){
        update(rt<<1|1,mid+1,r,L,R);
    }
    else{
        update(rt<<1,l,mid,L,mid);
        update(rt<<1|1,mid+1,r,mid+1,R);
    }
    pushup(rt);
}

ll cal(int rt,int l,int r,int L,int R){
    if(l==L&&R==r){
        return sum[rt];
    }
    pushdown(rt,l,r);
    int mid=(l+r)>>1;
    if(R<=mid){
        return cal(rt<<1,l,mid,L,R);
    }
    else if(L>mid){
        return cal(rt<<1|1,mid+1,r,L,R);
    }
    else{
        return cal(rt<<1,l,mid,L,mid)+cal(rt<<1|1,mid+1,r,mid+1,R);
    }
}

int main(void){
    FC;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    create(1,1,n);
    int tmp;
    while(m--){
        cin>>tmp;
        if(tmp==1){
            cin>>l>>r;
            cout<<cal(1,1,n,l,r)<<'\n';
        }
        else if(tmp==2){
            cin>>l>>r>>x;   
            update(1,1,n,l,r);
        }
        else{
            cin>>k>>x;
            update(1,1,n,k);
        }
    }
    return 0;
}
