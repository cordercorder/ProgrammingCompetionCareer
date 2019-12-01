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

const int maxsize=1e6+10; 

bool isv[30];
int tmp[maxsize];

int n;
string str;


void handle(const string &str){
	if(isv[str[str.length()-1]-'a']==1){
		isv[str[0]-'a']=1;
	}
	else{
		isv[str[0]-'a']=0;
	}
}

int main(void){
	int i,sum=0,cnt;
	while(scanf("%d",&n)!=EOF){
		if(n==0)
			break;
		getchar();
		cnt=0;
		memset(isv,0,sizeof(isv));
		isv['a'-'a']=1;
		for(i=0;i<n;i++){
			getline(cin,str);
			handle(str); 
		}
		sum++;
		printf("Program #%d\n",sum);
		for(i=0;i<26;i++){
			if(isv[i])
				tmp[cnt++]=i;
		}
		if(cnt==0){
			printf("none\n\n");
			continue;
		}
		printf("%c ",tmp[0]+'a'); 
		for(i=1;i<cnt;i++){
			printf("%c ",tmp[i]+'a');
		}
		printf("\n\n");
	}
	return 0;
}
