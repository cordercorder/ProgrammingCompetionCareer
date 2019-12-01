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

const int maxsize=1e3+10;
int n;

vector<int> child[maxsize];

void solve(){
	int i,tmp,sum;
	for(i=1;i<=n;i++){
		sum=0;
		if(child[i].size()>0){
			for(int j=0;j<child[i].size();j++){
				tmp=child[i][j];
				if(child[tmp].size()>0){//不是叶子节点
					continue;
				}
				sum++;//计算叶子节点 
			}
			//printf("###i=%d   sum=%d\n",i,sum);
			if(sum<3){
				printf("No\n");
				return ;
			}
		}
	}
	printf("Yes\n");
}

int main(void){
	int i,x;
	while(scanf("%d",&n)!=EOF){
		for(i=2;i<=n;i++){
			scanf("%d",&x);
			child[x].push_back(i);//i是x的子节点 
		}
		solve();
		for(i=1;i<=n;i++)
			child[i].clear();
	}
	return 0;
}
