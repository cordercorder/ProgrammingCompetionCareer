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
typedef unsigned long long ull;
typedef pair<int,int> pii;
/*head------[@cordercorder]*/

const int maxn=2000;

string s,t;
int k;
bool isv[30];
int sum[maxn];
unordered_map<ll,bool> mp;
const ll mod=1000000007LL;
const ll seed[7]={1311LL,10007LL,11137LL,5471LL,74507LL,49741LL,94447LL};

void pre_handle(){
	for(int i=0;i<(int)t.length();i++){
		if(t[i]=='1'){
			isv[i]=true;
		}
	}
	sum[0]=0;
	for(int i=0;i<(int)s.length();i++){
		sum[i+1]=sum[i]+(int)(isv[s[i]-'a']==false);
	}
}

void solve(){
	int pos;
	int ans=0;
	ll tmp=0;
	pre_handle();
	int cnt;
	for(int i=0;i<(int)s.length();i++){
		pos=upper_bound(sum,sum+(int)s.length()+1,k+sum[i])-sum-1;
		tmp=0;
		for(int j=i;j<pos;j++){
			tmp+=(tmp*seed[(ll)(s[j]+100000)%7]+(ll)(s[j]))%mod;
			if(mp.count(tmp)==0){
				mp[tmp]=true;
				ans++;
			}
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
