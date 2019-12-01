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
#define FIN freopen("data.txt","r",stdin)
#define FOUT freopen("data.txt","w",stdout)

using namespace std;

const long double PI=acos(-1.0);  
const long double eps=1e-6;
const long long maxw=1e17+10;

typedef long long ll;
typedef pair<int,int> pii;
/*head------[@cordercorder]*/

const int maxn=1e2+10;

struct node{
	int l;
	int p;
	int s;
}res[maxn];

int n,k;
int q[maxn];
int dp[maxn][16000+100]; 

bool cmp(const node &a,const node &b){
	return a.s<b.s;
}

void solve(){
	int front,back;
	sort(res+1,res+1+k,cmp);
	for(int i=1;i<=k;i++){
		front=0,back=0;		
		for(int j=max(0,res[i].s-res[i].l);j<=res[i].s-1;j++){
			while(front<back&&dp[i-1][q[back]]-q[back]*res[i].p<dp[i-1][j]-j*res[i].p){
				--back;
			}
			q[++back]=j;
		}
		for(int j=1;j<=n;j++){
			dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
			if(j>=res[i].s){
				if(front<back&&q[front+1]<(j-res[i].l)){
					++front;
				}
				if(front<back)
					dp[i][j]=max(dp[i][j],dp[i-1][q[front+1]]-q[front+1]*res[i].p+j*res[i].p);
			}
		}
	}
	printf("%d\n",dp[k][n]);
}

int main(void){
	scanf("%d %d",&n,&k);
	for(int i=1;i<=k;i++){
		scanf("%d %d %d",&res[i].l,&res[i].p,&res[i].s);
	}
	solve();
	return 0;
}
