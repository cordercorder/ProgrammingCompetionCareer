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
#define FOUT freopen("out.txt","w",stdout)

using namespace std;

const long double PI=acos(-1.0);  
const long double eps=1e-6;
const long long maxw=1e17+10;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
/*head------[@cordercorder]*/

const ll mod=998244353LL;
const ll maxn=2e5+10;

char a[maxn],b[maxn];
ll n,m;
ll sum[maxn];

ll q_mod(ll a,ll b){
	ll ans=1;
	while(b){
		if(b&1LL){
			ans=ans*a%mod;
		}
		a=a*a%mod;
		b>>=1;
	}
	return ans;
}

void solve(){
	reverse(a+1,a+1+n);
	reverse(b+1,b+1+m); 
	sum[0]=0;
	for(int i=1;i<=m;i++){
		sum[i]=sum[i-1]+(int)(b[i]=='1');
	}
	ll ans=0;
	for(int i=1;i<=n;i++){
		if(i>m)
			break;
		if(a[i]=='1'){
			ans=(ans+(sum[m]-sum[i-1])*q_mod(2LL,i-1LL)%mod)%mod;
		}
	}
	cout<<ans<<'\n';
}

int main(void){
	FC;
	cin>>n>>m;
	cin>>(a+1)>>(b+1);
	solve();
	return 0;
}
