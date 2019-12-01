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

# define deb(x) printf("# x=%d\n",x)

typedef long long ll;

using namespace std;

const int maxsize=2e5+10;

char str[maxsize];
int a[maxsize],n;

void handle(){
	int i,len=n-1;
	int l=1,r=0;
	for(i=1;i<=len;i++){
		if(str[i]=='1'){
			r=i+1;
		}
		else{
			if(l<r)
				sort(a+l,a+r+1);//l为起点,r为终点 
			l=i+1;
			r=i;
		}
	}
	if(l<r)
		sort(a+l,a+r+1);//补上结尾 
}

bool check(){
	int i;
	for(i=1;i<=n;i++)
		if(a[i]!=i)
			return 0;
	return 1;
}

int main(void){
	int i;
	while(scanf("%d",&n)!=EOF){
		for(i=1;i<=n;i++){
			scanf("%d",&a[i]);
		}
		scanf("%s",str+1);
		handle();
		if(check()){
			printf("YES\n");
		}
		else{
			printf("NO\n");
		}
		//for(i=1;i<=n;i++){
		//	deb(a[i]);
		//}
	}
	return 0;
}
