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
//#define DEBUG

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

const ll maxn=30;

ll n,m;
ll k;
ll a[maxn][maxn];
ll ans;
map<ll,ll> mp[maxn][maxn];
ll mid;
vector<ll> p,p2;

void handle1(ll x,ll y,ll res,ll cnt){
	res^=a[x][y];
	if(cnt==mid){
		mp[x][y][res]++;
		p.push_back(res);
		return ;
	}
	if(x<n){
		handle1(x+1,y,res,cnt+1);
	}
	if(y<m){
		handle1(x,y+1,res,cnt+1);
	}
}

void handle2(ll x,ll y,ll res,ll cnt){
	//deb(cnt);
	if(cnt==(n+m-2-mid)){
		ans+=mp[x][y][k^res];
		p2.push_back(res);
		//deb(ans);
		return ;
	}
	if(x>=1){
		handle2(x-1,y,res^a[x][y],cnt+1);
	}
	if(y>=1){
		handle2(x,y-1,res^a[x][y],cnt+1);
	}
}

int main(void){
	scanf("%lld %lld %lld",&n,&m,&k);
	for(ll i=1;i<=n;i++){
		for(ll j=1;j<=m;j++){
			scanf("%lld",&a[i][j]);
		}
	}
	ans=0;
	mid=(n+m-1)>>1;
	handle1(1,1,0,0);
	handle2(n,m,0,0);
	#ifdef DEBUG
	for(ll i=0;i<(ll)p.size();i++){
		cout<<p[i]<<" ";		
	}
	cout<<endl<<endl;
	for(ll i=0;i<(ll)p2.size();i++){
		cout<<p2[i]<<" ";
	}
	cout<<endl;
	#endif
	printf("%lld\n",ans);
	return 0;
}
