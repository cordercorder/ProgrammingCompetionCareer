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
# include<map>

# define deb(x) printf("# x=%d\n",x)
# define deb_d(x) printf("# x=%lf\n",x)

typedef long long ll;

using namespace std;

const int maxsize=1e2+10;

ll n,m;

ll a[55],b[55],c1[3005],c2[3005];

int main(void){
	int i,j,k,cnt1,cnt2;
	while(scanf("%lld %lld",&n,&m)!=EOF){
		cnt1=0;
		cnt2=0;
		for(i=0;i<n;i++){
			scanf("%lld",&a[i]);
		}
		for(i=0;i<m;i++){
			scanf("%lld",&b[i]);
		}
		sort(a,a+n);
		for(i=1;i<n;i++){
			for(j=0;j<m;j++)
				c1[cnt1++]=a[i]*b[j];
		}
		for(i=0;i<n-1;i++){
			for(j=0;j<m;j++)
				c2[cnt2++]=a[i]*b[j];
		}
		sort(c1,c1+cnt1);
		sort(c2,c2+cnt2);
		if(c1[cnt1-1]<c2[cnt2-1]){
			printf("%lld\n",c1[cnt1-1]);
		}
		else{
			printf("%lld\n",c2[cnt2-1]);
		}
	}
	return 0;
}
