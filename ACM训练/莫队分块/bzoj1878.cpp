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

/*head------[@cordercorder]*/

const int maxn=(int)5e4+10;

int bs;
int a[maxn],N,M;
int cnt[1000010];
int ans[200010];
int sum;

struct node{
    int l;
    int r;
    int id;
}q[200010];

bool cmp(const node &a,const node &b){
    if(a.l/bs!=b.l/bs){//不属于同一块按照左端点排序 
        return a.l<b.l;
    }
    return a.r<b.r;//否则按照右端点排序 
}

void add(int pos){
    cnt[a[pos]]++;
    if(cnt[a[pos]]==1){
        sum++;
    }
}

void del(int pos){
    cnt[a[pos]]--;
    if(cnt[a[pos]]==0){
        sum--;
    }
}

void solve(){
    sort(q+1,q+1+M,cmp);
    sum=0;
    int L=1,R=0;
    for(int i=1;i<=M;i++){
        while(R<q[i].r){
            add(++R);
        }
        while(R>q[i].r){
            del(R--);
        }
        while(L<q[i].l){
            del(L++);
        }
        while(L>q[i].l){
            add(--L);
        }
        ans[q[i].id]=sum;
    }
    for(int i=1;i<=M;i++){
        printf("%d\n",ans[i]);
    }
}

int main(void){
    scanf("%d",&N);
    for(int i=1;i<=N;i++){
        scanf("%d",&a[i]);
    }
    bs=(int)((double)N/sqrt(M));
    scanf("%d",&M);
    for(int i=1;i<=M;i++){
        scanf("%d %d",&q[i].l,&q[i].r);
        q[i].id=i;
    }
    solve();
    return 0;
}
