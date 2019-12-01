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

const int maxn=(int)3e4+10;

int cnt[1000010],a[maxn];
int n,q;
int block;
int ans[200010];

struct node{
    int l;
    int r;
    int id;
}Q[200010];

bool cmp(const node &a,const node &b){
    if(a.l/block<b.l/block)
        return true;
    else if(a.l/block==b.l/block&&a.r<b.r){
        return true;
    }
    return false;
}

void solve(){
    block=(int)(sqrt(n));
    sort(Q+1,Q+1+q,cmp);
    int L=1,R=0,sum=0;
    for(int i=1;i<=q;i++){
        while(R<Q[i].r){
            R++;
            cnt[a[R]]++;
            if(cnt[a[R]]==1){
                sum++;
            }
        }
        while(R>Q[i].r){
            cnt[a[R]]--;
            if(cnt[a[R]]==0){
                sum--;
            }
            R--;
        }
        while(L<Q[i].l){
            cnt[a[L]]--;
            if(cnt[a[L]]==0){
                sum--;
            }
            L++;
        }
        while(L>Q[i].l){
            L--;
            cnt[a[L]]++;
            if(cnt[a[L]]==1){
                sum++;
            }
        }
        ans[Q[i].id]=sum;
    }
    for(int i=1;i<=q;i++){
        printf("%d\n",ans[i]);
    }
}

int main(void){
    int x,l,r;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    scanf("%d",&q);
    for(int i=1;i<=q;i++){
        scanf("%d %d",&l,&r);
        Q[i]={l,r,i};
    }
    solve();
    return 0;
}
