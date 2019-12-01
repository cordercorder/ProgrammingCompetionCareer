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

const int maxsize=5e3+10;

int in[maxsize];
int n;
queue<int> q;
vector<int> p[maxsize];

void solve(){
	int i,cnt=0,tmp1,tmp2,tmp3;
	for(i=1;i<=n;i++){
		tmp1=p[i][0];
		tmp2=p[tmp1][0];
		tmp3=p[tmp2][0];
		if(i==tmp3){
			printf("YES\n");
			return;
		}
	}
	printf("NO\n");
}


int main(void){
	int i,tmp;
	while(scanf("%d",&n)!=EOF){
		memset(in,0,sizeof(in));
		for(i=1;i<=n;i++){
			scanf("%d",&tmp);
			p[i].push_back(tmp);
			in[tmp]++;
		}
		solve();
		for(i=1;i<=n;i++)
			p[i].clear();
		
	}
	return 0;
}
