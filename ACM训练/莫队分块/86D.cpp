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

const int maxn=(int)1e6+10;
const int N=200010;

int cnt[maxn],a[N];
int n,t;
int block;
ll sum;

struct node{
    int l;
    int r;
    int id;
}Q[N];
ll ans[maxn];

bool cmp(const node &a,const node &b){
    int x1=a.l/block,x2=b.l/block;
    if(x1<x2)
        return true;
    else if(x1==x2){
        return a.r<b.r;
    }
    return false;
}

void solve(){
    sort(Q+1,Q+1+t,cmp);
    int L=1,R=0;
    for(int i=1;i<=t;i++){
        while(R<Q[i].r){
            R++;
            sum+=(ll)(2ll*cnt[a[R]]+1ll)*(ll)a[R];
            cnt[a[R]]++;
        }
        while(R>Q[i].r){
            sum+=(ll)(-2ll*cnt[a[R]]+1ll)*(ll)a[R];
            cnt[a[R]]--;
            R--;
        }
        while(L<Q[i].l){
            sum+=(ll)(-2ll*cnt[a[L]]+1ll)*(ll)a[L];
            cnt[a[L]]--;
            L++;
        }
        while(L>Q[i].l){
            L--;
            sum+=(ll)(2ll*cnt[a[L]]+1ll)*(ll)a[L];
            cnt[a[L]]++;
        }
        ans[Q[i].id]=sum;
    }
    for(int i=1;i<=t;i++){
        printf("%lld\n",ans[i]);
    }
}

int main(void){
    scanf("%d %d",&n,&t);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    block=(int)(sqrt(n));
    for(int i=1;i<=t;i++){
        scanf("%d %d",&Q[i].l,&Q[i].r);
        Q[i].id=i;
    }
    solve(); 
    return 0;
}
