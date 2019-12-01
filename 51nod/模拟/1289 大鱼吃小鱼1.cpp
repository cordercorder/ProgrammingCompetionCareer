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
# include<limits.h>
# include<ctime>

# define deb(x) cout<<"#---"<<#x<<"=="<<x<<endl

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

const int maxn=1e5+10;

int n;
stack<int> s;

int main(void){
	int x,id;
	int ans,tmp,Max; 
	while(scanf("%d",&n)!=EOF){
		ans=n;
		for(int i=1;i<=n;i++){
			scanf("%d %d",&x,&id);
			if(id==1){
				s.push(x);
			}
			else{
				while(!s.empty()){
					if(s.top()<x){
						s.pop();
						ans--;
					}
					else{
						ans--;
						break;
					}
				}
			}
		}
		deb(s.size());
		while(!s.empty()){
			deb(s.top());
			s.pop();
			
		}
		printf("%d\n",ans);
	}
	return 0;
}
