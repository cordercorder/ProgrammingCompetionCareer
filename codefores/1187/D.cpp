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

const int maxn=(int)3e5+10;

int t,n;
int a[maxn],b[maxn];
int cnta[maxn],cntb[maxn];
vector<int> id[maxn];
int pos[maxn],T[maxn<<2];

void create(int rt,int l,int r){
    if(l==r){
        T[rt]=a[l];
        return ;
    }
    int mid=(l+r)>>1;
    create(rt<<1,l,mid);
    create(rt<<1|1,mid+1,r);
    T[rt]=min(T[rt<<1],T[rt<<1|1]);
}

int query(int rt,int l,int r,int L,int R){
    if(l==L&&R==r){
        return T[rt];
    }
    int mid=(l+r)>>1;
    if(R<=mid){
        return query(rt<<1,l,mid,L,R);
    }
    else if(L>mid){
        return query(rt<<1|1,mid+1,r,L,R);
    }
    else{
        return min(query(rt<<1,l,mid,L,mid),query(rt<<1|1,mid+1,r,mid+1,R));
    }
}

void update(int rt,int l,int r,int pos,int val){
    if(l==r){
        T[rt]=val;
        return ;
    }
    int mid=(l+r)>>1;
    if(pos<=mid){
        update(rt<<1,l,mid,pos,val);
    }
    else{
        update(rt<<1|1,mid+1,r,pos,val);
    }
    T[rt]=min(T[rt<<1],T[rt<<1|1]);
}

void solve(){
    for(int i=1;i<=n;i++){
        cnta[a[i]]++;
        cntb[b[i]]++;
        pos[i]=0;
    }
    for(int i=1;i<=n;i++){
        if(cnta[i]!=cntb[i]){
            puts("NO");
            return ;
        }
    }
    create(1,1,n);
    int mine;
    for(int i=1;i<=n;i++){
        if(pos[b[i]]<(int)id[b[i]].size()){
            mine=query(1,1,n,1,id[b[i]][pos[b[i]]]);
            if(mine<b[i]){
                puts("NO");
                return ;
            }
            update(1,1,n,id[b[i]][pos[b[i]]],1000000);
            pos[b[i]]++;
        }
    }
    puts("YES");
}

void clr(){
    for(int i=1;i<=n;i++){
        cnta[a[i]]--;
        cntb[b[i]]--;
        pos[i]=0;
        if(!id[i].empty()){
            id[i].clear();
        }
    }
}

int main(void){
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i]);
            id[a[i]].push_back(i); 
        }
        for(int i=1;i<=n;i++){
            scanf("%d",&b[i]);
        }
        solve();
        clr();
    }
    return 0;
}
