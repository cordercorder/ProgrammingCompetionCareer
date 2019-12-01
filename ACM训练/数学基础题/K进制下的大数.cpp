#include<algorithm>
#include<iostream>
#include<limits.h>
#include<cstdlib>
#include<cstring>
#include<vector>
#include<string>
#include<cstdio>
#include<bitset>
#include<cmath>
#include<queue>
#include<stack>
#include<deque>
#include<ctime>
#include<set>
#include<map>

#define deb(x) cout<<"#---"<<#x<<"=="<<x<<endl
#define FC ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define FIN freopen("data.txt","r",stdin)
#define FOUT freopen("data.txt","w",stdout)

using namespace std;

const long double PI=acos(-1.0);  
const long double eps=1e-6;
const long long maxw=1e17+10;

typedef long long ll;
typedef pair<int,int> pii;
/*head------[@cordercorder]*/

const int maxn=1e5+10;

char s[maxn];

void solve(){
	int len=strlen(s+1);
	int sum,ans=100;
	bool f; 
	for(int i=2;i<=36;i++){
		sum=0;
		f=0;
		for(int j=1;j<=len;j++){
			if(s[j]>='A'&&s[j]<='Z'){
				if((int)(s[j]-'A')+11>i){
					f=1;
					break;
				}
				sum=(sum*i+(int)(s[j]-'A')+10)%(i-1);
			}
			else{
				sum=(sum*i+(int)(s[j]-'0'))%(i-1);
			}
		}
		if(f)
			continue;
		if(sum%(i-1)==0){
			printf("%d\n",i);
			return ;
		}
	}
	puts("No Solution");
}

int main(void){
	scanf("%s",s+1);
	solve();
	return 0;
}
