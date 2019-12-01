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

typedef long long ll;

using namespace std;

const int maxsize=2e3+10;

ll n,m,k,ans;

char str[maxsize][maxsize];

void solve1(){
	ll i,j;
	ll sum;
	for(i=0;i<n;i++){
		sum=0;
		for(j=0;j<m;j++){
			while(j<m&&str[i][j]=='.'){
				j++;
				sum++;
			}
			if(sum>=k){
				ans+=sum-k+1;
			}
			sum=0;
		}
	}
}

void solve2(){
	ll i,j;
	ll sum;
	for(i=0;i<m;i++){
		sum=0;
		for(j=0;j<n;j++){
			while(j<n&&str[j][i]=='.'){
				j++;
				sum++;
			}
			if(sum>=k){
				ans+=sum-k+1;
			}
			sum=0;
		}
	}
}

int main(void){
	ll i;
	scanf("%lld %lld %lld",&n,&m,&k);
	getchar();
	for(i=0;i<n;i++){
		gets(str[i]);
	}
	ans=0;
	if(k==1){
		solve1();
		printf("%lld\n",ans);
		return 0;
	}
	solve1();
	//printf("ans=%lld\n",ans);
	solve2();
	printf("%lld\n",ans);
	return 0;
}
