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

# define deb(x) cout<<"#---"<<#x<<"=="<<x<<endl

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

const int maxn=1e5+10;

ll n,m,c;
ll a[maxn];
ll sum[maxn];
bool isv[maxn];
ll ans;

void solve(){
	sort(sum,sum+1+n);
	ll l=0,r=n;
	ans=0;
	for(ll i=0;i<m&&l<r;i++){
		if(sum[r]-sum[l]>c){
			ans+=sum[r]-sum[l]-c;
			r--;
			l++;
		}
	}
	printf("%lld\n",ans);
}

int main(void){
	while(scanf("%lld %lld %lld",&n,&m,&c)!=EOF){
		sum[0]=0;
		for(ll i=1;i<=n;i++){
			scanf("%lld",&a[i]);
			sum[i]=sum[i-1]+a[i];
		}
		solve();
	}
	return 0;
}
