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

const int maxn=1e2+10;

int n;
int num[maxn];

int main(void){
	int tmp;
	while(scanf("%d",&n)!=EOF){
		memset(num,0,sizeof(num));
		for(int i=1;i<=n;i++){
			scanf("%d",&tmp);
			num[tmp]++;
		} 
		sort(num,num+101);
		printf("%d\n",num[100]);
	}
	return 0;
}
