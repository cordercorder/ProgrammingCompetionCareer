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
typedef pair<int,int> pii;

/*head------[@cordercorder]*/

const ll maxn=(ll)1e5+10ll; 

ll n,a[maxn],m;
ll q[maxn],sum[maxn],dp[maxn];
ll ret;

void solve(){
    ll l=1;
    ll front=0,back=0,lst;
    for(ll i=1;i<=n;i++){
        while(sum[i]-sum[l-1]>m)
            l++;
        while(front<back&&q[front+1]<l){
            front++;
        }
        while(front<back&&a[q[back]]<a[i]){
            back--;
        }
        q[++back]=i;
        dp[i]=(ll)1e18+10ll;
        lst=l-1;
        for(ll j=front+1;j<=back;j++){
            dp[i]=min(dp[i],dp[lst]+a[q[j]]);
            lst=q[j];
        }
    }
    printf("%lld\n",dp[n]);
}

int main(void){
    scanf("%lld %lld",&n,&m);
    ret=1;
    for(ll i=1;i<=n;i++){
        scanf("%lld",&a[i]);
        sum[i]=sum[i-1]+a[i];
        if(a[i]>a[ret]){
            ret=i;
        }
    }
    if(a[ret]>m){
        puts("-1");
    }
    else{
        solve();
    }
    return 0;
}
