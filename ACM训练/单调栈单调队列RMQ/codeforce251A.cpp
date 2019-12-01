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

const long double PI=acos(-1.0); 
const long double eps=1e-6;
const long long maxw=1e17+10;

typedef long long ll;
typedef pair<int,int> pii;
/*head------[@cordercorder]*/

const int maxn=1e5+10;

int a[maxn];
int n,d;

void solve(){
	ll ans=0;
	ll pos;
	for(int i=1;i<=n-2;i++){
		pos=upper_bound(a+1,a+1+n,a[i]+d)-a-1;
		if(a[pos]<=a[i]+d){
		//	deb(pos);
			ans+=(pos-i)*(pos-i-1)/2;
		}
	}
	printf("%lld\n",ans);
}

int main(void){
	scanf("%d %d",&n,&d);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	solve();
	return 0;
}
