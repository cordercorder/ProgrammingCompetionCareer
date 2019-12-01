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

map<string,vector<string> > e;
map<string,bool> isv; 

int n,m;
string fa,son;
string s1,s2,ans;

void dfs1(string s){
    isv[s]=true;
    int len=e[s].size();
    string v;
    for(int i=0;i<len;i++){
        v=e[s][i];
        if(isv[v]==false){
            dfs1(v);
        }
    }
}

bool dfs2(string s,string f){
    if(isv[s]){
        ans=s;
        return true;
    }
    int len=e[s].size();
    string v;
    for(int i=0;i<len;i++){
        v=e[s][i];
        if(v==f)
            continue;
        if(dfs2(v,s))
            return true;
    }
    return false;
}

int main(void){
	FC;
	cin>>n;
	for(int i=0;i<n;i++){
	    cin>>fa>>son;
	    e[son].push_back(fa);
    }
	cin>>m;
	for(int i=0;i<m;i++){
	    cin>>s1>>s2;
	    dfs1(s1);
	    if(dfs2(s2,"")){
	        cout<<ans<<'\n';
        }
	    else{
	        cout<<"-1"<<'\n';
        }
        isv.clear();
    }
	return 0;
}
