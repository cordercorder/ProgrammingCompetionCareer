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

const int mod=998244353;

int n,t;
int m,p,q;
map<int,int> mp;
vector<int> pre,pp;

int q_mod(int a,int b){
	int ans=1;
	while(b){
		if(b&1){
			ans=ans*a%mod;
		}
		b=b>>1;
		a=a*a%mod;
	}
	return ans;
}

void handle(){
	mp.clear();
	for(int i=1;i*i<=n;i++){
		if(n%i==0){
			if(!mp[i]){
				pp.push_back(i);
				mp[i]=1;
			}
			if(!mp[n/i]){
				mp[n/i]=1;
				pp.push_back(n/i);
			}
		}
	}
}

void solve(int &x){
	double tmp=x;
	for(int i=0;i<pre.size()&&pre[i]<=x;i++){
		if(x%pre[i]==0){
			tmp=tmp*(1-1.0/pre[i]);
		}
	}
	ll xx=tmp;
	mp[x]=xx;
}

int main(void){
	while(scanf("%d",&t)!=EOF){
		while(t--){
			scanf("%d",&m);
			n=1;
			for(ll i=0;i<m;i++){
				scanf("%d %d",&p,&q);
				n=n*q_mod(p,q)%mod;
			}
			for(ll i=2;i<=n;i++){
				if(!mp[i]){
					pre.push_back(i);
					for(ll j=i*i;j<=n;j+=i)
						mp[j]=1;
				}
			}
			handle();
			mp.clear();
			for(int i=0;i<pp.size();i++){
				solve(pp[i]);
			}
			ll ans=0;
			for(int i=0;i<pp.size();i++){
				ans=(ans+mp[pp[i]]*n/pp[i])%mod;
			}
			printf("%lld\n",ans);
			mp.clear();
			pp.clear();
			pre.clear();
		}
	}
	return 0;
}
for(ll i=2;i<=n;i++){
	if(!mp[i]){
		pre.push_back(i);
		for(ll j=i*i;j<=n;j+=i)
			mp[j]=1;
	}
}

