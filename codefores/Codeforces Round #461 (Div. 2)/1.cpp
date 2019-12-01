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

int x,y;
int f,a,b;//a‘≠ º  bøΩ±¥ 

int main(void){
	int i;
	while(scanf("%d %d",&x,&y)!=EOF){
		if(x==0&&y==1){
			printf("Yes\n");
			continue;
		}
		if(y==0||x==0){
			printf("No\n");
			continue;
		}
		f=1;
		b=y-1;
		if(x-b<0||b==0){
			printf("No\n");
			continue;	
		}
		if((x-b)%2==0){
			printf("Yes\n");
		}
		else{
			printf("No\n");
		}
	}
	return 0;
}
