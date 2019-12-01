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

const int maxsize=1e3+10;

struct node{
	int l;
	int r;
};

bool cmp(const node &a,const node &b){
	return a.l<b.l;
}

int t,n;
node a[maxsize];
queue<node> q;

int main(void){
	int i,time;
	while(scanf("%d",&t)!=EOF){
		while(t--){
			scanf("%d",&n);
			for(i=0;i<n;i++){
				scanf("%d %d",&a[i].l,&a[i].r);
			}
			stable_sort(a,a+n,cmp);
			for(i=0;i<n;i++)
				q.push(a[i]);
			time=q.front().l;
			while(!q.empty()){
				if(q.front().r<time){
					q.pop();
					printf("0 ");
				}
				else{
					printf("%d ",time);
					time++;
					q.pop();
				}
				time=(time>q.front().l?time:q.front().l);
			}
			printf("\n");
		}
	}
	return 0;
}
