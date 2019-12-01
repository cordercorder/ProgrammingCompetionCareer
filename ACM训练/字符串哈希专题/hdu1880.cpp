#include<unordered_map>
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
typedef pair<int,int> pii;
/*head------[@cordercorder]*/

const int maxn=1e5+10;
const int H=100007;

char s[maxn][25],s2[maxn][85],tmp[120];
int cnt,n;
unordered_map<int,int> res1,res2;
unordered_map<int,int>::iterator it;

unsigned int getHash(char *str){//hash的大概思路是把字符串看做p进制数，为了尽可能避免冲突，p取素数31或131等 
	unsigned int seed=131;
	unsigned int hash=0;
	while(*str){
		hash=hash*seed+(*str);
		str++;
	}
	return (hash&0x7fffffff);
}

void pre_handle(){
	for(int i=1;i<cnt;i++){
		res1[getHash(s[i])]=i;
		res2[getHash(s2[i])]=i;
	}
}

int main(void){
	cnt=1;
	while(scanf("%s",s[cnt])){
		if(s[cnt][0]=='@')
			break;
		getchar();
		gets(s2[cnt]);
		++cnt;
	}
	pre_handle();
	scanf("%d",&n);
	getchar();
	for(int i=0;i<n;i++){
		gets(tmp);
		if(tmp[0]=='['){
			it=res1.find(getHash(tmp));
			if(it==res1.end()){
				puts("what?");
			}
			else{
				puts(s2[it->second]);
			}
		}
		else{
			it=res2.find(getHash(tmp));
			if(it==res2.end()){
				puts("what?");
			}
			else{
				int pos=it->second;
				for(int j=1;s[pos][j]!=']';j++){
					putchar(s[pos][j]);
				}
				puts("");
			}
		}
	}
	return 0;
}
