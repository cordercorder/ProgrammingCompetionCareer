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

const int maxsize=1e6+10;

int p[10][maxsize];
int Q,n;

int f(int n){
	int ans=1,m=1;
	while(m<=n){
		if((n/m)%10){
			ans=ans*((n/m)%10);
		}
		m=m*10;
	}
	return ans; 
}

int g(int n){
	if(n<10)
		return n;
	return g(f(n));
}

int main(void){
	int i,j;
	int l,r,k;
	memset(p,0,sizeof(p));
	for(i=1;i<=1000000;i++){
		p[g(i)][i]++;
	}
	for(i=1;i<10;i++){
		for(j=1;j<=1000000;j++){
			p[i][j]=p[i][j]+p[i][j-1];
		}
	}
	while(scanf("%d",&Q)!=EOF){
		while(Q--){
			scanf("%d %d %d",&l,&r,&k);
			printf("%d\n",p[k][r]-p[k][l-1]);
		}
	}
	return 0;
}
