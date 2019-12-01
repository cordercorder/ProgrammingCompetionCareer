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

const int maxn=3e3+10;

ll n,m;
vector<ll> res[maxn];

void solve(){
	vector<ll> tmp;
	for(ll i=2;i<=m;i++){
		if(!res[i].empty()){
			sort(res[i].begin(),res[i].end());
		}
	}
	ll ans=maxw,ret,need,sum;
	for(ll i=1;i<=n;i++){
		need=i-(ll)res[1].size();
		sum=0;
		for(ll j=2;j<=m;j++){
			ret=(ll)res[j].size()-i+1;
			ret=max(ret,(ll)0);
			for(ll k=0;k<ret;k++){
				need--;
				sum+=res[j][k];
			}
			for(ll k=ret;k<(ll)res[j].size();k++){
				tmp.push_back(res[j][k]);
			}
		}
		if(need>0){
			//sort(tmp.begin(),tmp.end());
			nth_element(tmp.begin(),tmp.begin()+need,tmp.end());
			for(ll j=0;j<need;j++){
				sum+=tmp[j];
			}
		}
		ans=min(ans,sum);
		tmp.clear();
	}
	printf("%lld\n",ans);
}

int main(void){
	ll p,c;
	scanf("%lld %lld",&n,&m);
	for(ll i=1;i<=n;i++){
		scanf("%lld %lld",&p,&c);
		res[p].push_back(c);
	}
	solve();
	return 0;
}
