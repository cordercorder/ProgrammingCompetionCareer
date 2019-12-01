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

# define deb(x) printf("# x=%d\n",x)
# define deb_d(x) printf("# x=%lf\n",x)
# define ccout(x) printf("%d\n",x)

typedef long long ll;

using namespace std;

int T;
string s;
int sum[2][30];

void solve(){
	int res;
	memset(sum,0,sizeof(sum));
	for(int i=0;i<s.length();i++){
		sum[i%2][s[i]-'a']++;
	}
	res=*max_element(sum[0],sum[0]+30);
	res+=*max_element(sum[1],sum[1]+30);
	printf("%d\n",(int)s.length()-res);
}

int main(void){
	while(scanf("%d",&T)!=EOF){
		while(T--){
			cin>>s;
			solve();
		}
	}
	return 0;
}
