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

ll n;
queue<ll> q;

void solve(){
	ll now,tmp=1;
	q.push(1);
	while(!q.empty()){
		now=q.front();
		q.pop();
		if(now%n==0){
			printf("%lld\n",now);
			while(!q.empty())
				q.pop();
			return ;
		}
		tmp=now*10;
		q.push(tmp);
		tmp=now*10+1;
		q.push(tmp);
	}
}

int main(void){
	while(scanf("%lld",&n)!=EOF){
		if(n==0)
			break;
		solve();
	}
	return 0;
}
