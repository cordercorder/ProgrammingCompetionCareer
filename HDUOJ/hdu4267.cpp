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

const int maxn=50010;

int T[maxn<<2][56];
int n;
int A[maxn],q;
int Index[15][10];

void create(int rt,int l,int r){
    for(int i=1;i<=56;i++){
        T[rt][i]=0;
    }
    if(l==r)
        return ;
    int mid=(l+r)>>1;
    create(rt<<1,l,mid);
    create(rt<<1|1,mid+1,r);
}

void pushdown(int rt,int l,int r){
    int mid=(l+r)>>1;
    for(int i=1;i<=55;i++){
        if(T[rt][i]){
            T[rt<<1][i]+=T[rt][i];
            T[rt<<1|1][i]+=T[rt][i];
            T[rt][i]=0;
        }
    }
}

void update(int rt,int l,int r,int L,int R,int val,int pos){
    if(l==L&&R==r){
        T[rt][pos]+=val;
        return ;
    }
    pushdown(rt,l,r);
    int mid=(l+r)>>1;
    if(R<=mid){
        update(rt<<1,l,mid,L,R,val,pos);
    } 
    else if(L>mid){
        update(rt<<1|1,mid+1,r,L,R,val,pos);
    }
    else{
        update(rt<<1,l,mid,L,mid,val,pos);
        update(rt<<1|1,mid+1,r,mid+1,R,val,pos);
    }
}

int query(int rt,int l,int r,int pos){
    if(l==r){
        int ans=0;
        for(int i=1;i<=10;i++){
            ans+=T[rt][Index[i][pos%i]];
        }
        return ans;
    }
    pushdown(rt,l,r);
    int mid=(l+r)>>1;
    if(pos<=mid){
        return query(rt<<1,l,mid,pos);
    }
    else{
        return query(rt<<1|1,mid+1,r,pos);
    }
}

int main(void){
    int a,b,k,c,tmp;
    int cnt=0;
    for(int i=1;i<=10;i++){
        for(int j=0;j<i;j++){
            Index[i][j]=++cnt;
        }
    }
    while(scanf("%d",&n)!=EOF){
        for(int i=1;i<=n;i++){
            scanf("%d",&A[i]);
        }
        create(1,1,n);
        scanf("%d",&q);
        while(q--){
            scanf("%d",&tmp);
            if(tmp==1){
                scanf("%d %d %d %d",&a,&b,&k,&c);
                update(1,1,n,a,b,c,Index[k][a%k]);
            }
            else{
                scanf("%d",&a);
                printf("%lld\n",(ll)A[a]+(ll)query(1,1,n,a));
            }
        }
    }
    return 0;
}
