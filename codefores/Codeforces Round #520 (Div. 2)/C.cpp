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
#include<list>

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

const ll maxn=1e5+10;
const ll mod=1e9+7;

ll n,q;
char s[maxn];
ll l,r;
ll sum[maxn];

ll q_mod(ll a,ll b){
    ll ans=1;
    while(b){
        if(b&1){
            ans=ans*a%mod;
        }
        a=a*a%mod;
        b>>=1;
    }
    return ans;
}

void solve(){
    ll res1=q_mod(2ll,sum[r]-sum[l-1]);
    ll res2=q_mod(2ll,r-l+1ll-sum[r]+sum[l-1]);
    ll ans=(res1-1ll)*res2%mod;
    cout<<ans<<'\n';
}

int main(void){
    FC;
    cin>>n>>q;
    cin>>(s+1);
    for(ll i=1;i<=n;i++){
        sum[i]=sum[i-1]+(ll)(s[i]=='1');
    }
    while(q--){
        cin>>l>>r;
        solve();
    }
	return 0;
}
