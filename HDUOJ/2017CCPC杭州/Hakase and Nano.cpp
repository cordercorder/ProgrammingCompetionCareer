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

const int maxn=1e6+10;

ll t;
ll n,d;
ll a[maxn];
ll sum,res;

void solve(){
	ll tmp;
	if(d==1){
		tmp=sum%3;
		if(tmp==0){
			puts("No");
		}
		else{
			puts("Yes");
		}
	}
	else{
		tmp=sum%3;
		//cout<<"tmp=="<<tmp<<endl;
		if(tmp==1){
			puts("No");
		}
		else{
			puts("Yes");
		}
	}
}

int main(void){
	ll tmp;
	while(scanf("%lld",&t)!=EOF){
		while(t--){
			scanf("%lld %lld",&n,&d);
			sum=0;
			res=0;
			for(ll i=1;i<=n;i++){
				scanf("%lld",&a[i]);
				sum+=a[i];
				if(a[i]==1)
					res++;
			}
			if(sum==n){
				solve();
			}
			else if(res==n-1){
				if(d==1){
					puts("Yes");
				}
				else{
					if(res%3==0||n%3==0){
						puts("No");
					} 
					else{
						puts("Yes");
					}
				}
			}
			else{
				puts("Yes");
			}
		}
	}
	return 0;
}
