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

const int maxsize=2e3+10;

int n;
int a[maxsize],b[maxsize],tmp[maxsize];
int ans;

int solve(){
	int i,j,cnt,l,r;
	tmp[0]=1;
	for(i=0;i<n;i++){
		l=0;
		r=0;
		for(j=0;j<n;j++){
			if(a[j]==2){
				l=j;
			}
			while(j<n&&a[j]==2){
				j++;
			}
			if(r-l>cnt){
				
				
				
			}
		}
	}
	
	
	
	
	
	
	ans=0;
	for(i=0;i<n;i++){
		l=i;
		cnt=1;
		while(l<n-1&&tmp[l+1]>tmp[l]){
			l++;
			cnt++;
		}
		if(l<n-1){
			l++;
			cnt++;
		}
		while(l<n-1&&tmp[l+1]>tmp[l]){
			l++;
			cnt++;
		}
		ans=max(ans,cnt);
	}
	printf("%d\n",ans);
}

int main(void){
	int i,j;
	while(scanf("%d",&n)!=EOF){
		j=0;
		for(i=0;i<n;i++){
			scanf("%d",&a[i]);
		}
		for(i=n-1;i>=0;i--){
			b[j]=a[i];
		}
		solve();
	}
	return 0;
}
