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

const ll maxn=(ll)2e5+10;

ll a[maxn],n,q;
ll T[7][maxn<<2];// max,max_second,min,min_second,cntmax,cntmin,sum
                   //  0,   1     , 2 ,3         ,4     ,5     ,6

struct node{
    ll ret[7];
};

void pushup(ll rt){
    if(T[0][rt<<1]>T[0][rt<<1|1]){
        T[0][rt]=T[0][rt<<1];
        T[1][rt]=max(T[1][rt<<1|1],T[1][rt<<1]);
        T[1][rt]=max(T[1][rt],T[0][rt<<1|1]);
        T[4][rt]=T[4][rt<<1];
    }
    else if(T[0][rt<<1]<T[0][rt<<1|1]){
        T[0][rt]=T[0][rt<<1|1];
        T[1][rt]=max(T[1][rt<<1|1],T[1][rt<<1]);
        T[1][rt]=max(T[1][rt],T[0][rt<<1]);
        T[4][rt]=T[4][rt<<1|1];
    }
    else{
        T[0][rt]=T[0][rt<<1];
        T[1][rt]=max(T[1][rt<<1],T[1][rt<<1|1]);
        T[4][rt]=T[4][rt<<1]+T[4][rt<<1|1];
    }
    if(T[2][rt<<1]<T[2][rt<<1|1]){
        T[2][rt]=T[2][rt<<1];
        T[3][rt]=min(T[3][rt<<1],T[3][rt<<1|1]);
        T[3][rt]=min(T[3][rt],T[2][rt<<1|1]);
        T[5][rt]=T[5][rt<<1];
    }
    else if(T[2][rt<<1]>T[2][rt<<1|1]){
        T[2][rt]=T[2][rt<<1|1];
        T[3][rt]=min(T[3][rt<<1],T[3][rt<<1|1]);
        T[3][rt]=min(T[3][rt],T[2][rt<<1]);
        T[3][rt]=T[2][rt<<1];
        T[5][rt]=T[5][rt<<1|1];
    }
    else{
        T[2][rt]=T[2][rt<<1];
        T[3][rt]=min(T[3][rt<<1],T[3][rt<<1|1]);
        T[5][rt]=T[5][rt<<1]+T[5][rt<<1|1];
    }
    T[6][rt]=T[6][rt<<1]+T[6][rt<<1|1];
}

void create(ll rt,ll l,ll r){
    if(l==r){
        T[0][rt]=a[l];
        T[1][rt]=0;
        T[2][rt]=a[l];
        T[3][rt]=(ll)1e9+10ll;
        T[4][rt]=1;
        T[5][rt]=1;
        T[6][rt]=a[l];
        return ;
    }
    ll mid=(l+r)>>1;
    create(rt<<1,l,mid);
    create(rt<<1|1,mid+1,r);
    pushup(rt);
}

node query(ll rt,ll l,ll r,ll L,ll R){
    if(l==L&&R==r){
        node ans;
        for(ll i=0;i<7;i++){
            ans.ret[i]=T[i][rt];
        }
        return ans;
    }
    ll mid=(l+r)>>1;
    if(R<=mid){
        return query(rt<<1,l,mid,L,R);
    }
    else if(L>mid){
        return query(rt<<1|1,mid+1,r,L,R);
    }
    else{
        node ans,ansL,ansR;
        ansL=query(rt<<1,l,mid,L,mid);
        ansR=query(rt<<1|1,mid+1,r,mid+1,R);
        if(ansL.ret[0]>ansR.ret[0]){
            ans.ret[0]=ansL.ret[0];
            ans.ret[1]=max(ansL.ret[1],ansR.ret[1]);
            ans.ret[1]=max(ans.ret[1],ansR.ret[0]);
            ans.ret[4]=ansL.ret[4];
        }
        else if(ansL.ret[0]<ansR.ret[0]){
            ans.ret[0]=ansR.ret[0];
            ans.ret[1]=max(ansL.ret[1],ansR.ret[1]);
            ans.ret[1]=max(ans.ret[1],ansL.ret[0]);
            ans.ret[4]=ansR.ret[4];
        }
        else{
            ans.ret[0]=ansL.ret[0];
            ans.ret[1]=max(ansL.ret[1],ansR.ret[1]);
            ans.ret[4]=ansL.ret[4]+ansR.ret[4];
        }
        if(ansL.ret[2]<ansR.ret[2]){
            ans.ret[2]=ansL.ret[2];
            ans.ret[3]=min(ansL.ret[3],ansR.ret[3]);
            ans.ret[3]=min(ans.ret[3],ansR.ret[2]);
            ans.ret[5]=ansL.ret[5];
        }
        else if(ansL.ret[2]>ansR.ret[2]){
            ans.ret[2]=ansL.ret[2];
            ans.ret[3]=min(ansL.ret[3],ansR.ret[3]);
            ans.ret[3]=min(ans.ret[3],ansL.ret[3]);
            ans.ret[5]=ansR.ret[5];
        }
        else{
            ans.ret[2]=ansL.ret[2];
            ans.ret[3]=min(ansL.ret[3],ansR.ret[3]);
            ans.ret[5]=ansL.ret[5]+ansR.ret[5];
        }
        ans.ret[6]=ansL.ret[6]+ansR.ret[6];
        return ans;
    }
}

int main(void){
    ll l,r;
    scanf("%lld",&n);
    for(ll i=1;i<=n;i++){
        scanf("%lld",&a[i]);
    }
    create(1,1,n);
    scanf("%lld",&q);
    node ans;
    while(q--){
        scanf("%lld %lld",&l,&r);
        ans=query(1,1,n,l,r);
        for(int i=0;i<7;i++){
            if(i>0){
                printf(" ");
            }
            printf("%lld",ans.ret[i]);
        }
        puts("");
    }
    return 0;
}
