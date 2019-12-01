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
#define FOUT freopen("A.txt","w",stdout)

using namespace std;

const long double PI=acos(-1.0);  
const long double eps=1e-6;
const long long maxw=1e17+10;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
/*head------[@cordercorder]*/

int n,m;

struct Trie{
    int v;
    Trie *nxt[26];
    Trie():v(0){
        for(int i=0;i<26;i++){
            this->nxt[i]=NULL;
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
    int query(const string &s){
        Trie *p=this;
        int id;
        for(int i=0;i<(int)s.length();i++){
            id=(int)(s[i]-'a');
            if(p->nxt[id]==NULL)
                return 0;
            p=p->nxt[id];
        }
        return p->v;
    }
};

int main(void){
	string s;
	FC;
	cin>>n;
	Trie *res=new Trie;
	for(int i=0;i<n;i++){
	    cin>>s;
	    res->insert_(s);
    }
    cin>>m;
	for(int i=0;i<m;i++){
	    cin>>s;
	    cout<<res->query(s)<<'\n';
    }
	return 0;
}
