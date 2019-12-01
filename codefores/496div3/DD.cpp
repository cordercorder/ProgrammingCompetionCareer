#include<iostream>
#include<algorithm>
#include<cstring>
#include<string>
#include<cmath>
#include<queue>
#include<stack>
#include<set>
#include<vector>
#include<cstdio>
#include<cstdlib>
#include<map>
#include<deque>
#include<limits.h>
#include<ctime>

#define deb(x) cout<<"#---"<<#x<<"=="<<x<<endl

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

const int maxn=2e5+10;

char s[2][maxn];
int len,cnt;
int num[15];
int ans;
bool isv[maxn];
int a[maxn];

void handle(int st,int ed){
	for(int i=st;i<ed;i++){
		s[0][i]='#';
	}
}

void solve(){
	memset(isv,0,sizeof(isv));
	cnt=0;
	ans=0;
	for(int i=0;i<len;i++){
		a[i]=(int)(s[0][i]-'0')%3;
	}
	ans=0;
	int sum=0;
	for(int i=0;i<len;i++){
		sum+=a[i];
		if(sum%3==0){
			ans++;
			sum=0;
		}
	}
	printf("%d\n",ans);
}

int main(void){
	while(cin>>s[0]){
		len=strlen(s[0]);
		solve();
	}
	return 0;
}
