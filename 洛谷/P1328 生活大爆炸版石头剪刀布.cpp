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

using namespace std;

const int maxsize=2e2+10;

int n,na,nb; 

int a[maxsize],b[maxsize];

int data[5][5]={
	{0,0,1,1,0},
	{1,0,0,1,0},
	{0,1,0,0,1},
	{0,0,1,0,1},
	{1,1,0,0,0}
};

void solve(){
	int i,j,ans1=0,ans2=0;
	for(i=0;i<n;i++){
		ans1=ans1+data[a[i%na]][b[i%nb]];
		ans2=ans2+data[b[i%nb]][a[i%na]];
	}
	printf("%d %d\n",ans1,ans2);
}

int main(void){
	int i;
	scanf("%d %d %d",&n,&na,&nb);
	for(i=0;i<na;i++){
		scanf("%d",&a[i]);
	}
	for(i=0;i<nb;i++){
		scanf("%d",&b[i]);
	}
	solve();
	return 0;
}
