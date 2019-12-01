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

string s;
vector<int> res;

bool check(const char &ch){
	if(ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u')
		return 0;
	return 1;
}

void solve(){
	for(int i=0;i<(int)s.length();i++){
		if(check(s[i])){
			res.push_back(i);
		}
	}
	int tmp;
	for(int i=0;i<(int)res.size();i++){
		if(s[res[i]]=='n'){
			continue;
		}
		tmp=res[i]+1;
		if(tmp<(int)s.length()&&check(s[tmp])){
			puts("NO");
			res.clear();
			return;
		}
		else if(tmp==(int)s.length()){
			puts("NO");
			res.clear();
			return;
		}
	}
	puts("YES");
	res.clear();
}

int main(void){
	while(cin>>s){
		solve();
	}
	return 0;
}
