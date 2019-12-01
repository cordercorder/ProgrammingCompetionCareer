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

typedef long long ll;
typedef pair<int,int> pii;
 
/*head------[@cordercorder]*/

const int maxn=(int)5e4+10;

int cnt[maxn];
int a[maxn];
int N,M,block;
ll sum;
ll ans1[maxn],ans2[maxn];

struct node{
    int l;
    int r;
    int id;
}Q[maxn];

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
    int L=1,R=0;
    sort(Q+1,Q+1+M,cmp);
    ll len,ret;
    ll tmp1,tmp2;
    for(int i=1;i<=M;i++){
        while(R<Q[i].r){
            R++;
            sum+=(ll)cnt[a[R]];
            cnt[a[R]]++;
        }
        while(R>Q[i].r){
            sum+=(ll)(-cnt[a[R]]+1ll);
            cnt[a[R]]--;
            R--;
        }
        while(L<Q[i].l){
            sum+=(ll)(-cnt[a[L]]+1ll);
            cnt[a[L]]--;
            L++;
        }
        while(L>Q[i].l){
            L--;
            sum+=(ll)cnt[a[L]];
            cnt[a[L]]++;
        }
        if(sum==0){
            ans1[Q[i].id]=0;
            ans2[Q[i].id]=1;
        }
        else{
            tmp1=sum;
            len=(ll)(Q[i].r-Q[i].l+1ll);
            tmp2=len*(len-1ll)/2;
            ret=__gcd(tmp1,tmp2);
            tmp1/=ret;
            tmp2/=ret;
            ans1[Q[i].id]=tmp1;
            ans2[Q[i].id]=tmp2;
        }
    }
    for(int i=1;i<=M;i++){
        printf("%lld/%lld\n",ans1[i],ans2[i]);
    }
}

int main(void){
    scanf("%d %d",&N,&M);
    for(int i=1;i<=N;i++){
        scanf("%d",&a[i]);
    }
    block=(int)(sqrt(N));
    for(int i=1;i<=M;i++){
        scanf("%d %d",&Q[i].l,&Q[i].r);
        Q[i].id=i;
    }
    solve();
    return 0;
}
