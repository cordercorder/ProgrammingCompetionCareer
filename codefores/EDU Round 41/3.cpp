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

const int maxsize=1e2+10;

char a[4][maxsize][maxsize];
char tmp[4][maxsize][maxsize]; 
int n;

char s[2][maxsize];
bool isv[4];
int ans;

void handle1(){
	int cnt=0;
	for(int i=0;i<n;i++){
		if(cnt&1){
			s[0][i]='0';
			s[1][i]='1';
		}
		else{
			s[0][i]='1';
			s[1][i]='0';
		}
		cnt++;
	}
	s[0][n]='\0';
	s[1][n]='\0';
}

void handle2(int x,int y){
	int sum=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(tmp[x][i][j]!=s[i%2][j]){
				sum++;
				tmp[x][i][j]=s[i%2][j];
			}
			if(tmp[y][i][j]!=s[i%2][j]){
				sum++;
				tmp[y][i][j]=s[i%2][j];
			}
		}
	}
	int res[2],cnt=0; 
	for(int i=0;i<4;i++){
		if(!isv[i]){
			res[cnt++]=i;
		}
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(tmp[res[0]][i][j]!=s[(i+1)%2][j]){
				sum++;
				tmp[res[0]][i][j]=s[(i+1)%2][j];
			}
			if(tmp[res[1]][i][j]!=s[(i+1)%2][j]){
				sum++;
				tmp[res[1]][i][j]=s[(i+1)%2][j];
			}
		}
	}
	ans=min(ans,sum);
}

void solve(){
	ans=4*1e4;
	for(int i=0;i<4;i++){
		for(int j=i+1;j<4;j++){
			memcpy(tmp,a,sizeof(a));
			memset(isv,0,sizeof(isv));
			isv[i]=1;
			isv[j]=1;
			handle2(i,j);
		}
	}
	printf("%d\n",ans);
}

int main(void){
	while(scanf("%d",&n)!=EOF){
		for(int i=0;i<4;i++){
			for(int j=0;j<n;j++){
				scanf("%s",a[i][j]);
			}
		}
		handle1();
		solve();
	}
	return 0;
}
