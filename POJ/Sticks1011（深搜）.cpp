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

# define deb(x) printf("# x=%d\n",x)
# define deb_d(x) printf("# x=%lf\n",x)
# define ccout(x) printf("%d\n",x)

typedef long long ll;

using namespace std;

const int maxsize=1e2+10;

int n;
int a[maxsize];
int Max;
int sum;
int isv[maxsize];

int check(int len,int stick,int ret){
	if(stick==n||ret==0)
		return len;
	if(ret==0)
		ret=len;
	for(int i=0;i<n;i++){
		if(isv[i])
			continue;
		if(a[i]>ret)
			continue;
		isv[i]=1;
		if(check(len,stick+1,ret-a[i]))
			return len;
		isv[i]=0;
		if(ret==a[i]||len==ret)
			break;
		while(a[i]==a[i+1])
			i++;
	}
	return 0;
}

void solve(){
	int ans;
	for(int i=1;i<=sum;i++){
		if(sum%i!=0)
			continue;
		memset(isv,0,sizeof(isv));
		ans=check(i,0,i);
		if(ans!=0){
			printf("%d\n",ans);
			return ;
		}
	}
}

bool cmp(const int &a,const int &b){
	return a>b;
}

int main(void){
	int tmp;
	while(scanf("%d",&n)!=EOF){
		if(n==0)
			break;
		Max=-1;
		sum=0; 
		for(int i=0;i<n;i++){
			scanf("%d",&a[i]);
			Max=max(Max,a[i]);
			sum+=a[i];
		}
		sort(a,a+n,cmp);
		solve();
	}
	return 0;
}
