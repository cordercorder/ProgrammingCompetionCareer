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

const int maxsize=5e3+10;

string s; 
int num[30][30][maxsize];

int solve(int x){
	int sum,Max=0;
	for(int i=0;i<s.length();i++){
		sum=0;
		for(int j=0;j<26;j++){
			if(num[x][j][i]==1){
				sum++;
				Max=max(Max,sum);
			}
		}
	}
	return Max;
}

int main(void){
	int cnt;
	double ans;
	cin>>s;
	memset(num,0,sizeof(num));
	for(int i=0;i<s.length();i++){
		cnt=0;
		for(int j=i;cnt<s.length();j++,cnt++){
			num[s[i]-'a'][s[j%s.length()]-'a'][cnt]++;	
		}
	}
	ans=0;
	for(int i=0;i<26;i++){
		ans+=solve(i);
	}
	ans=ans/s.length();
	printf("%.20lf\n",ans);
	return 0;
}
