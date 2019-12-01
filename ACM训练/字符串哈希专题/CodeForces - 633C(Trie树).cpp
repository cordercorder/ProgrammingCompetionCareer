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

int n,m;
string t;
string w[maxn];
int ans[maxn],top;

struct Trie{
	int ret;
	Trie *nxt[26];
	Trie():ret(-1){
		for(int i=0;i<26;i++){
			nxt[i]=NULL;
		}
	}
	void insert_(int pos,const string &s){
		int id;
		Trie *p=this,*q;
		for(int i=(int)s.length()-1;i>=0;i--){
			if(s[i]>='a'&&s[i]<='z'){
				id=(int)(s[i]-'a');
			}
			else{
				id=(int)(s[i]-'A');
			}
			if(p->nxt[id]==NULL){
				q=new Trie;
				p->nxt[id]=q;
				p=p->nxt[id];
			}
			else{
				p=p->nxt[id];
			}
		}
		p->ret=pos;
	}
}*res;

bool solve(int pos){
	if(pos==(int)t.length())
		return true;
	int now=0,id;
	Trie *p=res;
	for(int i=pos;i<(int)t.length();i++){
		id=(int)(t[i]-'a');
		if(p->nxt[id]==NULL)
			return false;
		else{
			p=p->nxt[id];
		}
		if(p->ret!=-1){
			ans[++top]=p->ret;
			if(solve(i+1)){
				return true;
			}
			--top;
		}
	}
	return false;
}

int main(void){
	FC;
	cin>>n>>t;
	cin>>m;
	res=new Trie;
	for(int i=1;i<=m;i++){
		cin>>w[i];
		res->insert_(i,w[i]);
	}
	top=-1;
	solve(0);
	for(int i=0;i<=top;i++){
		cout<<w[ans[i]]<<" ";
	}
	cout<<'\n';
	return 0;
}
