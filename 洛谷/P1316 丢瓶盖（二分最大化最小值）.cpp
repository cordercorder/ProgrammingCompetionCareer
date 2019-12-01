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
# define ccout(x) printf("%d\n",x)

typedef long long ll;

using namespace std;

const int maxsize=1e5+10;

ll n,m;
ll a[maxsize];

bool check(const ll &x){//距离最大为x 
	ll sum=1,s=a[0];
	for(int i=1;i<n;i++){
		if(a[i]-s>=x){
			s=a[i];
			sum++;
			if(sum>=m)
				return 1;
		}
	}
	return sum>=m;
}

int main(void){
	ll l,r,mid;
	while(scanf("%lld %lld",&n,&m)!=EOF){
		for(int i=0;i<n;i++)
			scanf("%lld",&a[i]);
		sort(a,a+n);
		l=0;
		r=a[n-1]-a[0]+1;
		while(l<r){
			mid=(l+r)>>1;
			//deb(mid);	
			//cout<<"l= "<<l<<endl;
			//cout<<"r= "<<r<<endl;
			if(check(mid)){//可行则说明距离小了 
				l=mid+1; 
			}
			else{
				r=mid;
			}
		}
		printf("%lld\n",l-1);
	}
	return 0;
}
