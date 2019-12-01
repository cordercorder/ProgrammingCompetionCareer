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

# define deb(x) printf("# x=%d\n",x)
# define deb_d(x) printf("# x=%lf\n",x)

typedef long long ll;

using namespace std;

ll n,k;

bool check(){
	ll i,j;
	for(i=1;i<k;i++){
		for(j=i+1;j<=k;j++){
			if(n%i==n%j)
				return 0;
		}
	}
	return 1;
}

int main(void){
	ll i;
	while(scanf("%lld %lld",&n,&k)!=EOF){
		if(k==1){
			printf("Yes\n");
			continue;
		}
		if(n==1&&k>2){
			printf("No\n");
			continue;
		}
		if(k>=n&&k>2){
			printf("No\n");
			continue;
		}
		if(n%2==0){
			printf("No\n");
			continue;	
		}
		if(k<=10000&&check()){
			printf("Yes\n");
		}
		else{
			printf("No\n");
		}
	}
	return 0;
}
