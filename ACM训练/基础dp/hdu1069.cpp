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
const long long maxw=1e17+10;

typedef long long ll;
typedef pair<int,int> pii;
/*head------[@cordercorder]*/

const int maxn=200;

struct node{
	int x;
	int y;
	int z;
}res[maxn];

int n;
int a[3];
int cnt=0;
int dp[maxn];

void handle(){
	res[++cnt].x=a[0];// 0 1 2
	res[cnt].y=a[1];
	res[cnt].z=a[2];
	res[++cnt].x=a[0];// 0 2 1
	res[cnt].y=a[2];
	res[cnt].z=a[1];
	res[++cnt].x=a[1];//1 0 2
	res[cnt].y=a[0];
	res[cnt].z=a[2];
	res[++cnt].x=a[1];//1 2 0
	res[cnt].y=a[2];
	res[cnt].z=a[0];
	res[++cnt].x=a[2];//2 1 0
	res[cnt].y=a[1];
	res[cnt].z=a[0];
	res[++cnt].x=a[2];//2 0 1
	res[cnt].y=a[0];
	res[cnt].z=a[1];
}

bool cmp(const node &a,const node &b){
	if(a.x<b.x)
		return 1;
	else if(a.x==b.x&&a.y<b.y)
		return 1;
	return 0;
}

void solve(){
	int ans=0;
	sort(res+1,res+1+cnt,cmp);
	//for(int i=1;i<=cnt;i++){
	//	printf("%d %d %d\n",res[i].x,res[i].y,res[i].z);
	//}
	//puts("");
	for(int i=1;i<=cnt;i++){
		dp[i]=res[i].z;
		for(int j=1;j<i;j++){
			if(res[i].x>res[j].x&&res[i].y>res[j].y){
				dp[i]=max(dp[i],dp[j]+res[i].z);
			}
		}
		ans=max(ans,dp[i]);
	}
	printf("%d\n",ans);
}

int main(void){
	int k=0;
	while(scanf("%d",&n)!=EOF){
		if(n==0){
			break;
		}
		cnt=0;
		for(int i=1;i<=n;i++){
			scanf("%d %d %d",&a[0],&a[1],&a[2]);
			handle();
		}
		printf("Case %d: maximum height = ",++k);
		solve();
	}
	return 0;
}
