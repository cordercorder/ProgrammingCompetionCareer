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
set<int> s;
stack<int> res;



int main(void){
	char str[5];
	int x;
	while(scanf("%d %d"&n,&m)!=EOF){
		while(m--){
			scanf("%s",str);
			if(str[0]=='D'){
				scanf("%d",&x);
				res.push(x);
				s.insert(x);
			}
			else if(str[0]=='Q'){
				
				
				
				
			}
			else{
				
				
				
				
			}
			
		}
		
	}
	
	return 0;
}
