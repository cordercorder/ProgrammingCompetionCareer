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

const int maxsize=1e4+10;

struct node{
	int s;
	int e;
};

int n,m; 
node p[maxsize];

bool cmp(const node &a,const node &b){
	return a.e<b.e;
}


int solve(int x,int ti){//ti为结束时间 
	
	
	
	int res;
	if(ti<=p[x].s){
		res=solve(x+1,p[x].e)+p[x].e+1-p[x].s;//计算工作的多长时间 
	}
	else{
		res=
		
	}
	
	
}

int main(void){
	int a,b;
	while(scanf("%d %d",&m,&n)!=EOF){
		for(int i=0;i<n;i++){
			scanf("%d %d",&a,&b);
			p[i].s=a;
			p[i].e=a+b-1;
		}
		
		
		
		
		
		
	}
	
	
	return 0;
}
