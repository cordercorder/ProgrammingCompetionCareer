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
# define ccout(x) printf("%d\n",x)

typedef long long ll;

using namespace std;

const int maxn=8e4+10;

int a[maxn];
stack<int> s;
int n;
int R[maxn];

void handle(){
	while(!s.empty())
		s.pop(); 
}

void solve(){
	for(int i=n;i>=1;i--){
		while(s.size()&&a[s.top()]<a[i])
			s.pop();
		if(s.empty())
			R[i]=n+1;
		else
			R[i]=s.top();
		s.push(i);
	}
	handle();
	ll ans=0;
	for(int i=1;i<=n;i++){
		ans+=(ll)(R[i]-i-1);
		//deb(R[i]);
	}
	printf("%lld\n",ans);
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
