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

typedef long long ll;
typedef pair<int,int> pii;

const int maxn=1e5+10;

struct node{
	int w;
	int h;
}res[maxn];

int n;

void solve(){
	int ret=max(res[1].h,res[1].w),tmp;
	for(int i=2;i<=n;i++){
		tmp=min(res[i].h,res[i].w);
		if(ret>=tmp){
			if(max(res[i].h,res[i].w)<=ret){
				ret=max(res[i].h,res[i].w);
			}
			else{
				ret=tmp;
			}
		}
		else{
			puts("NO");
			return ;
		}
	}
	puts("YES");
}

int main(void){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d %d",&res[i].w,&res[i].h);
	}
	solve();
	return 0;
}
