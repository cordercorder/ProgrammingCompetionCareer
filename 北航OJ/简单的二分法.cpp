# include<iostream>
# include<algorithm>
# include<cstring>
# include<cstdlib>
# include<string>
# include<cmath>
# include<queue>
# include<stack>
# include<set>
# include<vector>
# include<cstdio>

using namespace std;

const int maxsize=25e4+10;

int a[maxsize];
int n,m;

void solve(){
	int i,e,mid,l=0,r=n-1;
	scanf("%d",&e);
	while(l<r){
		mid=(l+r)>>1;
		if(e>a[mid]){
			l=mid+1;
		}
		else{
			r=mid;
		}
	}
	if(a[l]==e){
		printf("%d\n",l+1);
	}
	else{
		printf("error\n");
	}
}

int main(void){
	int i;
	while(scanf("%d %d",&n,&m)!=EOF){
		for(i=0;i<n;i++)
			scanf("%d",&a[i]);
		while(m--){
			solve();
		}
	}
	return 0;
}
