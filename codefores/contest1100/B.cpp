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

const int maxn=1e5+10;

int n,m;
int a[maxn];
int T[maxn<<2],add[maxn<<2];

void pushdown(int rt){
    if(add[rt]){
        T[rt<<1]-=add[rt];
        T[rt<<1|1]-=add[rt];
        add[rt<<1]+=add[rt];
        add[rt<<1|1]+=add[rt];
        add[rt]=0;
    }
}

void update(int rt,int l,int r,int pos){
    if(l==r){
        T[rt]++;
        return ;
    }
    pushdown(rt);
    int mid=(l+r)>>1;
    if(pos<=mid){
        update(rt<<1,l,mid,pos);
    }
    else{
        update(rt<<1|1,mid+1,r,pos);
    }
    T[rt]=min(T[rt<<1],T[rt<<1|1]);
}

void solve(){
    for(int i=1;i<=m;i++){
        update(1,1,n,a[i]);
//        deb(T[1]); 
        if(T[1]==1){
            cout<<'1';
            T[1]--;
            add[1]++;
        }
        else{
            cout<<'0';
        }
    }
}

int main(void){
    FC;
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        cin>>a[i];
    }
    solve();
    return 0;
}
