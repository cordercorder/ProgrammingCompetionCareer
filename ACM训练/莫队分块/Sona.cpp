#include<iostream>
#include<algorithm>
#include<cstring>
#include<string>
#include<cmath>
#include<queue>
#include<stack>
#include<set>
#include<vector>
#include<cstdio>
#include<cstdlib>
#include<map>
#include<deque>
#include<limits.h>
#include<bitset>
#include<ctime>

#define deb(x) cout<<"#---"<<#x<<"=="<<x<<endl

using namespace std;

typedef __int64 ll;
typedef pair<int,int> pii;
 
/*head------[@cordercorder]*/

const int maxn=(int)1e5+10;

int N,Q;
int note[maxn];
int block;
map<int,ll> cnt;
ll ans[maxn];

struct node{
    int l;
    int r;
    int id;
}q[maxn];

bool cmp(const node &a,const node &b){
    int x1=a.l/block,x2=b.l/block;
    if(x1<x2){
        return true;
    }
    else if(x1==x2&&a.r<b.r){
        return true;
    }
    return false;
}

void solve(){
    sort(q+1,q+1+Q,cmp);
    int L=1,R=0;
    ll sum=0,tmp;
    for(int i=1;i<=Q;i++){
        while(R<q[i].r){
            R++;
            tmp=cnt[note[R]];
            sum+=((ll)3*tmp*tmp+(ll)3*tmp+(ll)1);
            cnt[note[R]]++;
        }
        while(R>q[i].r){
            tmp=cnt[note[R]];
            sum+=(-(ll)3*tmp*tmp+(ll)3*tmp-(ll)1);
            cnt[note[R]]--;
            R--;
        }
        while(L<q[i].l){
            tmp=cnt[note[L]];
            sum+=(-(ll)3*tmp*tmp+(ll)3*tmp-(ll)1);
            cnt[note[L]]--;
            L++;
        }
        while(L>q[i].l){
            L--;
            tmp=cnt[note[L]];
            sum+=((ll)3*tmp*tmp+(ll)3*tmp+(ll)1);
            cnt[note[L]]++;
        }
        ans[q[i].id]=sum;
    }
    for(int i=1;i<=Q;i++){
        printf("%I64d\n",ans[i]);
    }
    cnt.clear();
}

int main(void){
    while(scanf("%d",&N)!=EOF){
        for(int i=1;i<=N;i++){
            scanf("%d",&note[i]);
        }
        block=(int)(sqrt(N));
        scanf("%d",&Q);
        for(int i=1;i<=Q;i++){
            scanf("%d %d",&q[i].l,&q[i].r);
            q[i].id=i;
        }
        solve();
    }
    return 0;
}
