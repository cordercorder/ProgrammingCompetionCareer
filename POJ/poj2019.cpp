#include<algorithm>
#include<iostream>
#include<limits.h>
#include<cstdlib>
#include<cstring>
#include<vector>
#include<string>
#include<cstdio>
#include<bitset>
#include<cmath>
#include<queue>
#include<stack>
#include<deque>
#include<ctime>
#include<set>
#include<map>

#define deb(x) cout<<"#---"<<#x<<"=="<<x<<endl
#define FC ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define FIN freopen("in.txt","r",stdin)
#define FOUT freopen("out.txt","w",stdout)

using namespace std;

const long double PI=acos(-1.0);  
const long double eps=1e-6;
const long long maxw=1e17+10;

typedef long long ll;
typedef pair<int,int> pii;
/*head------[@cordercorder]*/

const int maxn=255;

int a[maxn][maxn];
int n,b,k;
int x,y;
int st[maxn][maxn][10][2];
int Log[maxn];

void ST(int id){
	for(int i=1;i<=n;i++){
		st[id][i][0][0]=a[id][i];
		st[id][i][0][1]=a[id][i];
	}
	for(int j=1;(1<<j)<=n;j++){
		for(int i=1;i+(1<<j)-1<=n;i++){
			st[id][i][j][0]=max(st[id][i][j-1][0],st[id][i+(1<<(j-1))][j-1][0]);
			st[id][i][j][1]=min(st[id][i][j-1][1],st[id][i+(1<<(j-1))][j-1][1]);
		}
	}
}

int cal(int id,int L,int R,bool f){
	int k=Log[R-L+1];
	if(f)
		return max(st[id][L][k][0],st[id][R-(1<<k)+1][k][0]);
	return min(st[id][L][k][1],st[id][R-(1<<k)+1][k][1]);
}

void solve(){
	int Max=-1,Min=255;
	for(int i=x;i<=x+b-1;i++){
		Max=max(Max,cal(i,y,y+b-1,1));
		Min=min(Min,cal(i,y,y+b-1,0));
	}
	printf("%d\n",Max-Min);
}

int main(void){
	scanf("%d %d %d",&n,&b,&k);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			scanf("%d",&a[i][j]);
		}
	}
	Log[0]=-1;
	for(int i=1;i<=n;i++){
		Log[i]=Log[i>>1]+1;
	}
	for(int i=1;i<=n;i++){
		ST(i);
	}
	while(k--){
		scanf("%d %d",&x,&y);
		solve();
	}
	return 0;
}
