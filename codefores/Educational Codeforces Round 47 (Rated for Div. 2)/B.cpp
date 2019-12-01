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

const int maxn=1e5+10; 

string s;

void solve(){
	int pos,sum=0;
	string ans;
	for(int i=0;i<(int)s.size();i++){
		if(s[i]!='1'){
			ans+=s[i];
		}
		else{
			sum++;
		}
	}
	for(pos=0;pos<(int)ans.size();pos++){
		if(ans[pos]=='2')
			break;
	}
	ans.insert(pos,string(sum,'1'));
	cout<<ans<<endl;
	ans.clear();
}

int main(void){
	while(cin>>s){
		solve();
	}
	return 0;
}
