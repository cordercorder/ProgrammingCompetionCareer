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

using namespace std;

int n;
int a,b,c; 


int main(void){
	int i,temp,ans;
	while(scanf("%d",&n)!=EOF){
		while(n--){
			scanf("%d %d %d",&a,&b,&c);
			if(b-c<=0){
				printf("fail\n");
				continue;
			}
			temp=a-c;
			if(temp%(b-c)==0){
				ans=temp/(b-c);
			}
			else{
				ans=temp/(b-c)+1;
			}
			printf("%d\n",ans);				}
		}
	return 0;
}
