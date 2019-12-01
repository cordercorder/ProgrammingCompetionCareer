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

char s[10][10];
int n;
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
int ans;

bool check(int x,int y){
	for(int i=y-1;i>=1;i--){
		if(s[x][i]=='#')
			return 0;
		if(s[x][i]=='X'){
			break;
		}
	}
	for(int i=y+1;i<=n;i++){
		if(s[x][i]=='#')
			return 0;
		if(s[x][i]=='X')
			break;
	}
	for(int i=x-1;i>=1;i--){
		if(s[i][y]=='#')
			return 0;
		if(s[i][y]=='X')
			break;
	}
	for(int i=x+1;i<=n;i++){
		if(s[i][y]=='#')
			return 0;
		if(s[i][y]=='X')
			break;
	}
	return 1;
}

void print(){
	for(int i=1;i<=n;i++){
		puts(s[i]+1);
	}
}


void solve(int pos,int sum){
	ans=max(sum,ans);
	if(pos>n*n)
		return ;
	int x=(pos-1)/n+1;
	int y=(pos-1)%n+1;
	if(s[x][y]=='.'&&check(x,y)){
		s[x][y]='#';
		solve(pos+1,sum+1);
		s[x][y]='.';
		solve(pos+1,sum);
	}
	else{
		solve(pos+1,sum);
	}
}

int main(void){
	while(scanf("%d",&n)!=EOF){
		if(n==0)
			break;
		for(int i=1;i<=n;i++){
			scanf("%s",s[i]+1);
		}
		ans=0;
		solve(1,0);
		printf("%d\n",ans);
	}
	return 0;
}
