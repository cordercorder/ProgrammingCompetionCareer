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

# define ll long long

using namespace std;

priority_queue<int,vector<int>,greater<int> > q;//Ð¡¶¥¶Ñ 


int n;
int ans,sum;

int main(void){
	int i,x,a1,a2;
	while(scanf("%d",&n)!=EOF){
		for(i=0;i<n;i++){
			scanf("%d",&x);
			q.push(x);
		}
		ans=0;
		while(!q.empty()){
			a1=q.top();
			q.pop();
			a2=q.top();
			q.pop();
			ans=ans+a1+a2;
			q.push(a1+a2);
			if(q.size()==1){
				break;
			}
		}
		q.pop();
		printf("%d\n",ans);	
	}
	return 0;
}
