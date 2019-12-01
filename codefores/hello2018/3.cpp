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

# define deb(x) printf("# x=%d\n",x)
# define deb_d(x) printf("# x=%lf\n",x)

typedef long long ll;

using namespace std;

const int maxsize=35;
const int maxsize2=1e6+10;

const long long maxw=1e19+10;

ll n,l;

ll ci[maxsize],li[maxsize];

int main(void){
	ll ans,sum,tmp,las;
	
	while(scanf("%lld %lld",&n,&l)!=EOF){
		for(int i=0;i<n;i++){
			scanf("%lld",&ci[i]);
			li[i]=(long long)pow(2,i);
		}
		for(int i=0;i<n-1;i++){
			ci[i+1]=min(ci[i+1],2*ci[i]);
		}
		sum=0;
		ans=maxw;
		las=l;
		for(int i=n-1;i>=0&&las>=0;i--){
			tmp=las/li[i];
			las=las-tmp*li[i];
			sum=sum+tmp*ci[i];
			ans=min(ans,sum+(las>0)*ci[i]);//超过L升的情况 
		}
		printf("%lld\n",ans);
	}
	return 0;
}
