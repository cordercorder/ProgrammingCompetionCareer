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

ll n,m;

ll solve(ll a,ll b){
	if(b==0){
		return a;
	}
	return solve(b,a%b);
}

int main(void){
	ll ans,tmp;
	while(scanf("%lld %lld",&n,&m)!=EOF){
		tmp=solve(n,m);
		ans=((n*m)/tmp)*(ll)2;
		printf("1/%lld\n",ans);
	}
	return 0;
}
