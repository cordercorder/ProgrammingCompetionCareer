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

struct node{
	int d;
	string s;
	bool operator<(const node &a)const{
		if(d<a.d)
			return 1;
		if(d==a.d&s<a.s)
			return 1;
		return 0;
	}
};

string s;
set<node> p;

bool check(){
	node tmp;
	for(int d=0;d<int(s.length()-2);d++){
		for(int i=0;i+d+1<s.length();i++){
			tmp.d=d;
			tmp.s+=s[i];
			tmp.s+=s[i+d+1];
			//cout<<"tmp.s=="<<tmp.s<<endl;
			if(p.find(tmp)==p.end()){
				p.insert(tmp);
				tmp.s.clear();
			}
			else
				return 0;
		}
		p.clear();
		tmp.s.clear();
	}
	return 1;
}

int main(void){
	while(cin>>s){
		if(s=="*")
			break;
		if(check()){
			cout<<s<<" is surprising."<<endl;
		}
		else{
			cout<<s<<" is NOT surprising."<<endl;
		}
		p.clear();
	}
	return 0;
}
