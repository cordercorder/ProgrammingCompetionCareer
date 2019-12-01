#include<algorithm>
#include<iostream>
#include<limits.h>
#include<cstdlib>
#include<cstring>
#include<vector>
#include<string>
#include<cstdio>
#include<bitset>
#include<cmath>
#include<queue>
#include<stack>
#include<deque>
#include<ctime>
#include<list>
#include<set>
#include<map>

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

typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll,ll> pii;

/*head------[@cordercorder]*/

const ll maxn=(ll)1e5+10ll;

ll n,k;
ll a[maxn];
ll t;
pii sum[maxn];

bool cmp(const pii &a,const pii &b){
    return a.first<b.first;
}

bool check(ll d){
    ll posL,posR;
    pii R,L;
    for(ll l=0;l<=n;l++){
        R.first=sum[l].first+t+d;
        L.first=sum[l].first+t-d;
        posR=upper_bound(sum,sum+1+n,R,cmp)-sum;
        posL=lower_bound(sum,sum+1+n,L,cmp)-sum;
        if(posL==l){
            posL++;
        }
        if((posR-posL)>0)
            return true;
    }
    return false;
}

void solve(){
    ll l=0,r=(ll)2e9+10ll,mid;
    while(l<r){
        mid=(l+r)>>1ll;
        if(check(mid)){
            r=mid;
        }
        else{
            l=mid+1ll;
        }
    }
    pii R,L;
    ll x1,x2;
    for(ll i=0;i<=n;i++){
        R.first=sum[i].first+t+l;
        L.first=sum[i].first+t-l;
        x1=upper_bound(sum,sum+1+n,R,cmp)-sum;
        x2=lower_bound(sum,sum+1+n,R,cmp)-sum;
        if(x2==i){
            x2++;
        }
        if((x1-x2)>0){
            printf("%lld ",sum[x2].first-sum[i].first);
            if(sum[x2].second<sum[i].second){
                printf("%lld %lld\n",sum[x2].second+1ll,sum[i].second);
            }
            else{
                printf("%lld %lld\n",sum[i].second+1ll,sum[x2].second);
            }
            return ;
        }
        x1=upper_bound(sum,sum+1+n,L,cmp)-sum;
        x2=lower_bound(sum,sum+1+n,L,cmp)-sum;
        if(x2==i){
            x2++;
        }
        if((x1-x2)>0){
            printf("%lld ",sum[x2].first-sum[i].first);
            if(sum[x2].second<sum[i].second){
                printf("%lld %lld\n",sum[x2].second+1ll,sum[i].second);
            }
            else{
                printf("%lld %lld\n",sum[i].second+1ll,sum[x2].second);
            }
            return ;
        }
    }
}

int main(void){
    while(scanf("%lld %lld",&n,&k)!=EOF){
        if(n==0&&k==0)
            break;
        sum[0].first=0;
        sum[0].second=0;
        for(ll i=1;i<=n;i++){
            scanf("%lld",&a[i]);
            sum[i].first=sum[i-1].first+a[i];
            sum[i].second=i;
        }
        sort(sum,sum+n+1,cmp); 
        while(k--){
            scanf("%lld",&t);
            solve();
        }
    }
    return 0;
}
