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

# define deb(x) printf("# x=%d\n",x)
# define deb_d(x) printf("# x=%lf\n",x)

typedef long long ll;

using namespace std;

const int maxsize=1e5+10;

string ss[maxsize],str;
ll n;

ll handle(string &s){
	ll tmp=0,sum=0,i;
	for(i=0;i<s.length();i++){
		if(s[i]=='s'){
			sum++;
		}
		else{
			tmp=tmp+sum;
		}
	}
	return tmp;
}

bool cmp(const string &a,const string &b){
	string s1=a+b,s2=b+a;
	if(handle(s1)>handle(s2))
		return 1;
	return 0;
}

void solve(){
	ll i;
	ll sum=0,ans=0;
	sort(ss,ss+n,cmp);
	for(i=0;i<n;i++)
		str=str+ss[i];
	//cout<<"str="<<str<<endl;
	printf("%lld\n",handle(str));
	str.clear();
}

int main(void){
	ll i,j;
	while(scanf("%lld",&n)!=EOF){
		for(i=0;i<n;i++){
			cin>>ss[i];
		}
		solve();
	}
	return 0;
}
