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

const int maxsize=2e5+10;

struct node{
	int x;
	int y;
};

node pos[maxsize];

int n,len;
int a[maxsize];
int tmp[maxsize],cnt;

char str[maxsize];

bool solve(){
	int i,k,j,x,y;
	len=0;
	if(cnt>0){
		x=min(tmp[0],a[tmp[0]]);
		y=max(tmp[0],a[tmp[0]])-1;
		for(k=x,j=y;k<=j;k++,j--){
			if(str[k-1]=='1'&&str[j-1]=='1'){
				continue;
			}
			else
				return 0;
		}
	}
	for(i=1;i<cnt;i++){
		if(min(tmp[i],a[tmp[i]])>=x&&max(tmp[i],a[tmp[i]])-1<=y)
			continue;
		for(k=min(tmp[i],a[tmp[i]]),j=max(tmp[i],a[tmp[i]])-1;k<=j;k++,j--){
			if(str[k-1]=='1'&&str[j-1]=='1'){
				continue;
			}
			else
				return 0;
		}
		x=min(x,min(tmp[i],a[tmp[i]]));
		y=max(y,max(tmp[i],a[tmp[i]])-1);
	}
	return 1;
}

int main(void){
	int i;
	while(scanf("%d",&n)!=EOF){
		cnt=0;
		for(i=1;i<=n;i++){
			scanf("%d",&a[i]);
			if(a[i]!=i){
				tmp[cnt++]=i;
			}
		}
		getchar();
		gets(str);
		//printf("str=%s",str);
		if(solve()){
			printf("YES\n");
		}
		else{
			printf("NO\n");
		}
	}
	return 0;
}
