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
typedef pair<int,int> pii;
/*head------[@cordercorder]*/

const ll mod=1e9+7;

ll t;
ll L,R;
ll tmp[23],cnt;


void bits(ll x){
	cnt=0;
	while(x){
		tmp[++cnt]=x%10;
		x/=10;
	}
}






void solve(){
	bits(R);
	
	
	
	
	
	
	
	
}

int main(void){
	scanf("%lld",&t);
	while(t--){
		scanf("%lld %lld",&L,&R);
		solve();
	}
	return 0;
}
