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

int a,b,x;

char s[210],s2[210];
int len,len2;

bool check(char *str,int __len){
	int num[2]={0,0},sum=0;
	for(int i=1;i<len-1;i++){
		num[(int)(str[i]-'0')]++;
		if(str[i]!=str[i+1]){
			sum++;
		}
	}
	num[(int)(str[len-1]-'0')]++;
	if(num[0]==a&&num[1]==b&&sum==x){
		return 1;
	}
	return 0;
}

void solve(){
	int cnt=x/2;
	int num[2]={0,0},num2[2]={0,0};
	cnt*=2;
	len=1;
	len2=1;
	for(int i=1;i<=cnt+1;i++){
		if(i&1){
			s[len++]='1';
			s2[len2++]='0';
			num2[0]++;
			num[1]++;
		}
		else{
			s[len++]='0';
			s2[len2++]='1';
			num2[1]++;
			num[0]++;
		}
		//putchar(s[i]);
	}
	//puts("");
	while(num[1]<b){
		s[len++]='1';
		num[1]++;
	}
	while(num2[0]<a){
		s2[len2++]='0';
		num2[0]++;
	}
	while(num[0]<a){
		s[len++]='0';
		num[0]++;
	}
	while(num2[1]<b){
		s2[len2++]='1';
		num2[1]++;
	}
	s[len]='\0';
	s2[len2]='\0';
	//deb(s+1);
	//deb(s2+1);
	if(check(s,len)){
		puts(s+1);
	}
	else{
		puts(s2+1);
	}
}

int main(void){
	while(cin>>a>>b>>x){
		solve();	
	}
	return 0;
}
