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
#include<ctime>

#define deb(x) cout<<"#---"<<#x<<"=="<<x<<endl

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

const int maxn=1e3+10;

int n;
int a[maxn];
int cnt;
int res[maxn];

void solve(){
	int sum=1;
	cnt=0;
	for(int i=1;i<n;i++){
		if(a[i]<a[i+1]){
			sum++;
		}
		else{
			res[cnt++]=sum;
			sum=1;
		}
	}
	res[cnt++]=sum;
	printf("%d\n",cnt);
	printf("%d",res[0]);
	for(int i=1;i<cnt;i++){
		printf(" %d",res[i]);
	}
	printf("\n");
}

int main(void){
	while(scanf("%d",&n)!=EOF){
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
		}
		solve();
	}
	
	return 0;
}
