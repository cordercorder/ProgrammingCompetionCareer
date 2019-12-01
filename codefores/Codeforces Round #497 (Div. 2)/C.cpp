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

int a[maxn];
int tmp[maxn];
int n;

void solve(){
	int ans=0,pos=1;
	sort(tmp+1,tmp+1+n);
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		pos=upper_bound(a+pos,a+1+n,tmp[i])-a;
	//	deb(pos);
		if(pos!=(n+1)){
			pos++; 
			ans++;
		}
		else{
			break;
		}
	}
	printf("%d\n",ans);
}

int main(void){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		tmp[i]=a[i];
	}
	solve();
	return 0;
}
