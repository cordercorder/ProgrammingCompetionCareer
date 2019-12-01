# include<iostream>
# include<algorithm>
# include<cstring>
# include<string>
# include<cmath>
# include<queue>
# include<stack>
# include<set>
# include<vector>
# include<cstdio>
# include<cstdlib>
# include<map>
# include<deque>

# define deb(x) printf("# x=%d\n",x)
# define deb_d(x) printf("# x=%lf\n",x)
# define ccout(x) printf("%d\n",x)

typedef long long ll;

using namespace std;

const int maxsize=1e5+10;

vector<ll> p;
bool f[maxsize]; 

int main(void){
	memset(f,0,sizeof(f));
	for(ll i=2;i<=maxsize;i++){
		if(!f[i]){
			p.push_back(i);
			for(ll j=i*i;j<=maxsize;j+=i){
				f[j]=1;
			}
		}
	}
	for(ll i=0;i<p.size();i++){
		printf("%d ",p[i]);
	}
	return 0;
}
