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
const int maxw=1e8+10;

typedef long long ll;
typedef pair<int,int> pii;
/*head------[@cordercorder]*/

const int maxn=1e3+10;

struct node{
	int x;
	int y;
	int h;	
};

int t;
int N,X,Y,MAX;
node res[maxn];
int dp[maxn][2];

bool cmp(const node &a,const node &b){
	return a.h<b.h;
}

void solve(){
	bool f;
	sort(res+1,res+N+1,cmp);
	for(int i=1;i<=N+1;i++){
		int j=i-1;
		f=0;
		while(j>=0){
			if(res[j].x<=res[i].x&&res[i].x<=res[j].y&&res[i].h-res[j].h<=MAX){
				if(j==0){
					dp[i][0]=res[i].h-res[j].h;
					f=1;
					break;
				}
				dp[i][0]=res[i].h-res[j].h+min(dp[j][0]+res[i].x-res[j].x,dp[j][1]+res[j].y-res[i].x);
				f=1;
				break;
			}
			else{
				j--;
			}
		}
		if(!f){
			dp[i][0]=maxw;
		}
		j=i-1;
		f=0;
		while(j>=0){
			if(res[j].x<=res[i].y&&res[i].y<=res[j].y&&res[i].h-res[j].h<=MAX){
				if(j==0){
					dp[i][1]=res[i].h-res[j].h;
					f=1;
					break;
				}
				dp[i][1]=res[i].h-res[j].h+min(dp[j][0]+res[i].y-res[j].x,dp[j][1]+res[j].y-res[i].y);
				f=1;
				break;
			}
			else{
				j--;
			}
		}
		if(!f){
			dp[i][1]=maxw;
		}
	}
	//for(int i=1;i<=N;i++){
	//	printf("%d  %d\n",dp[i][0],dp[i][1]);
	//}
	//puts("");
	int ans=min(dp[N+1][0],dp[N+1][1]);
	printf("%d\n",ans);
}

int main(void){
	scanf("%d",&t);
	while(t--){
		scanf("%d %d %d %d",&N,&X,&Y,&MAX);
		for(int i=1;i<=N;i++){
			scanf("%d %d %d",&res[i].x,&res[i].y,&res[i].h);
		}
		res[0].x=-20000-10;
		res[0].y=20000+10;
		res[0].h=0;
		res[N+1].x=X;
		res[N+1].y=X;
		res[N+1].h=Y;
		solve();
	}
	return 0;
}
