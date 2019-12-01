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

# define deb(x) printf("# x=%d\n",x)
# define deb_d(x) printf("# x=%lf\n",x)
# define ccout(x) printf("%d\n",x)

typedef long long ll;

using namespace std;

map<ll,vector<ll> > mp;
vector<ll> p;

const int maxn=1e5+10;

ll n,k;
ll a[maxn];
ll f[maxn];

int main(void){
	ll ans;
	ll len,pos;
	while(scanf("%lld %lld",&n,&k)!=EOF){
		for(ll i=1;i<=n;i++){
			scanf("%lld",&a[i]);
			mp[a[i]].push_back(i); 
			f[i]=n+1;
		}
		if(k==0){
			printf("%lld\n",(n*(n+1))/2);
			mp.clear();
			continue;
		}
		f[n+1]=n+1;
		ans=0;
		for(ll i=1;i<=n;i++){
			len=mp[a[i]].size();
			pos=lower_bound(mp[a[i]].begin(),mp[a[i]].end(),i)-mp[a[i]].begin();
			if(pos+k-1<len){
				f[i]=mp[a[i]][pos+k-1];
			}
		}
		/*for(ll i=1;i<=n;i++){
			cout<<f[i]<<" ";
		}
		cout<<endl;*/
		for(ll i=n;i>=1;i--){
			f[i]=min(f[i],f[i+1]);
			ans+=n-f[i]+1;
		}
		printf("%lld\n",ans);
		mp.clear();
	}
	return 0;
}
