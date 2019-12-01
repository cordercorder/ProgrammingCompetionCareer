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

int n;
int a[maxsize];
int Start,End;


char str[maxsize];

bool solve(){
	int i;
	for(i=Start;i<End;i++){
		if(str[i-1]=='1'){
			continue;
		}
		else
			return 0;
	}
	return 1;
}

int main(void){
	int i;
	bool flag;
	while(scanf("%d",&n)!=EOF){
		flag=1;
		Start=-1;
		End=-1; 
		for(i=1;i<=n;i++){
			scanf("%d",&a[i]);
			if(a[i]!=i&&flag==1){
				Start=i;//记录最开始需要交换的 
				flag=0;
			}
			if(a[i]!=i&&i>End){
				End=i;
			}
		}
		//printf("start=%d  end=%d\n",start,end);
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
