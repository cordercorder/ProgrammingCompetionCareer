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

# define deb(x) printf("# x=%d\n",x)
# define deb_d(x) printf("# x=%lf\n",x)
# define ccout(x) printf("%d\n",x)

typedef long long ll;

using namespace std;

int a,b;
int n;
string str;

void solve(){
	int aa=a,bb=b;
	if(str[0]=='.'){
		if(aa>bb&&aa>0){
			aa--;
			str[0]='1';
		}
		else{
			if(bb>0){
				bb--;
				str[0]='2';
			}
		}
	}
	for(int i=1;i<n;i++){
		if(str[i]=='.'){
			if(str[i-1]=='1'){
				if(bb==0)
					continue;
				bb--;
				str[i]='2';
			}
			else if(str[i-1]=='2'){
				if(aa==0)
					continue;
				aa--;
				str[i]='1';
			}
			else{
				if(aa>bb){
					aa--;
					str[i]='1';
				}
				else{
					if(bb==0)
						continue;
					bb--;
					str[i]='2';
				}
			}
		}
	}
	//cout<<"aa=="<<aa<<endl;
	//cout<<"bb=="<<bb<<endl;
	//cout<<"str=="<<str<<endl;
	int ans=0;
	for(int i=0;i<str.length();i++){
		if(str[i]=='1'||str[i]=='2')
			ans++;
	}
	cout<<ans<<endl; 
}

int main(void){
	ios::sync_with_stdio(false);
	cin.tie(0);
	while(cin>>n>>a>>b){
		cin>>str;
		solve();
	}
	return 0;
}
