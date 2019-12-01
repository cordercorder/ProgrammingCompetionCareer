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

const int maxize=100;

const int maxsize=5e3+10;

int n;
string s;
int dp[2][maxsize];

int main(void){
	int tmp;
	string str;
	while(scanf("%d",&n)!=EOF){
		cin>>s;
		str=s;
		reverse(s.begin(),s.end());
		memset(dp,0,sizeof(dp));
		for(int i=1;i<=(int)s.length();i++){
			for(int j=1;j<=(int)s.length();j++){
				if(s[i-1]==str[j-1])
					dp[i%2][j]=dp[(i-1)%2][j-1]+1;
				else
					dp[i%2][j]=max(dp[(i-1)%2][j],dp[i%2][j-1]);
			}
		}
		printf("%d\n",(int)s.length()-dp[(int)s.length()%2][(int)s.length()]); 
	}
	return 0;
}
