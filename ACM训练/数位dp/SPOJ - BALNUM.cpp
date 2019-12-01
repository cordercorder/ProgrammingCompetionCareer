#include<algorithm>
#include<iostream>
#include<limits.h>
#include<cstdlib>
#include<cstring>
#include<vector>
#include<string>
#include<cstdio>
#include<bitset>
#include<cmath>
#include<queue>
#include<stack>
#include<deque>
#include<ctime>
#include<set>
#include<map>

#define deb(x) cout<<"#---"<<#x<<"=="<<x<<endl
#define FC ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define FIN freopen("in.txt","r",stdin)
#define FOUT freopen("out.txt","w",stdout)

using namespace std;

const long double PI=acos(-1.0);  
const long double eps=1e-6;
const long long maxw=1e17+10;

typedef long long ll;
typedef pair<int,int> pii;
/*head------[@cordercorder]*/

ll t;
char A[25],B[25];
ll tmp[25],cnt;
ll digit[20];//digit[i]=0代表数字i未出现，digit[i]=1代表数字i出现了奇数次，digit[i]=2代表数字i出现了偶数次 
ll dp[22][59999];

void bits(char *s){
	cnt=strlen(s+1);
	reverse(s+1,s+1+cnt);
	for(ll i=1;i<=cnt;i++){
		tmp[i]=(ll)(s[i]-'0');
	}
}

void cal_f(ll s){
	for(ll i=0;i<10;i++){
		digit[i]=s%3;
		s/=3;
	}
}

ll cal_b(ll s){
	ll ret=1,ans=0;
	for(ll i=0;i<10;i++){
		ans+=(digit[i]*ret);
		ret*=3;
	}
	return ans;
}

ll handle(ll s,ll num){
	cal_f(s);
	if(digit[num]==0LL){
		digit[num]=1LL;
	}
	else if(digit[num]==1LL){
		digit[num]=2LL;
	}
	else{
		digit[num]=1LL;
	}
	return cal_b(s);
}

ll check(ll sta){
	cal_f(sta);
	for(ll i=0;i<10;i++){
		if(i&1){
			if(digit[i]==1)
				return 0;
		}
		else{
			if(digit[i]==2)
				return 0;
		}
	}
	return 1LL;
}

ll dfs(ll pos,ll sta,bool f){
	if(pos==0){
		return check(sta);
	}
	if(!f&&dp[pos][sta]!=-1){
		return dp[pos][sta];
	}
	ll num;
	if(f){
		num=tmp[pos];
	}
	else{
		num=9;
	}
	ll ans=0;
	for(ll i=0;i<=num;i++){
		ans+=(ll)dfs(pos-1,(sta==0&&i==0)?0:handle(sta,i),f&&i==num);
	}
	if(!f){
		dp[pos][sta]=ans;
	}
	return ans;
}

void solve(){
	bits(B);
	ll res1=dfs(cnt,0,true);
	bits(A);
	ll res2=dfs(cnt,0,true);
	ll ans=res1-res2;
	vector<ll> num(11,0);
	for(ll i=1;i<=cnt;i++){
		num[tmp[i]]++;
	}
	bool f=true;
	for(ll i=0;i<10;i++){
		if(num[i]!=0){
			if(i&1){
				if(num[i]%2==1){
					f=false;
					break;
				}
			}
			else{
				if(num[i]%2==0){
					f=false;
					break;
				}
			}
		}
	}
	ans+=(ll)f;
	printf("%lld\n",ans);
}

int main(void){
	scanf("%lld",&t);
	memset(dp,-1,sizeof(dp));
	while(t--){
		scanf("%s %s",A+1,B+1);
		solve();
	}
	return 0;
}
