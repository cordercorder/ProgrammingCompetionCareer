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

const int maxn=2e5+10;

int n,k;
int v[maxn];
int Max;
int st[maxn][20];
int Log[maxn];

void ST(){
	Log[0]=-1;
	for(int i=1;i<=n;i++){
		st[i][0]=v[i];
		Log[i]=Log[i>>1]+1;
	}
	for(int j=1;(1<<j)<=n;j++){
		for(int i=1;i+(1<<j)-1<=n;i++){
			st[i][j]=max(st[i][j-1],st[i+(1<<(j-1))][j-1]);
		}
	}
}

int query(int L,int R){
	int len=R-L+1,k=-1;
	//while(len){
	//	k++;
	//	len>>=1;
	//}
	k=Log[len];
	return max(st[L][k],st[R-(1<<k)+1][k]); 
}

void solve(){
	ST();
	int i=k/Max,len,ret,sum;
	for(;i<=n;i++){
		ret=n/i;
		len=ret*i;
		sum=0;
		for(int j=1;j<=len;j+=ret){
			if(j+ret-1>len)
				break;
			sum+=query(j,j+ret-1);
		}
		if(sum>k){
			printf("%d\n",i);
			return ;
		}
	}
}

int main(void){
	int sum; 
	while(scanf("%d %d",&n,&k)!=EOF){
		if(n<0&&k<0)
			break;
		Max=-1;
		sum=0;
		for(int i=1;i<=n;i++){
			scanf("%d",&v[i]);
			Max=max(Max,v[i]);
			sum+=v[i];
		}
		if(sum<=k){
			puts("-1");
			continue;
		}
		if(Max>k){
			puts("1");
			continue;
		}
		solve();
	}
	return 0;
}
