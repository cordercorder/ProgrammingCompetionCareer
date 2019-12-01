#include<bits/stdc++.h>
using namespace std;
const int N=1e6+6;
char s[N];
int a[N];
int main(){
	int n,x=0;
	scanf("%d",&n);
	scanf("%s",s);
	for(int i=0;i<n;i++){
		if(s[i]=='(')x++;
		else x--;
		a[i]=x;
	}
	for(int i=n-2;i>=0;i--)a[i]=min(a[i+1],a[i]);
	int t=0,b=0;
	for(int i=0;i<n;i++){
		if(s[i]=='('){
			if(a[i]>=2&&x==2)t++;
			b++;
		}
		else{
			if(a[i]>=-2&&x==-2)t++;
			b--;
		}
		cout<<"b=="<<b<<endl;
		if(b<0)break;
	}
	printf("%d\n",t);
}
