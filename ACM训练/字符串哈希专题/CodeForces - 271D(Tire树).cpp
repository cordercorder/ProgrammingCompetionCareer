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

string s,t;
int k;

struct Trie{
	bool v;
	Trie *nxt[26];
	Trie():v(false){
		for(int i=0;i<26;i++){
			this->nxt[i]=NULL;
		}
	}
};

Trie *root,*p;

bool insert_t(int pos){
	Trie *q;
	int id;
	bool f=false;
	id=s[pos]-'a';
	if(p->nxt[id]==NULL){
		q=new Trie;
		q->v=true;
		p->nxt[id]=q;
		p=p->nxt[id];
		f=true;
	}
	else{
		p=p->nxt[id];
	}
	return f;
}

void del(Trie *T){
	if(T==NULL)
		return ;
	for(int i=0;i<26;i++){
		if(T->nxt[i]!=NULL){
			del(T->nxt[i]);
			delete T;
		}
	}
}

void solve(){
	int ans=0,sum;
	root=new Trie;
	for(int i=0;i<(int)s.length();i++){
		sum=0;
		p=root;
		for(int j=i;j<(int)s.length();j++){
			if(t[s[j]-'a']=='0'){
				sum++;
				if(sum>k)
					break;
			}
			//deb(sum);
			ans+=(int)insert_t(j);
		}
	}
	cout<<ans<<'\n';
}

int main(void){
	FC;
	cin>>s>>t>>k;
	solve();
	return 0;
}
