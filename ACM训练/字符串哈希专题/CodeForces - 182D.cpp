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

const int maxn=1e5+10;

string s[2];
int nxt[2][maxn];

int handle(int id){
	int i,j;
	j=nxt[id][0]=-1;
	i=0;
	while(i<(int)s[id].length()){
		while(j!=-1&&s[id][i]!=s[id][j]){
			j=nxt[id][j];
		}
		nxt[id][++i]=++j;
	}
	int len=(int)s[id].length();
	if(len%(len-nxt[id][len])==0){
		return (len-nxt[id][len]);//最小循环节长度
	}
	return len; 
}

void solve(){
	int tot1,tot2;
	tot1=handle(0);
	tot2=handle(1);
	if(tot1!=tot2){
		cout<<"0"<<'\n';
		return ;
	}
	for(int i=0;i<tot1;i++){
		if(s[0][i]!=s[1][i]){
			cout<<"0"<<'\n';
			return ;
		}
	}
	int ans=0;
	int res1,res2;
	res1=(int)s[0].length()/tot1;
	res2=(int)s[1].length()/tot2;
	for(int i=1;i<=min(res1,res2);i++){
		if(res1%i==0&&res2%i==0){
			ans++;
		}
	}
	cout<<ans<<'\n';
}

int main(void){
	FC;
	cin>>s[0]>>s[1];
	solve();
	return 0;
}
