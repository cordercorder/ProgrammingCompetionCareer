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

const int maxn=3e5+10;

string t;
string s;
int n,m;

struct Trie{
	Trie *nxt[3];
	Trie(){
		for(int i=0;i<3;i++){
			nxt[i]=NULL;
		}
	}
	void insert_(const string &s){
		int id;
		Trie *q,*p=this;
		for(int i=0;i<(int)s.length();i++){
			id=(int)(s[i]-'a');
			if(p->nxt[id]==NULL){
				q=new Trie;
				p->nxt[id]=q;
				p=p->nxt[id];
			}
			else{
				p=p->nxt[id];
			}
		}
	}
};

Trie *res; 

bool dfs(Trie *p,int pos,int sum){
	if(pos==(int)s.length()){
		return sum==1;
	}
	int id=(int)(s[pos]-'a');
	for(int i=0;i<3;i++){
		if(id!=i&&sum==0&&p->nxt[i]!=NULL&&dfs(p->nxt[i],pos+1,sum+1)){
			return true;
		}
		else if(id==i&&p->nxt[i]!=NULL&&dfs(p->nxt[i],pos+1,sum)){
			return true;
		}
	}
	return false;
}

int main(void){
	FC;
	cin>>n>>m;
	res=new Trie();
	for(int i=1;i<=n;i++){
		cin>>t;
		res->insert_(t);
	}
	while(m--){
		cin>>s;
		if(dfs(res,0,0)){
			cout<<"YES"<<'\n';
		}
		else{
			cout<<"NO"<<'\n';
		}
	}
	return 0;
}
