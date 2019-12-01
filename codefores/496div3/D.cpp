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
#include<ctime>

#define deb(x) cout<<"#---"<<#x<<"=="<<x<<endl

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

const int maxn=2e5+10;

char s[2][maxn];
int len,cnt;
int num[15];
int ans;
int a[maxn];

void solve(){
	ans=0;
	for(int i=0;i<len;i++){
		a[i]=(int)(s[0][i]-'0')%3;
		if(a[i]==0){
			ans++;
			a[i]=-1;
		}
	}
	int sum=0;
	for(int i=0;i<len;i++){
		if(a[i]!=-1){
			sum=0;
			for(int j=i;j<i+3;j++){
				if(a[j]!=-1)
					sum+=a[j];
				if(sum!=0&&sum%3==0){
					//deb(i);
					ans++;
					i=j;
					break;
				}
				if(a[j]==-1){
					break;
				}
			}
		}
	}
	printf("%d\n",ans);
}

int main(void){
	while(cin>>s[0]){
		len=strlen(s[0]);
		solve();
	}
	return 0;
}
