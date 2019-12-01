#include<iostream>
#include<algorithm>
#include<cstring>
#include<string>
#include<cmath>
#include<queue>
#include<stack>
#include<set>
#include<vector>
#include<cstdio>
#include<cstdlib>
#include<map>
#include<deque>
#include<limits.h>
#include<bitset>
#include<ctime>

#define deb(x) cout<<"#---"<<#x<<"=="<<x<<endl

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

int n,m;
vector<pii> res;
bitset<100005> isv;

bool check(){
	isv.reset();
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(__gcd(i,j)==1){
				res.push_back(pii(i,j));
				isv[i]=1;
				isv[j]=1;
				if((int)res.size()==m){
					if(isv.count()==n)
						return 1;
					return 0;
				}
			}
		}
	}
	return 0;
}

void solve(){
	if(check()){
		puts("Possible");
		for(int i=0;i<(int)res.size();i++){
			printf("%d %d\n",res[i].first,res[i].second);
		}
	}
	else{
		puts("Impossible");
	}
}

int main(void){
	scanf("%d %d",&n,&m);
	solve();
	return 0;
}
