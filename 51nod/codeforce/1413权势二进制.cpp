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
typedef pair<int,int> pii;

const int maxn=1e6+10;

int n;

void solve(const int &x){
	int m=1,tmp;
	int ans=0;
	while(m<=x){
		tmp=(x/m)%10;
		m*=10;
		ans=max(ans,tmp);
	}
	printf("%d\n",ans);
}

int main(void){
	while(scanf("%d",&n)!=EOF){
		solve(n);
	}
	return 0;
}
