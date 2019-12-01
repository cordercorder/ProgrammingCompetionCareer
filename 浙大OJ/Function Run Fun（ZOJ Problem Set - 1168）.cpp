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

# define ll long long

using namespace std;

const int maxsize=25;

int dp[maxsize][maxsize][maxsize];

int fun(int a,int b,int c){
	int res;
	if(a<=0||b<=0||c<=0){
		return 1;
	}
	if(a<=20&&b<=20&&c<=20&&dp[a][b][c]>=0){
		return dp[a][b][c];
	}
	else if(a>20||b>20||c>20){
		return fun(20,20,20);
	}
	else if(a<b&&b<c){
		return fun(a,b,c-1)+fun(a,b-1,c-1)-fun(a,b-1,c);
	}
	else{
		return fun(a-1,b,c)+fun(a-1,b-1,c)+fun(a-1, b, c-1)-fun(a-1,b-1,c-1);
	}
}

int main(void){
	int a,b,c;
	int i,j,k;
	memset(dp,-1,sizeof(dp));
	for(i=0;i<=20;i++){
		for(j=0;j<=20;j++){
			for(k=0;k<=20;k++){
				dp[i][j][k]=fun(i,j,k);
			}
		}
	}
	while(scanf("%d %d %d",&a,&b,&c)!=EOF){
		if(a==-1&&b==-1&&c==-1)
			break;
		if(a<=0||b<=0||c<=0){
			printf("w(%d, %d, %d) = 1\n",a,b,c);
		}
		else{
			printf("w(%d, %d, %d) = %d\n",a,b,c,fun(a,b,c));
		}
	}
	return 0;
}
