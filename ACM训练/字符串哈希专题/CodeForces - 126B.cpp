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

const int maxn=1e6+10;

string s;
vector<int> nxt;

void get_nxt(){
	int i,j;
	nxt.resize((int)s.length()+1);
	i=0;
	j=nxt[0]=-1;
	while(i<(int)s.length()){
		if(j==-1||s[i]==s[j]){
			nxt[++i]=++j;
		}
		else{
			j=nxt[j];
		}
	}
}

void solve(){
	get_nxt();
	vector<bool> isv((int)s.length()+1,false);
	for(int i=1;i<(int)s.length();i++){
		isv[nxt[i]]=true;
	}
	int ret=nxt[(int)s.length()];
	while(ret>0&&isv[ret]==false){
		ret=nxt[ret];
	}
	if(ret==0){
		cout<<"Just a legend"<<'\n';
		return ;
	}
	cout<<s.substr(0,ret)<<'\n';
}

int main(void){
	FC;
	cin>>s;
	solve();
	return 0;
}
