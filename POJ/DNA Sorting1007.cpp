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


int n,m;
string str[maxsize];

int handle(const string &s){
	int ans=0;
	for(int i=0;i<s.length();i++){
		for(int j=i+1;j<s.length();j++){
			if(s[i]>s[j])
				ans++;
		}
	}
	return ans;
}

bool cmp(const string &a,const string &b){
	if(handle(a)<handle(b))
		return 1;
	return 0;
}

int main(void){
	while(scanf("%d %d",&n,&m)!=EOF){
		for(int i=0;i<m;i++){
			cin>>str[i];
		}
		stable_sort(str,str+m,cmp);
		for(int i=0;i<m;i++){
			cout<<str[i]<<endl;
		}
	}
	return 0;
}
