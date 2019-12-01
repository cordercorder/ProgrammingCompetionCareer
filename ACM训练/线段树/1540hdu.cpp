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
stack<int> s;
set<int> res;
set<int>::iterator it1;
set<int,greater<int> > res2;
set<int,greater<int> >::iterator it2;

int main(void){
	int x;
	char str[20];
	int ans;
	while(scanf("%d %d",&n,&m)!=EOF){
		for(int i=1;i<=m;i++){
			scanf("%s",str);
			if(str[0]=='D'){
				scanf("%d",&x);
				s.push(x);
				res.insert(x);
				res2.insert(x);
			}
			else if(str[0]=='Q'){
				scanf("%d",&x);
				if(res.find(x)!=res.end()){
					puts("0");
					continue;
				}
				ans=0;
				it1=res.upper_bound(x);
				if(it1==res.end()){
					ans+=(n-x+1);
				}
				else{
					ans+=((*it1)-x);
				}
				it2=res2.upper_bound(x);
				if(it2==res2.end()){
					ans+=(x-1);
				}
				else{
					ans+=(x-(*it2)-1);
				}
				printf("%d\n",ans);
			}
			else{
				x=s.top();
				s.pop();
				res.erase(x);
				res2.erase(x);
			}
		}
		while(!s.empty())
			s.pop();
		res.clear();
		res2.clear();
	}
	return 0;
}
