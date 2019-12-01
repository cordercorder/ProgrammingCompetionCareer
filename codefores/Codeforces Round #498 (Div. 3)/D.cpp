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

const int maxn=1e5+10; 

int n;
char a[maxn],b[maxn];
set<char> s;

void solve(){
	int ans=0;
	int len=(n+1)/2;
	for(int i=1;i<=len;i++){
		if(b[i]==b[n-i+1]){
			if(a[i]==a[n-i+1])
				continue;
			ans++;
		}
		else{
			if(a[i]==a[n-i+1]){
				ans+=!(a[i]==b[i]);
				ans+=!(a[i]==b[n-i+1]);
			}
			else{
				if(a[i]==b[i]&&a[n-i+1]==b[n-i+1])
					continue;
				if(a[i]==b[n-i+1]&&a[n-i+1]==b[i])
					continue;
				if(a[i]==b[i]||a[i]==b[n-i+1]||a[n-i+1]==b[i]||a[n-i+1]==b[n-i+1]){
					ans++;
				}
				else{
					ans+=2;
				}
			}
		}
	}
	if((n&1)&&a[len]!=b[len])
		ans++;
	printf("%d\n",ans);
}

int main(void){
	while(scanf("%d",&n)!=EOF){
		scanf("%s %s",a+1,b+1);
		solve();
	}
	return 0;
}
