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

string str;
int n;
stack<char> s;
char tmp[105];

bool check(const char &ch){
	if(ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u'||ch=='y')
		return 1;
	return 0;
}

int main(void){
	int i,cnt;
	while(scanf("%d",&n)!=EOF){
		cin>>str;
		cnt=0;
		s.push(str[0]);
		for(i=1;i<n;i++){
			if(check(str[i])&&check(s.top()))
				continue;
			s.push(str[i]);
		}
		while(!s.empty()){
			tmp[cnt++]=s.top();
			s.pop();
		}
		for(i=cnt-1;i>=0;i--)
			printf("%c",tmp[i]);
		printf("\n");
	} 
	return 0;
}
