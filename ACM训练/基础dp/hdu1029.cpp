# include<iostream>
# include<algorithm>
# include<cstring>
# include<string>
# include<cmath>
# include<queue>
# include<stack>
# include<set>
# include<vector>
# include<cstdio>
# include<cstdlib>
# include<map>
# include<deque>
# include<limits.h>
# include<ctime>

# define deb(x) printf("# x=%d\n",x)
# define deb_d(x) printf("# x=%lf\n",x)
# define ccout(x) printf("%d\n",x)

typedef long long ll;

using namespace std;

const int maxn=1e6+10;

map<ll,ll> mp;
map<ll,ll>::iterator it; 
ll n;

int main(void){
	ll tmp;
	ll Max,ans;
	while(scanf("%lld",&n)!=EOF){
		for(ll i=1;i<=n;i++){
			scanf("%lld",&tmp);
			mp[tmp]++;
		}
		Max=mp.begin()->second;
		ans=mp.begin()->first;
		for(it=mp.begin();it!=mp.end();it++){
			if(it->second>Max){
				Max=it->second;
				ans=it->first;
			}
		}
		//cout<<mp[0]<<endl;
		//cout<<"11=="<<mp[1]<<endl;
		printf("%lld\n",ans);
		mp.clear();
	}
	return 0;
}
