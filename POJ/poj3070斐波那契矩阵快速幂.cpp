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

const int maxn=1e5+10;
const int mod=10000;

struct Matrix{
	int mat[2][2];
};
int n;

Matrix mul_M(Matrix a,Matrix b){
	Matrix ans;
	for(int i=0;i<2;i++){
		for(int j=0;j<2;j++){
			ans.mat[i][j]=0;
			for(int k=0;k<2;k++){
				ans.mat[i][j]=(ans.mat[i][j]+a.mat[i][k]*b.mat[k][j])%mod;
			}
		}
	}
	return ans;
}

Matrix q_mod(Matrix a,int n){
	Matrix ans;
	memset(ans.mat,0,sizeof(ans.mat));
	for(int i=0;i<2;i++){
		ans.mat[i][i]=1;
	}
	while(n){
		if(n&1){
			ans=mul_M(ans,a);
		}
		a=mul_M(a,a);
		n>>=1;
	}
	return ans;
}

void solve(){
	Matrix ret;
	ret.mat[0][0]=1;
	ret.mat[0][1]=1;
	ret.mat[1][0]=1;
	ret.mat[1][1]=0;
	ret=q_mod(ret,n-1);
	printf("%d\n",ret.mat[0][0]);
}

int main(void){
	while(scanf("%d",&n)!=EOF){
		if(n==-1)
			break;
		if(n==0){
			puts("0");
			continue;
		}
		solve();
	}
	return 0;
}
