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


const int maxn=2e5+10;

ll a[maxn];
ll n;
ll sum[maxn];

void solve(){
	for(ll i=n;i>=0;i--){
		//deb(i);
		//deb(sum[i]);
		//cout<<endl;
		if(sum[i]>=i){
			printf("%lld\n",i);
			return ;
		}
	}
}

int main(void){
	while(scanf("%lld",&n)!=EOF){
		for(int i=0;i<=n;i++){
			scanf("%lld",&a[i]);
		}
		memset(sum,0,sizeof(sum));
		for(int i=n;i>=0;i--){
			sum[i]+=sum[i+1]+a[i];
		}
		solve();
	}
	return 0;
}
