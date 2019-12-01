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

const int maxn=1e3+10;

ll a[maxn];
ll n;
ll num[2];

int main(void){
	ll tmp;
	while(scanf("%lld",&n)!=EOF){
		num[0]=0;
		num[1]=0;
		for(ll i=1;i<=n;i++){
			scanf("%lld",&a[i]);
			if(a[i]==0)
				num[0]++;
			else
				num[1]++;
			
		}
		if(num[0]==0){
			puts("-1");
			continue;
		}
		tmp=num[1]/9;
		if(tmp==0){
			puts("0");
			continue;
		}
		for(ll i=0;i<tmp;i++){
			for(ll j=0;j<9;j++){
				putchar('5');
			}
		}
		for(ll i=0;i<num[0];i++){
			putchar('0');
		}
	}
	return 0;
}
