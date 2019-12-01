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

using namespace std;

const int maxsize=1e4+5;

int n,m;
int a[maxsize];

int main(void){
	int i;
	scanf("%d %d",&n,&m);
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	for(i=0;i<m;i++){
		next_permutation(a,a+n);
	}
	printf("%d",a[0]);
	for(i=1;i<n;i++){
		printf(" %d",a[i]);
	}
	return 0;
}
