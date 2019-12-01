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

ll k;

ll num[10]={1,0,0,0,1,0,1,0,2,1};

int main(void){
	int i;
	int e,s;
	while(scanf("%lld",&k)!=EOF){
		if(k>36){
			printf("-1\n");
			continue;
		}
		e=k/2;
		s=k-2*e;
		for(i=0;i<e;i++){
			printf("8");
		}
		for(i=0;i<s;i++){
			printf("6");
		}
		printf("\n");
	}
	return 0;
}
