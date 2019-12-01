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

const int maxn=2e3+10;

struct node{
	int data;
	int pos;
}res[maxn];

int a[maxn];
int n,k;
vector<int>ret;

bool cmp(const node &a,const node &b){
	return a.data>b.data;
}



void solve(){
	stable_sort(res+1,res+1+n,cmp);
	int ans=0;
	for(int i=1;i<=k;i++){
		ans+=res[i].data;
		ret.push_back(res[i].pos);
	}
	printf("%d\n",ans);
	if(ret.size()==1){
		printf("%d\n",n);
		ret.clear();
		return ;
	}
	sort(ret.begin(),ret.end());
	printf("%d ",ret[0]);
	for(int i=1;i<(int)ret.size()-1;i++){
		printf("%d ",ret[i]-ret[i-1]);
	}
	printf("%d\n",n-ret[(int)ret.size()-2]);
	ret.clear();
}

int main(void){
	while(scanf("%d %d",&n,&k)!=EOF){
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
			res[i].data=a[i];
			res[i].pos=i;
		}
		solve();
	}
	return 0;
}
