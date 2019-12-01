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

string s,tmp;
int n;

struct Trie{
	Trie *nxt[26];
	int v;
	Trie():v(0){
		for(int i=0;i<26;i++){
			nxt[i]=NULL;
		}
	}
	void insert_(const string &s){
		Trie *p=this,*q;
		int id;
		for(int i=0;i<(int)s.length();i++){
			id=(int)(s[i]-'a');
			if(p->nxt[id]==NULL){
				q=new Trie;
				q->v++;
				p->nxt[id]=q;
				p=p->nxt[id];
			}
			else{
				p=p->nxt[id];
				p->v++;
			}
		}
	}
	void Free(Trie *p){
		if(p==NULL)
			return ;
		for(int i=0;i<26;i++){
			if(p->nxt[i]){
				Free(p->nxt[i]);
				delete p->nxt[i];
				p->nxt[i]=NULL;
			}
		}
	}
	void del(const string &s){
		Trie *p=this,*q;
		int id; 
		for(int i=0;i<(int)s.length();i++){
			id=(int)(s[i]-'a');
			q=p->nxt[id];
			if(q==NULL)
				return ;
			p=p->nxt[id];
		}
		int sum=p->v;
		p=this;
		for(int i=0;i<(int)s.length();i++){
			id=(int)(s[i]-'a');
			q=p;
			p=p->nxt[id];
			p->v-=(sum);
			if(p->v==0){
				q->nxt[id]=NULL;
			}
		}
		Free(p);
	}
	bool search(const string &s){
		Trie *p=this;
		int id;
		for(int i=0;i<(int)s.length();i++){
			id=(int)(s[i]-'a');
			if(p->nxt[id]==NULL)
				return false;
			p=p->nxt[id];
		}
		return true;
	}
};

int main(void){
	FC;
	Trie *res=new Trie;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>tmp>>s;
		if(tmp[0]=='i'){
			res->insert_(s);
		}
		else if(tmp[0]=='d'){
			res->del(s);
		}
		else{
			if(res->search(s)){
				cout<<"Yes"<<'\n';
			}
			else{
				cout<<"No"<<'\n';
			}
		}
	}
	return 0;
}
