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

ll t;
ll n,m;
ll tmp[35];

struct Trie{
	Trie *nxt[2];
	Trie(){
		nxt[0]=NULL;
		nxt[1]=NULL;
	}
	void insert(ll num){
		Trie *p=this,*q;
		ll id;
		for(ll i=0;i<32;i++){
			id=num%2;
			tmp[i]=id;
			num>>=1;
		}
		for(ll i=31;i>=0;i--){
			id=tmp[i];
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
	ll query(ll num){
		ll ans=0,ret=(1LL<<31),id;
		Trie *p=this,*q;
		for(ll i=0;i<32;i++){
			tmp[i]=num%2;
			num>>=1;
		}
		for(int i=31;i>=0;i--){
			id=tmp[i];
			id=1-id;
			if(p->nxt[id]==NULL){
				id=1-id;
				p=p->nxt[id];
			}
			else{
				p=p->nxt[id];
			}
			ans+=(ret*id);
			ret>>=1;
		}
		return ans;
	}
	void Free(Trie *p){
		if(p==NULL){
			return ;
		}
		for(int i=0;i<2;i++){
			if(p->nxt[i]){
				Free(p->nxt[i]);
				delete p->nxt[i];
				p->nxt[i]=NULL;
			}
		}
	}
}*res;


int main(void){
	ll tmp;
	scanf("%lld",&t);
	for(ll ca=1;ca<=t;ca++){
		res=new Trie;
		scanf("%lld %lld",&n,&m);
		for(ll i=0;i<n;i++){
			scanf("%lld",&tmp);
			res->insert(tmp);
		}
		printf("Case #%lld:\n",ca);
		while(m--){
			scanf("%lld",&tmp);
			printf("%lld\n",res->query(tmp));
		}
		//res->Free(res);
	}
	return 0;
}
