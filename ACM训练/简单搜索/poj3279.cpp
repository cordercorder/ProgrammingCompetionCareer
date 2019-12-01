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
const int maxw=1e9+10;

typedef long long ll;
typedef pair<int,int> pii;
/*head------[@cordercorder]*/

const int maxn=20;

int a[maxn][maxn];
int res[maxn][maxn];
int m,n;
int dx[4]={0,1,0,-1};
int dy[4]={1,0,-1,0};
int ret[maxn][maxn];

int handle(int x,int y){
	int sum=a[x][y];
	sum+=res[x][y];
	int nx,ny;
	for(int i=0;i<4;i++){
		nx=x+dx[i];
		ny=y+dy[i];
		if(nx>=0&&nx<m&&ny>=0&&ny<n){
			sum+=res[nx][ny];
		}
	}
	return sum&1;
}

int cal(){
	for(int i=1;i<m;i++){
		for(int j=0;j<n;j++){
			if(handle(i-1,j)){
				res[i][j]=1;
			}
		}
	}
	for(int i=0;i<n;i++){
		if(handle(m-1,i)){
			return maxw;
		}
	}
	int ans=0;
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			ans+=res[i][j];
		}
	}
	return ans;
}

void solve(){
	int len=(1<<n);
	int ans=maxw,tmp;
	for(int i=0;i<len;i++){
		memset(res,0,sizeof(res));
		for(int j=0;j<n;j++){
			res[0][j]=(i>>j)&1;
		}
		tmp=cal();
		if(tmp<ans){
			ans=tmp;
			for(int i=0;i<m;i++){
				for(int j=0;j<n;j++){
					ret[i][j]=res[i][j];
				}
			}
		}
	}
	if(ans==maxw){
		puts("IMPOSSIBLE");
		return ;
	}
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			if(j==(n-1)){
				printf("%d\n",ret[i][j]);
				continue;
			}
			printf("%d ",ret[i][j]);
		}
	}
	printf("\n");
}

int main(void){
	scanf("%d %d",&m,&n);
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			scanf("%d",&a[i][j]);
		}
	}
	solve();
	return 0;
}
