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
#include<ctime>

#define deb(x) cout<<"#---"<<#x<<"=="<<x<<endl

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

const int maxn=120000+10;

ll a[maxn];
ll n;
map<ll,ll> mp;
vector<ll> p;

void solve(){
	ll tmp;
	bool f;
	for(ll i=1;i<=n;i++){
		f=0;
		for(ll j=0;j<=32;j++){
			tmp=((ll)1<<j)-a[i];
			//deb(tmp);
			if(mp[tmp]){
				if(tmp==a[i]&&mp[tmp]>1){
					f=1;
				}
				else if(tmp!=a[i]){
					f=1;
				}
			}
		}
		/*if(f){
			if(!isv[a[i]]){
				p.push_back(a[i]);
				isv[a[i]]=1;
			}
			if(!isv[tmp]){
				p.push_back(tmp);
				isv[tmp]=1;
			}
		}*/
		if(!f){
			p.push_back(a[i]);
		}
	}
	//deb(p.size());
	printf("%lld\n",(ll)p.size());
}

int main(void){
	while(scanf("%lld",&n)!=EOF){
		for(ll i=1;i<=n;i++){
			scanf("%lld",&a[i]);
			mp[a[i]]++;
		}
		solve();
		mp.clear();
		p.clear();
	}
	return 0;
}
