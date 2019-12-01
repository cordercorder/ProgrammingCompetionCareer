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

int n;
char s[100];
int len;
vector<int> p;
int num[100],cnt;

void handle(){
	for(int i=1;i*i<=n;i++){
		p.push_back(i*i);
	}
}

bool check(int x,int &ans){
	ll m=1;
	int res;
	cnt=0;
	while(m<=x){
		res=(x/m)%10;
		//cout<<"res=="<<res<<endl; 
		num[cnt++]=res;
		m=m*10;
	}
	reverse(num,num+cnt);
	int i=0,j=0;
	while(i<cnt&&j<len){
		if(num[i]==(s[j]-'0')){
			i++;
			j++;
		}
		else{
			j++;
		}
	}
	ans=len-cnt;
	return i==cnt;
}

void solve(){
	int ans;
	for(int i=p.size()-1;i>=0;i--){
		if(check(p[i],ans)){
			cout<<ans<<endl;
			return ;
		}
	}
	puts("-1");
}

int main(void){
	
	while(scanf("%s",s)!=EOF){
		n=atoi(s);
		len=strlen(s);
		handle();
		solve();
	}
	return 0;
}
