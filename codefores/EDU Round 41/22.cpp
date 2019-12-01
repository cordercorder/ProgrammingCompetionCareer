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

# define deb(x) printf("# x=%d\n",x)
# define deb_d(x) printf("# x=%lf\n",x)
# define ccout(x) printf("%d\n",x)

typedef long long ll;

using namespace std;

const int maxsize=1e5+10;

struct node{
	ll w;
	ll id;
	bool operator<(const node &a)const{
		return id<a.id;
	}
};

ll n,k;
ll ans;

ll a[maxsize],t[maxsize];
ll sum[maxsize];
node num[maxsize];
ll cnt;

void solve(){
	ll ti;
	ll Max=0;
	node tmp;
	tmp.w=0;
	for(ll i=1;i<cnt;i++){
		ti=num[i].id;
		tmp.id=ti+k-1;
		//cout<<"ti=="<<ti<<endl;
		ll j=lower_bound(num+1,num+cnt,tmp)-num-1;
		j++;
		if(j>=cnt)
			j--;
		if(num[j].id>ti+k-1)
			j--;
		//cout<<"j=="<<j<<endl;
		//cout<<"####ti=="<<num[j].id<<endl;
		Max=max(Max,sum[j]-sum[i-1]);
	}
	printf("%lld\n",ans+Max);
}

int main(void){
	while(scanf("%lld %lld",&n,&k)!=EOF){
		sum[0]=0;
		for(ll i=1;i<=n;i++){
			scanf("%lld",&a[i]);
		}
		ans=0;
		cnt=1;
		for(ll i=1;i<=n;i++){
			scanf("%lld",&t[i]);
			if(t[i]==1){
				ans+=a[i];
			}
			else{
				num[cnt].w=a[i];
				num[cnt++].id=i;
			}
		}
		sum[0]=0;
		for(ll i=1;i<cnt;i++){
			sum[i]=sum[i-1]+num[i].w;
		}
		solve();
	}
	return 0;
}
