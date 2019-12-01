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

const int maxsize=1e3+10;

int n,m;
int a[maxsize];
int num[maxsize];

bool check(){
	for(int i=1;i<=n;i++){
		if(num[i]==0)
			return 0;
	}
	return 1;
}

int main(void){
	int ans;
	while(scanf("%d %d",&n,&m)!=EOF){
		memset(num,0,sizeof(num));
		ans=0;
		for(int i=1;i<=m;i++){
			scanf("%d",&a[i]);
			num[a[i]]++;
			if(check()){
				for(int j=1;j<=n;j++){
					num[j]--;
				}
				ans++;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
