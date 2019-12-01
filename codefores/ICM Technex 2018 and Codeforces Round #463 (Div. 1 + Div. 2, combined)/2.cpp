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

const int maxsize=1e6+10;

int Q;
int l,r,k;
int a[maxsize];
vector<int> p[10];
vector<int>::iterator it1,it2;

int fun(int n){
	int m=1,ans=1;
	while(m<=n){
		if((n/m)%10==0){
			m=m*10;
			continue;
		}
		ans=ans*((n/m)%10);
		m=m*10;
	}
	return ans;
}

int gun(int n){
	if(n<10){
		return n;
	}
	else 
		return gun(fun(n));
}

int Find(const int &xx,const int &k){
	int l=0,r=p[k].size()-1,mid;
	while(l<r){
		mid=(l+r)/2;
		if(xx<=p[k][mid]){
			r=mid;
		}
		else{
			l=mid+1;
		}
	}
	return l;
}

int main(void){
	int i,cnt,tmp;
	for(i=1;i<=1000000;i++){
		tmp=gun(i);
		p[tmp].push_back(i);
	}
	scanf("%d",&Q);
	while(Q--){
		cnt=0;
		scanf("%d %d %d",&l,&r,&k);
		int x=Find(l,k);
		int y=Find(r,k);
		if(p[k][y]<r){//r超出范围的情况 
			if(p[k][x]<l)
				printf("0\n");
			else
				printf("%d\n",y-x+1);
		}
		else if(p[k][y]==r){
			printf("%d\n",y-x+1);
		}
		else{
			printf("%d\n",y-x);
		}
	}
	return 0;
}
