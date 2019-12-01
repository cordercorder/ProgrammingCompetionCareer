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

typedef long long ll;
typedef pair<int,int> pii;

const int maxn=1e2+10;

int N,W;
int Wi[10000+10],Pi[10000+10];
int cnt;
int x1,x2,x3;
int dp[50000+10];

void handle(){
	int ret=1;
	while(x3>=ret){
		x3-=ret;
		Wi[++cnt]=x1*ret;
		Pi[cnt]=x2*ret;
		ret<<=1;
	}
	if(x3){
		Wi[++cnt]=x1*x3;
		Pi[cnt]=x2*x3;
	}
}

void solve(){
	for(int i=1;i<=cnt;i++){
		for(int j=W;j>=Wi[i];j--){
			dp[j]=max(dp[j],dp[j-Wi[i]]+Pi[i]);
		}
	}
	printf("%d\n",dp[W]);
}

int main(void){
	scanf("%d %d",&N,&W);
	cnt=0;
	for(int i=1;i<=N;i++){
		scanf("%d %d %d",&x1,&x2,&x3);
		handle();
	}
	solve();
	return 0;
}
