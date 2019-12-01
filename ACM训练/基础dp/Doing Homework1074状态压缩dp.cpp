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
# include<map>
# include<deque>
# include<limits.h>
# include<ctime>

# define deb(x) cout<<"#---"<<#x<<"=="<<x<<endl

typedef long long ll;

using namespace std;

const int maxn=20;

struct node{
	char s[105];
	int C;
	int D;
}a[maxn];

struct node1{
	int cost;
	int pre;
	int ans;
}dp[(1<<16)+5];

int n;
bool isv[(1<<16)+5];
int t;

void print(int x){
	int nx=dp[x].pre^x;
	int cnt=0;
	while(nx!=1){
		nx>>=1;
		cnt++;
	}
	//deb(dp[x].pre);
	if(dp[x].pre!=0){
		print(dp[x].pre);
	}
	puts(a[cnt].s);
}

void solve(){
	int len=(1<<n)-1;
	int now,res,sum;
	memset(isv,0,sizeof(isv));
	dp[0].ans=0;
	dp[0].cost=0;
	dp[0].pre=-1;
	isv[0]=1;
	for(int status=0;status<len;status++){
		for(int i=0;i<n;i++){
			res=(1<<i);
			if((res&status)==0){//状态stauts能做i作业的条件是状态status中i作业未做 
				now=res|status;
				int tmp=dp[status].cost+a[i].C;
				dp[now].cost=tmp;
				sum=tmp-a[i].D;
				if(sum<0)
					sum=0;
				sum+=dp[status].ans;//被减少的分数相加 
				if(isv[now]){
					if(sum<dp[now].ans){
						dp[now].ans=sum;
						dp[now].pre=status;//dp[status|res].pre=status
					}
					else if(sum==dp[now].ans){
						if(status<dp[now].pre){
							dp[now].pre=status;
						}
					}
				}
				else{
					isv[now]=1;
					dp[now].ans=sum;
					dp[now].pre=status;
				}
			}
		}
	}
	printf("%d\n",dp[len].ans);
	print(len);
}

int main(void){
	while(scanf("%d",&t)!=EOF){
		while(t--){
			scanf("%d",&n);
			for(int i=0;i<n;i++){
				scanf("%s %d %d",a[i].s,&a[i].D,&a[i].C);
			}
			solve();
		}
	}
	return 0;
}
