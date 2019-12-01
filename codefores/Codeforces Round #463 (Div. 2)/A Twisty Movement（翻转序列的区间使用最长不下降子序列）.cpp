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

int a[3000];
int cnt[2][3000];

int main(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=n;i++){
		cnt[0][i]=cnt[0][i-1]+(a[i]==1);
		cnt[1][i]=cnt[1][i-1]+(a[i]==2);
	}
	for(int i=1;i<=n;i++){
		printf("%d ",cnt[0][i]);
	}
	printf("\n");
	for(int i=1;i<=n;i++){
		printf("%d ",cnt[1][i]);
	}
	printf("\n\n");
	
	long long res=0;
	for(int i=0;i<=n;i++){
		res=max(res,(long long)cnt[0][i]+cnt[1][n]-cnt[1][i]);
	}
	for(int i=1;i<=n;i++){
		int mid=i;
		for(int j=i;j<=n;j++){
			if(cnt[1][j]-cnt[1][mid]>cnt[0][j]-cnt[0][mid])mid=j;
			res=max(res,(long long)cnt[0][i-1]+cnt[1][n]-cnt[1][j]+cnt[1][mid]-cnt[1][i-1]+cnt[0][j]-cnt[0][mid-1]);
		}
	}
	cout<<res;
	return 0;
}
