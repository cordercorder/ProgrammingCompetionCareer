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

int n,m,x; 
int ret;
int p[35];
int cnt;

void handle(int ans,bool f){
	printf("%d\n",ans);
	fflush(stdout);
	scanf("%d",&ret);
	if(ret==1&&f)
		p[cnt++]=1;//correct
	else if(ret==-1&&f)
		p[cnt++]=0;//lie
}

void solve(){
	cnt=0;
	for(int i=0;i<n;i++){
		handle(1,1);
		if(ret==0)
			return ;
	}
	int l=1,r=m+1,mid;
	int tot=0;
	//for(int i=0;i<n;i++){
	//	printf("%d ",p[i]);
	//}
	//puts("");
	while(l<r){
		mid=(l+r)>>1;
		handle(mid,0);
		if(p[tot%n]==1){
			if(ret==1){
				l=mid+1;
			}
			else if(ret==-1){
				r=mid;
			}
			else{
				return ;
			}
		}
		else{
			if(ret==1){
				r=mid;
			}
			else{
				l=mid+1;
			}
		}
		++tot;
	}
}

int main(void){
	scanf("%d %d",&m,&n);
	solve();
	return 0;
}
