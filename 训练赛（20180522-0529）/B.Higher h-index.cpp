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

int main(void){
	ll n,a;
	ll ans;
	while(scanf("%lld %lld",&n,&a)!=EOF){
		ans=a+((n-a)>>1);
		printf("%lld\n",ans);
	}
	return 0;
}
