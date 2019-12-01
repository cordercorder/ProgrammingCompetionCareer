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
#include<ctime>

#define deb(x) cout<<"#---"<<#x<<"=="<<x<<endl

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

string s,t;
int ans;

void solve(){
	int sum=0;
	for(int i=0;i<(int)s.length()&&i<(int)t.length();i++){
		if(s[i]==t[i]){
			sum++;
		}
		else{
			break;
		}
	}
	//deb(sum);
	ans=(int)s.length()+(int)t.length()-2*sum;
	printf("%d\n",ans);
}

int main(void){
	while(cin>>s>>t){
		reverse(s.begin(),s.end());
		reverse(t.begin(),t.end());
		solve();
	}
	return 0;
}
