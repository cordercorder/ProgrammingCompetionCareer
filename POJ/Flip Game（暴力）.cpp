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
# include<deque>

# define deb(x) printf("# x=%d\n",x)
# define deb_d(x) printf("# x=%lf\n",x)
# define ccout(x) printf("%d\n",x)

typedef long long ll;

using namespace std;

char str[10][10];
int sum[2];
int ans;
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

bool check(){
	sum[1]=0;
	sum[0]=0;
	for(int i=0;i<4;i++)
		for(int j=0;j<4;j++){
			if(str[i][j]=='b')
				sum[0]++;
			else
				sum[1]++;
		}
	if(sum[0]==16||sum[1]==16)
		return 1;
	return 0;
}

void handle(int x,int y){
	if(x<0||x>=4||y<0||y>=4)
		return ;
	if(str[x][y]=='b')
		str[x][y]='w';
	else
		str[x][y]='b';
	if(x+1<4){
		if(str[x+1][y]=='b')
			str[x+1][y]='w';
		else
			str[x+1][y]='b';
	}
	if(x-1>=0){
		if(str[x-1][y]=='b')
			str[x-1][y]='w';
		else
			str[x-1][y]='b';
	}
	if(y+1<4){
		if(str[x][y+1]=='b')
			str[x][y+1]='w';
		else
			str[x][y+1]='b';
	}
	if(y-1>=0){
		if(str[x][y-1]=='b')
			str[x][y-1]='w';
		else
			str[x][y-1]='b';
	}
}

void solve(int x,int y,int step){
	//cout<<"x=="<<x<<"  y=="<<y<<endl;
	if(check()){
		ans=min(ans,step);
		return ;
	}
	if(x<0||y<0||x>=4||y>=4)
		return ;
	if(y<3){
		solve(x,y+1,step);
		handle(x,y);
		solve(x,y+1,step+1);
		handle(x,y);
	}
	else{
		solve(x+1,0,step);
		handle(x,y);
		solve(x+1,0,step+1);
		handle(x,y);
	}
}

int main(void){
	for(int i=0;i<4;i++)
		scanf("%s",str[i]);
	if(check()){
		puts("0");
		return 0;
	}
	ans=1e5+10;
	solve(0,0,0);
	if(ans==1e5+10){
		puts("Impossible");
	}
	else{
		printf("%d\n",ans);
	}
	return 0;
}
