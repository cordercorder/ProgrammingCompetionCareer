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

const int maxn=1e5+10;

int n,k;
bool isv[maxn+maxn+maxn];
int steps[maxn+maxn+maxn];
int Q[maxn+maxn+maxn];
int front,back;

int len;
void solve(){
	int tmp;
	int now;
	len=3*maxn;
	front=0;
	back=0;
	Q[++back]=n;
	steps[n]=0;
	while(front<back){
		now=Q[++front];
		if(now==k){
			printf("%d\n",steps[now]);
			return; 
		}
		if(now-1>=0&&!isv[now-1]){
			steps[now-1]=steps[now]+1;
			isv[now-1]=1;
			Q[++back]=now-1;
		}
		if(now+1<len&&!isv[now+1]){
			steps[now+1]=steps[now]+1;
			isv[now+1]=1;
			Q[++back]=now+1;
		}
		if(now*2<len&&!isv[now*2]){
			steps[now*2]=steps[now]+1;
			isv[now*2]=1;
			Q[++back]=now*2;
		}
	}
}

int main(void){
	scanf("%d %d",&n,&k);
	solve();
	return 0;
}
