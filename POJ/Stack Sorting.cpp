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

const int maxsize=2e5+10;

int n,k; 
int p[maxsize];
stack<int> s;
int cnt;
vector<int> a;


bool check(){
	s.push(p[0]);
	cnt=1;
	for(int i=1;i<k;i++){
		if(!s.empty()&&s.top()<p[i]){
			if(s.top()==cnt){
				a.push_back(s.top());
				s.pop();
				cnt++;
			}
			else
				return 0; 
		}
		s.push(p[i]);
	}
	/*cout<<"cnt="<<cnt<<endl;
	while(!s.empty()){
		cout<<" "<<s.top();
		s.pop();
		
	}*/
	return 1;
}

int main(void){
	
	while(scanf("%d %d",&n,&k)!=EOF){
		for(int i=0;i<k;i++)
			scanf("%d",&p[i]);
		if(!check()){
			puts("-1");
			continue;
		}
		while(!s.empty()){
			
			
			
			
			
		}
		
		
		
		
	}
	
	
	return 0;
}
