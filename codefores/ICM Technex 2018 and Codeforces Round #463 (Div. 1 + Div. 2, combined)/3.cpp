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

int p[10]={0,6,5,8,3,4,1,9,2,7};

int f(int i,int j){
	if(j==1)
		return p[i];
	return f(p[i],j-1);
}

int main(void){
	int i;
	for(i=1;i<=9;i++){
		for(int j=1;;j++){
			if(f(i,j)==i){
				printf("g(%d)=%d\n",i,j);
				break;
			}
		}
	}
	
	
	return 0;
}
