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

const ll maxn=1e5+10;

ll n,d;
ll x[maxn];

void solve(){
	ll ans=0,pos;
	for(ll i=1;i<=n;i++){
		pos=upper_bound(x+1,x+1+n,x[i]+d)-x-1;
		if(pos-i>1){
			ans+=(pos-i)*(pos-i-1)/2;
		}
		//deb(pos);
	}
	cout<<ans<<endl;
}

int main(void){
	FC;
	cin>>n>>d;
	for(ll i=1;i<=n;i++){
		cin>>x[i];
	}
	solve();
	return 0;
}
