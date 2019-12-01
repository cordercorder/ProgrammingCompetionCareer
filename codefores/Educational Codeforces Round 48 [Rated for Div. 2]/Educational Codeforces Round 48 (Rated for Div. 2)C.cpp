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

const long double PI=acos(-1.0); 
const long double eps=1e-6;
const long long maxw=1e17+10;

typedef long long ll;
typedef pair<int,int> pii;
/*head------[@cordercorder]*/

const int maxn=3e5+10;

ll res[3][maxn],sumL[3][maxn],sumR[3][maxn];
ll n;
ll l_sum[3][maxn],r_sum[3][maxn];
ll num[maxn];

void handle(){
	l_sum[1][0]=0;
	l_sum[2][0]=0;
	for(ll i=1;i<=n;i++){
		l_sum[1][i]=l_sum[1][i-1]+sumL[1][i];
		l_sum[2][i]=l_sum[2][i-1]+sumL[2][i];
	}
	r_sum[1][n+1]=0;
	r_sum[2][n+1]=0;
	sumR[1][n+1]=0;
	sumR[2][n+1]=0;
	for(ll i=1;i<=2;i++){
		for(ll j=n;j>=1;j--){
			sumR[i][j]=sumR[i][j+1]+res[i][j];
		}
	}
	for(ll i=n;i>=1;i--){
		r_sum[1][i]=r_sum[1][i+1]+sumR[1][i]; 
		r_sum[2][i]=r_sum[2][i+1]+sumR[2][i];
	}
}

void solve(){
	handle(); 
	ll x=1,y=1,cnt=0,len=2*n,tmp=0,tot=0;
	while(cnt<len){
		if(cnt%4==0){
			tmp+=(res[x][y]*cnt);
			x++;
		}
		else if(cnt%4==1){
			tmp+=(res[x][y]*cnt);
			y++;
		}
		else if(cnt%4==2){
			tmp+=(res[x][y]*cnt);
			x--;
		}
		else{
			tmp+=(res[x][y]*cnt);
			y++;
		}
		if(cnt&1){
			num[++tot]=tmp;
			//deb(tmp);
		}
		cnt++;
	}
	ll ans=0;
	for(ll i=1;i<=n;i++){
		if(i&1){			
			tmp=num[i-1]+r_sum[1][i]+(2*i-3)*sumR[1][i]+l_sum[2][n]-(l_sum[2][i-1]+(n-i+1)*sumL[2][i-1])+(n+i-2)*(sumR[2][i]);
		}
		else{
			tmp=num[i-1]+r_sum[2][i]+(2*i-3)*sumR[2][i]+l_sum[1][n]-(l_sum[1][i-1]+(n-i+1)*sumL[1][i-1])+(n+i-2)*(sumR[1][i]);
		}
		ans=max(ans,tmp);
	}
	printf("%lld\n",ans);
}

int main(void){
	scanf("%lld",&n);
	sumL[1][0]=0;
	sumL[2][0]=0;
	for(ll i=1;i<=2;i++){
		for(ll j=1;j<=n;j++){
			scanf("%lld",&res[i][j]);
			sumL[i][j]=sumL[i][j-1]+res[i][j];
		}
	}
	solve(); 
	return 0;
}
