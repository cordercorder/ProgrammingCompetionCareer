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

# define ll long long

using namespace std;

const int maxsize=1e3+10;

struct node{
	string name;
	string ip;
};

node a[maxsize];

int n,m;

void solve(const string &x,const string &y){
	int i;
	for(i=0;i<n;i++){
		if((a[i].ip+";")==y){
			cout<<x<<" "<<y<<" #"<<a[i].name<<endl;
			return ;
		}
	}
}

int main(void){
	int i;
	string x,y;
	while(scanf("%d %d",&n,&m)!=EOF){
		for(i=0;i<n;i++){
			cin>>a[i].name>>a[i].ip;
		}
		for(i=0;i<m;i++){
			cin>>x>>y;
			solve(x,y);
		}
	}
	return 0;
}
