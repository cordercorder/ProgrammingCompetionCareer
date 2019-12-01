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

const int maxsize=10800100;

int a[maxsize+5];

bool check(const int &x,int &sum){
	int m=1;
	sum=0;
	while(m<=x){
		sum=sum+(x/m)%10;
		if(sum>10)
			return 0;
		m=m*10;
	}
	return 1;
}

int main(void){
	int i,j,cnt=0,k,sum;
	for(i=0;i<=108001;i++){
		if(check(i,sum)){
			for(j=(10-sum==10?9:10-sum);j>=0;j--){
				if(sum==0&&j==0)
					continue;
				a[cnt++]=i*100+(10-sum-j)*10+j;
				//printf("i=%d  j=%d\n",i,j);
				//printf("%d\n",a[cnt-1]);
				//printf("ok\n");
			}
		}
	}
	scanf("%d",&k);
	printf("%d\n",a[k-1]);
	return 0;
}
