# include<iostream>
# include<vector>
# include<algorithm>
# include<cstring>

using namespace std;

const int maxsize=1e5+10;

int dp1[maxsize],dp2[maxsize];

vector<int> p;

void solve(){
	int i,j;
	int max1=0,max2=0;
	for(i=0;i<p.size();i++){
		dp1[i]=1;//最长不下降子序列的长度 
		dp2[i]=1;//最长上升子序列的长度
		for(j=0;j<i;j++){
			if(p[i]<=p[j]&&dp1[i]<dp1[j]+1){
				dp1[i]=dp1[j]+1;
				max1=max(max1,dp1[i]);
			}
			if(p[i]>p[j]&&dp2[i]<dp2[j]+1){
				dp2[i]=dp2[j]+1;
				max2=max(max2,dp2[i]);
			}
		}
	}
	printf("%d\n%d\n",max1,max2);
}

int main(void){
	int n;
	while(scanf("%d",&n)!=EOF){
		p.push_back(n);
	}
	solve();
	return 0;
}
