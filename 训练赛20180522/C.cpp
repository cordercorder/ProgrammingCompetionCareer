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

int n;
ll a[55],b[55];
map<ll,ll> mp[4];

void solve(ll id,ll pos,ll res){
	if(pos==n/2){
		return ;
	}
	mp[id][res]++;
	solve(id,pos+1,res|a[pos]);
	solve(id,pos+1,res);
}

void handle(){
	
}



int main(void){
	while(scanf("%lld",&n)!=EOF){
		for(ll i=1;i<=n;i++){
			scanf("%lld",&a[i]);
		}
		for(ll i=1;i<=n;i++){
			scanf("%d",&b[i]);
		}
		
		
		
		
		
		
		
	}
	
	
	return 0;
}
