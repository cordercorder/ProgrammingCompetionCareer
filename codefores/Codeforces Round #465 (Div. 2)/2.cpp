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

const int maxsize=1e5+10;

struct node{
	int x;
	int y;
	int position;
	node():position(0){			};
	void Set(int a,int b);
};

void node::Set(int a,int b){
	x=a;
	y=b;
}

char str[maxsize];
int n;
node now;

void solve(){
	int i;
	now.Set(0,0);
	int ans=0;
	if(str[0]=='U'){
		now.y++;
		now.position=1;
	}
	else{
		now.x++;
		now.position=-1;
	}
	for(i=1;i<n;i++){
		if(str[i]=='U'){
			now.y++;
			if(now.y>now.x&&now.position==-1){
				now.position=1;
				ans++;
			}
		}
		else if(str[i]=='R'){
			now.x++;
			if(now.x>now.y&&now.position==1){
				now.position=-1;
				ans++;
			}
		}
	}
	printf("%d\n",ans);
}

int main(void){
	int i;
	while(scanf("%d",&n)!=EOF){
		scanf("%s",str);
		solve();
	}
	return 0;
}
