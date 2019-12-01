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

const int maxn=1e3+10;

struct node{
	int w;
	int s;
	int id;
}res[maxn];

int cnt;
int dp[maxn];
int pre[maxn];

bool cmp(const node &a,const node &b){
	if(a.w<b.w)
		return 1;
	else if(a.w==b.w&&a.s>b.s)
		return 1;
	return 0;
}

void print(int x){
	if(x==0)
		return ;
	print(pre[x]);
	printf("%d\n",x);
}

void solve(){
	int ans;
	sort(res+1,res+1+cnt,cmp);
	for(int i=1;i<=cnt;i++){
		dp[i]=1;
		for(int j=1;j<i;j++){
			if(res[i].w>res[j].w&&res[i].s<res[j].s){
				if(dp[i]<dp[j]+1){
					dp[i]=dp[j]+1;
					pre[res[i].id]=res[j].id;
				}
			}
		}
	}
	ans=1;
	for(int i=1;i<=cnt;i++){
		if(dp[i]>dp[ans]){
			ans=i;
		}
	}
	//deb(ans);
	printf("%d\n",dp[ans]);
	print(res[ans].id);
}

int main(void){
	int a,b;
	cnt=0;
	while(scanf("%d %d",&a,&b)!=EOF){
		res[++cnt].w=a;
		res[cnt].s=b;
		res[cnt].id=cnt;
	}
	solve();
	return 0;
}
