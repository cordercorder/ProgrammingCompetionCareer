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

const int maxn=(int)1e5+10;

int t;
int n,k;
int a[maxn];
int ret;
int st[maxn][20][2];
int Log[maxn];

void ST(){
    Log[0]=-1;
    for(int i=1;i<=n;i++){
        st[i][0][0]=a[i];
        st[i][0][1]=a[i];
        Log[i]=Log[i>>1]+1;
    }
    for(int j=1;(1<<j)<=n;j++){
        for(int i=1;i+(1<<j)-1<=n;i++){
            st[i][j][0]=max(st[i][j-1][0],st[i+(1<<(j-1))][j-1][0]);
            st[i][j][1]=min(st[i][j-1][1],st[i+(1<<(j-1))][j-1][1]);
        }
    }
}


int cal(int L,int R,bool f){
    int len=R-L+1,ret;
    ret=Log[len];
    if(f){
        return max(st[L][ret][0],st[R-(1<<ret)+1][ret][0]);
    }
    return min(st[L][ret][1],st[R-(1<<ret)+1][ret][1]);
}

int Find(int L,int R){
    int l=L,r=R,mid;
    int mine,maxe;
    while(l<r){
        mid=(l+r)>>1;
        mine=cal(L,mid,false);
        maxe=cal(L,mid,true);
        if(maxe-mine<k){
            l=mid+1;
        }
        else{
            r=mid;
        }
    }
    mine=cal(L,l,false);
    maxe=cal(L,l,true);
    if(maxe-mine<k)
        return l;
    return l-1;
}

void solve(){
    ST();
    int pos;
    ll ans=0ll;
    for(int i=1;i<=n;i++){
        pos=Find(i,n);
        ans+=(ll)(pos-i+1ll);
    }
    printf("%lld\n",ans);
}

int main(void){
    scanf("%d",&t);
    while(t--){
        scanf("%d %d",&n,&k);
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i]);
        }
        solve();
    }
    return 0;
}
