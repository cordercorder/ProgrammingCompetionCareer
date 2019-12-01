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
int cnt;

int main(void){
	
	while(scanf("%d",&n)!=EOF){
		cnt=2;
		if(n<=5){
			puts("-1");
			for(int i=0;i<n-1;i++){
				printf("1 %d\n",cnt++);
			}
		}
		else{
			for(int i=0;i<n-3;i++){
				printf("1 %d\n",cnt++);
			}
			for(int i=0;i<2;i++){
				printf("2 %d\n",cnt++);
			}
			cnt=2;
			for(int i=0;i<n-1;i++){
				printf("1 %d\n",cnt++);
			}
		}
	}
	return 0;
}
