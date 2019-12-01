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

const int maxsize=1e2+10;
const int maxw=1e8+10;

string str;

int dp[maxsize][maxsize],c[maxsize][maxsize];

void solve(){
	memset(dp,0,sizeof(dp));
	for(int i=0;i<str.length();i++)
		dp[i][i]=1;
	int len;
	for(len=1;len<(int)str.length();len++){
		for(int i=0;i<(int)str.length()-len;i++){
			int j=i+len;
			dp[i][j]=maxw;
			if((str[i]=='('&&str[j]==')')||(str[i]=='['&&str[j]==']')){
				dp[i][j]=dp[i+1][j-1];
				c[i][j]=-1;
			}
			for(int k=i;k<j;k++){
				if(dp[i][j]>dp[i][k]+dp[k+1][j]){
					dp[i][j]=dp[i][k]+dp[k+1][j];
					c[i][j]=k;
				}
			}
		}
	}
}

void print(int x,int y){
	if(x>y)
		return ;
	if(x==y){
		if(str[x]=='('||str[x]==')')
			printf("()");
		else 
			printf("[]");
	}
	else if(c[x][y]==-1){
		printf("%c",str[x]);
		print(x+1,y-1);
		printf("%c",str[y]);
	}
	else{
		print(x,c[x][y]);
		print(c[x][y]+1,y);
	}
}

int main(void){
	while(getline(cin,str)){
		solve();
		print(0,(int)str.length()-1);
		printf("\n");
	}
	return 0;
}
