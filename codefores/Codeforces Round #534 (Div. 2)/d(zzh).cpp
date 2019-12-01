#include <bits/stdc++.h>
using namespace std;

#define io ios::sync_with_stdio(false)
#define pb push_back
#define pqueue priority_queue
#define fi first
#define se second
#define ls rt<<1
#define rs rt<<1|1
#define mid (l+r)/2
#define sz(x) (int)(x).size()
#define dbg(x) cout<<#x<<"---"<<x<<endl
#define mst(x,a) memset(x,a,sizeof(x))
#define fin(a) freopen(a,"r",stdin)
#define fout(a) freopen(a,"w",stdout)
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
ll gcd(ll a,ll b){ return b==0?a:gcd(b,a%b); }
const int inf=0x7fffffff;
const ll mx=1e9;

int main(){
	io;
	string s;
	while(cin>>s){
		fflush(stdout);
		if(s=="end")break;
		cout<<"?"<<" "<<2<<" "<<1<<endl;
		fflush(stdout);
		string c;
		ll x=2,y=1;
		bool ok=false;
		while(cin>>c){
			fflush(stdout);
			if(!ok){
				if(c=="x"){
					if(x>mx&&y>mx){
						cout<<"!"<<" "<<1<<endl;
						fflush(stdout);
						break;
					}
					x*=2;y*=2;
					x=min(2*mx,x);
					cout<<"?"<<" "<<x<<" "<<y<<endl;
					fflush(stdout);
				}
				else {
					ok=true;
				}
			}
			while(ok){
				string s1,s2;
				ll m=(x+y)/2;
				cout<<"?"<<" "<<x<<" "<<m+1<<endl;
				fflush(stdout);
				cin>>s1;
				fflush(stdout);
				cout<<"?"<<" "<<m<<" "<<y<<endl;
				fflush(stdout);
				cin>>s2;
				fflush(stdout);
				if(s1=="y"&&s2=="x"){
					y=m+1;
				}
				else if(s1=="x"&&s2=="y"){
					x=m;
				}
				else {
					cout<<"?"<<" "<<m+1<<" "<<y<<endl;
					fflush(stdout);
					string ss;cin>>ss;
					if(ss=="y")cout<<"!"<<" "<<m+1<<endl;
					else cout<<"!"<<" "<<y<<endl;
					fflush(stdout);
					break;
				}
			}
			if(ok)break;
		}
		return 0;
	}
}
