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

int n;

int main(void){
	int i,j,k,cnt;
	while(scanf("%d",&n)!=EOF){
		cnt=0;
		for(i=1;i<=n;i++){
			for(j=i+1;j<=n;j++){
				for(k=j+1;k<i+j&&k<=n;k++){
					if((i^j^k)==0){
						cnt++;
					}
				}
			}
		}
		printf("%d\n",cnt);
	}
	return 0;
}
