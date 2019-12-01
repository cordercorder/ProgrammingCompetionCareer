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
# include<limits.h>
# include<ctime>

# define deb(x) cout<<"#---"<<#x<<"=="<<x<<endl

using namespace std;

typedef long long ll;
typedef pair<long double,int> pii;

const int maxn=1e3+10;

pii p[maxn];
int n;

int main(void){
	long double tmp1,tmp2,tmp3;
	while(scanf("%d",&n)!=EOF){
		for(int i=1;i<=n;i++){
			scanf("%Lf %Lf %Lf",&tmp1,&tmp2,&tmp3);
			p[i].first=(tmp1+tmp2)/tmp3;
			p[i].second=i;
		}
		sort(p+1,p+1+n);
		printf("%d",p[1].second);
		for(int i=2;i<=n;i++){
			printf(" %d",p[i].second);
		}
		printf("\n");
	}
	return 0;
}
