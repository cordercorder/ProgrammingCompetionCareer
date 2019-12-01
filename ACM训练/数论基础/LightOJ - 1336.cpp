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

ll t;
ll n;

int main(void){
	ll sum;
	scanf("%lld",&t);
	for(ll ca=1;ca<=t;ca++){
		scanf("%lld",&n);
		sum=n;
		sum-=(ll)sqrt(n);
		sum-=(ll)sqrt(n/2);
		printf("Case %lld: %lld\n",ca,sum);
	}
	return 0;
}
