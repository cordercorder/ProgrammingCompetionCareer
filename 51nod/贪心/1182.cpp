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
#include<bitset>
#include<ctime>

#define deb(x) cout<<"#---"<<#x<<"=="<<x<<endl

using namespace std;

const long double PI=acos(-1.0); 
const long double eps=1e-6;
const long long maxw=1e17+10;

typedef long long ll;
typedef pair<int,int> pii;
/*head------[@cordercorder]*/

const int maxn=1e4+10; 

int res[30];
char s[maxn];
int len;

void solve(){
	memset(res,0,sizeof(res));
	for(int i=1;i<=len;i++){
		if(s[i]>='A'&&s[i]<='Z'){
			s[i]=s[i]+32;
		}
	}
	for(int i=1;i<=len;i++){
		res[(int)(s[i]-'a')]++;
	}
	sort(res,res+26,greater<int>());
	int ans=0,cnt=26;
	for(int i=0;i<26;i++){
		ans+=(res[i]*(cnt--));
	}
	printf("%d\n",ans);
}

int main(void){
	scanf("%s",s+1);
	len=strlen(s+1);
	solve();
	return 0;
}
