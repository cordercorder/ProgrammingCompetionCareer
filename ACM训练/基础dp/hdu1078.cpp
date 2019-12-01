#include<iostream>
#include<algorithm>
#include<cstring>
#include<string>
#include<cmath>
#include<queue>
#include<stack>
#include<set>
#include<vector>
#include<cstdio>
#include<cstdlib>
#include<map>
#include<deque>
#include<limits.h>
#include<bitset>
#include<ctime>

#define deb(x) cout<<"#---"<<#x<<"=="<<x<<endl

using namespace std;

const long double PI=acos(-1.0); 
const long double eps=1e-6;
const int maxw=-1e7-10;

typedef long long ll;
typedef pair<int,int> pii;
/*head------[@cordercorder]*/

const int maxn=1e2+10;

int a[maxn][maxn];
int n,k;
int dp[maxn][maxn];
bool isv[maxn][maxn];

int solve(int x,int y){
	if(isv[x][y]){
		return dp[x][y];
	}
	int ans=a[x][y],tmp;
	for(int i=1;i<=k;i++){
		if(x+i<n&&a[x+i][y]>a[x][y]){
			tmp=solve(x+i,y)+a[x][y];
			ans=max(ans,tmp);
		}
		if(x-i>=0&&a[x-i][y]>a[x][y]){
			tmp=solve(x-i,y)+a[x][y];
			ans=max(ans,tmp);
		}
		if(y+i<n&&a[x][y+i]>a[x][y]){
			tmp=solve(x,y+i)+a[x][y];
			ans=max(ans,tmp);
		}
		if(y-i>=0&&a[x][y-i]>a[x][y]){
			tmp=solve(x,y-i)+a[x][y];
			ans=max(ans,tmp);
		}
	}
	isv[x][y]=1;
	return dp[x][y]=ans;
}

int main(void){
	while(scanf("%d %d",&n,&k)!=EOF){
		if(n==-1&&k==-1)
			break;
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				scanf("%d",&a[i][j]);
			}
		}
		memset(isv,0,sizeof(isv));
		printf("%d\n",solve(0,0));
	}
	return 0;
}
