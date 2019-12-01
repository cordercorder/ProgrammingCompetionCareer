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

int n,m; 

int main(void){
	int i;
	while(scanf("%d %d",&n,&m)!=EOF){
		if(n>=27){
			printf("%d\n",m);
		}
		else{
			int tmp=pow(2,n);
			printf("%d\n",m%tmp);
		}
	}
	return 0;
}
