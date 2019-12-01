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
#define FIN freopen("in.txt","r",stdin)
#define FOUT freopen("out.txt","w",stdout)

using namespace std;

const long double PI=acos(-1.0);  
const long double eps=1e-6;
const long long maxw=1e17+10;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
/*head------[@cordercorder]*/

const ll maxn=1e5+10;

char s[maxn],s2[maxn];
int nxt[maxn],len;

void pre_handle(){
	int i,j;
	j=nxt[0]=-1;
	i=0;
	while(i<len){
		if(j!=-1&&s[i]!=s[j]){
			j=nxt[j];
		}
		nxt[++i]=++j;
	}
}

int handle(){
	int i=0,j=0;
	while(i<len&&j<len){
		if(j==-1||s2[i]==s[j]){
			i++;
			j++; 
		}
		else{
			j=nxt[j];
		}
	}
	return j;
}

void solve(){
	strcpy(s2,s);
	len=strlen(s);
	reverse(s2,s2+len); 
	pre_handle();
	deb(handle());
	
}


int main(void){
	while(scanf("%s",s)!=EOF){
		
		solve();
	}
	
	return 0;
}
