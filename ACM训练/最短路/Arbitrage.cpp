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

const long double PI=acos(-1.0); 
const long double eps=1e-6;
const double maxw=1e8+10;

typedef long long ll;
typedef pair<int,int> pii;
/*head------[@cordercorder]*/

const int maxn=35;


map<string,int> mp;
int n,m;
double D[maxn][maxn];

bool check(){
	for(int k=1;k<=n;k++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				D[i][j]=max(D[i][j],D[i][k]*D[k][j]);
			}
		}
	}
	for(int i=1;i<=n;i++){
		if(D[i][i]>(double)1)
			return 1;
	}
	return 0;
}

int main(void){
	int ca=0;
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	string s,u,v;
	double w;
	while(cin>>n){
		if(n==0)
			break;
		for(int i=1;i<=n;i++){
			cin>>s;
			mp[s]=i;
		}
		cin>>m;
		memset(D,0,sizeof(D));
		for(int i=1;i<=m;i++){
			cin>>u>>w>>v;
			D[mp[u]][mp[v]]=max(D[mp[u]][mp[v]],w);
		}
		++ca;
		cout<<"Case "<<ca<<": ";
		if(check()){
			cout<<"Yes"<<endl;
		}
		else{
			cout<<"No"<<endl;
		}
		mp.clear();
	}
	return 0;
}
