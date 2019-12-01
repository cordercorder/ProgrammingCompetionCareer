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

const int maxn=1e7+10;

ll t;
ll n;
vector<ll> pre; 
bool isv[maxn];
ll ans;

void handle(){
	memset(isv,0,sizeof(isv));
	for(ll i=2;i<=10000000;i++){
		if(!isv[i]){
			pre.push_back(i);
			for(ll j=i*i;j<=10000000;j+=i)
				isv[j]=1;
		}
	}
}

void solve(){
	ll res;
	ans=1;
	for(ll i=0;i<(ll)pre.size()&&pre[i]*pre[i]<=n;i++){
		res=0;
		while(n%pre[i]==0){
			n/=pre[i];
			res++;
		}
		ans*=(2*res+1);
		if(n==1)
			break;
	}
	if(n!=1){
		ans*=3;
	}
	ans=(ans+1)/2;
}

int main(void){
	handle();
	scanf("%lld",&t);
	for(ll i=1;i<=t;i++){
		scanf("%lld",&n);
		solve();
		printf("Case %lld: %lld\n",i,ans);
	}
	return 0;
}
