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

# define ll long long

using namespace std;

const int maxsize=25;

const int maxsize1=1e6+10;

int n,m,c;

int de[maxsize];

int x[maxsize1];

bool isv[maxsize],flag;

int main(void){
	int i,ans,tmp;
	int cnt=0;
	while(scanf("%d %d %d",&n,&m,&c)!=EOF){
		if(n==0&&m==0&&c==0)
			break;
		for(i=1;i<=n;i++){
			scanf("%d",&de[i]);
		}
		for(i=0;i<m;i++){
			scanf("%d",&x[i]);
		}
		ans=-1;
		tmp=0;
		cnt++;
		flag=0;
		memset(isv,0,sizeof(isv));
		for(i=0;i<m;i++){
			if(!isv[x[i]]){//假如刚开始是关闭的 
				isv[x[i]]=1;
				tmp=tmp+de[x[i]];//总功率增加 
				if(tmp>ans)
					ans=tmp;
			}
			else{//假如开始是打开的 
				isv[x[i]]=0;
				tmp=tmp-de[x[i]];
			}
			if(tmp>c){
				flag=1;
				break;
			}
		}
		if(flag){
			printf("Sequence %d\n",cnt);
			printf("Fuse was blown.\n\n");
			continue;
		}
		printf("Sequence %d\n",cnt);
		printf("Maximal power consumption was %d amperes.\n\n",ans);
	}
	return 0;
}
