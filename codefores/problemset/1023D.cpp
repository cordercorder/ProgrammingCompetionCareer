#include<algorithm>
#include<iostream>
#include<limits.h>
#include<cstdlib>
#include<cstring>
#include<vector>
#include<string>
#include<cstdio>
#include<bitset>
#include<cmath>
#include<queue>
#include<stack>
#include<deque>
#include<ctime>
#include<set>
#include<map>

#define deb(x) cout<<"#---"<<#x<<"=="<<x<<endl
#define FC ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define FIN freopen("data.txt","r",stdin)
#define FOUT freopen("data.txt","w",stdout)

using namespace std;

const long double PI=acos(-1.0);
const long double eps=1e-6;
const long long maxw=1e17+10;

typedef long long ll;
typedef pair<int,int> pii;
/*head------[@cordercorder]*/

const int maxn=2e5+10;

vector<int> res;
int n,q;
int a[maxn];
vector<int> pos;

bool check(){
	for(int i=1;i<=n;i++){
		if(a[i]==q){
			pos.push_back(i);
		}
	}
	for(int i=0;i<(int)pos.size()-1;i++){
		//deb(pos[i]);
		//deb(pos[i+1]);
		for(int j=pos[i]+1;j<pos[i+1];j++){
			if(a[j]==0)
				continue;
			return 0;
		}
	}
	if(pos.empty()){
		for(int i=1;i<=n;i++){
			if(a[i]==0)
				return 1;
		}
		return 0;
	}
	return 1;
}

void solve(){
	bool f;
	for(int i=1;i<=n;){
		int j=i;
		f=1;
		while(j<=n&&a[j]==0){
			j++;
			f=0;
		}
		if(a[i]==0&&j<=n){
			for(int k=i;k<j;k++){
				a[k]=a[j];
			}
		}
		if(f){
			i=j+1;
		}
		else{
			i=j;
		}
	}
	for(int i=n;i>=1;){
		int j=i;
		f=1;
		while(j>=1&&a[j]==0){
			j--;
			f=0;
		}
		if(a[i]==0&&j>=1){
			for(int k=j+1;k<=i;k++){
				a[k]=a[j];
			}
		}
		if(f){
			i=j-1;
		}
		else{
			i=j;
		}
	}
	for(int i=1;i<=n;i++){
		if(a[i]==0){
			a[i]=q;
		}
		cout<<a[i]<<" ";
	}
}

int main(void){
	FC;
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(!check()){
		cout<<"NO";
		return 0;
	}
	cout<<"YES"<<'\n';
	solve(); 
	return 0;
}
