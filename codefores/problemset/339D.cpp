#include<bits/stdc++.h>
 
using namespace std;
 
#define FC ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define FIN freopen("in.txt","r",stdin)
#define FOUT freopen("out.txt","w",stdout)
#define deb(x) cerr<<"DEBUG------"<<'\n';cerr<<#x<<"------>";err(x)
 
template<typename T>
void err(T a){
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

const int maxn=(1<<17)+10;

int a[maxn],m,n,N,T[maxn<<2];

void create(int rt,int l,int r,int depth){
    if(l==r){
        T[rt]=a[l];
        return ;
    }
    int mid=(l+r)>>1;
    create(rt<<1,l,mid,depth+1);
    create(rt<<1|1,mid+1,r,depth+1);
    if((n-depth)%2==0){
        T[rt]=T[rt<<1]|T[rt<<1|1];
    }
    else{
        T[rt]=T[rt<<1]^T[rt<<1|1];
    }
}

void update(int rt,int l,int r,int pos,int val,int depth){
    if(l==r){
        T[rt]=val;
        return ;
    }
    int mid=(l+r)>>1;
    if(pos<=mid){
        update(rt<<1,l,mid,pos,val,depth+1);
    }
    else{
        update(rt<<1|1,mid+1,r,pos,val,depth+1);
    }
    if((n-depth)%2==0){
        T[rt]=T[rt<<1]|T[rt<<1|1];
    }
    else{
        T[rt]=T[rt<<1]^T[rt<<1|1];
    }
}

int main(void){
    int b,p;
    scanf("%d %d",&n,&m);
    N=(1<<n);
    for(int i=1;i<=N;i++){
        scanf("%d",&a[i]);
    }
    create(1,1,N,1);
    while(m--){
        scanf("%d %d",&p,&b);
        update(1,1,N,p,b,1);
        printf("%d\n",T[1]);
    }
    return 0;
}
