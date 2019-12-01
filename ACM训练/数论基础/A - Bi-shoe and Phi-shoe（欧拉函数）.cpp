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

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

const int maxn=1000003+10;

int a[maxn];
int n,T;
int num[10005];

void handle(int x){
	a[1]=0;
	for(int i=2;i<=x;i++)
		a[i]=i;
	for(int i=2;i<=x;i++){
		if(a[i]==i){
			for(int j=i;j<=x;j+=i)
				a[j]=a[j]/i*(i-1);
		}
	}
}

int main(void){
	handle(1000003);
	ll ans;
	int sum;
	while(scanf("%d",&T)!=EOF){
		sum=0;
		while(T--){
			scanf("%d",&n);
			for(int i=1;i<=n;i++){
				scanf("%d",&num[i]);
			}
			sort(num+1,num+1+n);
			ans=0;
			int tmp,l=1;
			for(int i=1;i<=n;i++){
				while(a[l]<num[i]){
					l++;
				}
				ans+=l;
			} 
			printf("Case %d: %lld Xukha\n",++sum,ans);
		}
	}
	return 0;
}
