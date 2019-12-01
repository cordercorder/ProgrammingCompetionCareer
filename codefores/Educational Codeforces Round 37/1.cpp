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

const int maxsize=205;

int t;
int n,k;
int x[maxsize],gap;

void solve(){
	int i,j,ans=-100;
	for(j=1;x[0]-(j-1)>1;j++);
	if(j>ans){
		ans=j;
	}
	for(j=1;x[k-1]+(j-1)<n;j++);
	if(j>ans){
		ans=j;
	}
	if((gap+1)%2==0){
		ans=max(ans,(gap+1)/2);
	}
	else{
		ans=max(ans,(gap+1)/2+1);
	}
	printf("%d\n",ans);
}

int main(void){
	int i;
	while(scanf("%d",&t)!=EOF){
		while(t--){
			gap=0;
			scanf("%d %d",&n,&k);
			for(i=0;i<k;i++){
				scanf("%d",&x[i]);
				if(i>0&&x[i]-x[i-1]>gap){
					gap=x[i]-x[i-1];
				}
			}
			solve();
		}
	}
	return 0;
}
