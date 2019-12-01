# include<iostream>
# include<algorithm>
# include<vector>
# include<cstring>

# define ll long long

using namespace std;

const int maxsize1=65;
const int maxsize2=32005;

struct node{
	ll v;
	ll v_p;
};

vector<node> p[maxsize1];
ll dp[maxsize1][maxsize2];

ll n,m;

ll Max(ll a,ll b){
	if(a>b)
		return a;
	return b; 
}

void solve(){
	ll i,j;
	memset(dp,0,sizeof(dp));
	for(i=1;i<=m;i++){
		for(j=1;j<=n;j++){
			if(!p[i].empty()){
				if(j>=p[i][0].v){
					dp[i][j]=Max(dp[i-1][j],dp[i-1][j-p[i][0].v]+p[i][0].v_p);
				if(p[i].size()>1&&j>=p[i][0].v+p[i][1].v)
					dp[i][j]=Max(dp[i][j],dp[i-1][j-p[i][0].v-p[i][1].v]+p[i][0].v_p+p[i][1].v_p);
				if(p[i].size()>2&&j>=p[i][0].v+p[i][1].v+p[i][2].v)	
					dp[i][j]=Max(dp[i][j],dp[i-1][j-p[i][0].v-p[i][1].v-p[i][2].v]+p[i][0].v_p+p[i][1].v_p+p[i][2].v_p);
				}
				else{
					dp[i][j]=dp[i-1][j];
				}
			}
			else{
				dp[i][j]=dp[i-1][j];
			}
		}		
	}
	printf("%lld\n",dp[m][n]);
}

int main(void){
	ll i;
	ll v,p1,q;
	node temp;
	scanf("%lld %lld",&n,&m);
	for(i=1;i<=m;i++){
		scanf("%lld %lld %lld",&v,&p1,&q);
		temp.v=v;
		temp.v_p=v*p1;
		if(!q){
			p[i].push_back(temp);
		}
		else{
			p[q].push_back(temp);
		}
	}
	solve();
	return 0;
}
