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
#define FIN freopen("data.txt","r",stdin)
#define FOUT freopen("data.txt","w",stdout)

using namespace std;

const long double PI=acos(-1.0);
const long double eps=1e-6;
const long long maxw=1e17+10;

typedef long long ll;
typedef pair<int,int> pii;
/*head------[@cordercorder]*/

const ll maxn=5e5+10;

ll n;
ll a[maxn];
bool f[2];

bool cmp(const ll &a,const ll &b){
	return abs(a)<abs(b);
}

void solve(){
	ll ans=0;
	for(ll i=1;i<=n;i++){
		ans+=abs(a[i]);
	}
	if(f[0]&&f[1]){
		cout<<ans;
	}
	else{
		ans-=abs(*min_element(a+1,a+1+n,cmp))*2LL;
		cout<<ans;
	}
}

int main(void){
	FC;
	cin>>n;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]>=0){
			f[0]=1;
		}
		if(a[i]<=0){
			f[1]=1;
		}
	}
	if(n==1){
		cout<<a[1];
		return 0;
	}
	solve();
	return 0;
}
