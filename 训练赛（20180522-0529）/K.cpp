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

ll a,b,c,d;

int main(void){
	ll tmp1,tmp2,tmp3,tmp4;
	ll ans;
	while(scanf("%lld %lld %lld %lld",&a,&b,&c,&d)!=EOF){
		ans=0;
		tmp1=b/2-(a-1)/2-(b/2018-(a-1)/2018);
		tmp2=d/1009-(c-1)/1009;
		tmp3=tmp1;
		ans+=tmp1*tmp2;
		tmp1=b/1009-(a-1)/1009-(b/2018-(a-1)/2018);
		tmp4=tmp1;
		tmp2=d/2-(c-1)/2;
		ans+=tmp1*tmp2;
		tmp1=b/2018-(a-1)/2018;
		tmp2=d/2018-(c-1)/2018;
		ans+=tmp1*(d-c+1);
		ans+=tmp2*(b-a+1-tmp3-tmp4-(b/2018-(a-1)/2018));
		printf("%lld\n",ans);
	}
	return 0;
}
