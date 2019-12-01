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
#include<set>
#include<map>

#define deb(x) cout<<"#---"<<#x<<"=="<<x<<endl
#define FC ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define FIN freopen("in.txt","r",stdin)
#define FOUT freopen("A.txt","w",stdout)

using namespace std;

const long double PI=acos(-1.0);  
const long double eps=1e-6;
const long long maxw=1e17+10;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
/*head------[@cordercorder]*/

const ll maxn=1e6+10;

ll k;
ll a[maxn],r[maxn];

ll exgcd(ll a,ll b,ll&x ,ll& y){
    if(b==0){
        x=1;
        y=0;
        return a;
    }
    ll d=exgcd(b,a%b,x,y);
    ll tmp=x;
    x=y;
    y=tmp-a/b*y;
    return d;
}

ll solve(ll *m,ll *r,ll n){
    ll M=m[1],R=r[1],x,y,gcd;
    for(ll i=2;i<=n;i++){
        gcd=exgcd(M,m[i],x,y);
        if((r[i]-R)%gcd!=0){
            return -1;
        }
        ll tmp=m[i]/gcd;
        x=x*(r[i]-R)/gcd;
        x=x%tmp;
        R=R+x*M;
        M=M/gcd*m[i];
        R=R%M;
    }
    if(R<0)
        R=R+M;
    return R;
}

int main(void){
    while(scanf("%lld",&k)!=EOF){
        for(ll i=1;i<=k;i++){
            scanf("%lld %lld",&a[i],&r[i]);
        }
        printf("%lld\n",solve(a,r,k));
    }
	return 0;
}
