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
# include<limits.h>
# include<ctime>

# define deb(x) cout<<"#---"<<#x<<"=="<<x<<endl

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

char s[20][20];
char str[20][20][20][20];
int n,m,a,b;

int main(void){
	while(scanf("%d %d %d %d",&n,&m,&a,&b)!=EOF){
		for(int i=1;i<=n;i++){
			scanf("%s",s[i]+1);
		}
		for(int i=1;i<=n;i++){
			for(int u=1;u<=a;u++){
				for(int j=1;j<=m;j++){
					for(int k=1;k<=b;k++){
						printf("%c",s[i][j]);
					}
				}
				printf("\n");		
			}		
		}
	}
	return 0;
}
