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

int t;
int x;

int main(void){
	int i,j,tmp,xx;
	bool flag;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&x);
		flag=0;
		for(i=sqrt(x)+1;i<=40000;i++){
			tmp=i*i-x;
			xx=sqrt(tmp);
			if(xx*xx==tmp){
				if(i/xx>i/(xx+1)){
					printf("%d %d\n",i,i/xx);
					flag=1;
					break;
				}
			}
		}
		if(!flag){
			printf("-1\n");
		}
	}
	return 0;
}
