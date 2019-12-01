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

# define deb(x) printf("# x=%d\n",x)
# define deb_d(x) printf("# x=%lf\n",x)
# define ccout(x) printf("%d\n",x)

typedef long long ll;

using namespace std;

int n;

int main(void){
	
	while(scanf("%d",&n)!=EOF){
		if(n&1){
			puts("Ehab");
		}
		else{
			puts("Mahmoud");
		}
	}
	return 0;
}
