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
//#define myfault

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

const int maxn=1e3+10;

int n,m;
pii res[maxn];
int a[maxn];

#ifdef myfault
void solve(){
	sort(res+1,res+1+m);
	memset(a,0,sizeof(a));
	int tmp,r=0,sum;
	for(int i=1;i<=m;i++){
		tmp=res[i].second-res[i].first+1;
		if(res[i].second<=r){
			continue;
		}
		else if(res[i].first>r){
			sum=0;
			for(int j=res[i].first;j<=res[i].second;j++){
				if(sum<tmp/2){
					a[j]=1;
					sum++;
				}
				else{
					a[j]=0;
				}
			}
			r=res[i].second;
		}
		else{
			sum=0;
			for(int j=res[i].first;j<=r;j++){
				sum=sum+(a[j]==1);
			}
			for(int j=r+1;j<=res[i].second;j++){
				if(sum<tmp/2){
					a[j]=1;
					sum++;
				}
			}
			r=res[i].second;
		}
	}
	for(int i=1;i<=n;i++){
		printf("%d",a[i]);
	}
	printf("\n");
}
#endif

int main(void){
	scanf("%d %d",&n,&m);
	for(int i=1;i<=m;i++){
		scanf("%d %d",&res[i].first,&res[i].second);
	}
	#ifdef myfault
	solve();
	#endif
	for(int i=1;i<=n;i++){
		if(i&1){
			a[i]=1;
		}
		else{
			a[i]=0;
		}
		printf("%d",a[i]);
	}
	printf("\n");
	return 0;
}
