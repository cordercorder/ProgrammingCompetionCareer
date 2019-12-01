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

typedef long long ll;
typedef pair<int,int> pii;

const int maxn=1e2+10;

ll a[maxn];
ll d,n;
set<ll> s;
set<ll>::iterator it;

void solve(){
	sort(a+1,a+1+n);
	ll res1,res2;
	for(ll i=1;i<=n;i++){
		if(i==1){
			res1=a[i]-d;
			s.insert(res1);
		}
		else{
			res1=a[i]-d;
			res2=a[i-1]+d;
			if(abs(a[i-1]-res1)>=d){
				s.insert(res1);
			}
			if(abs(a[i]-res2)>=d){
				s.insert(res2);
			}
		}
	}
	/*for(it=s.begin();it!=s.end();it++){
		deb(*it);
	}*/
	s.insert(a[n]+d);
	printf("%lld",(ll)s.size());
	s.clear();
}

int main(void){
	scanf("%lld %lld",&n,&d);
	for(ll i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	solve();
	return 0;
}
