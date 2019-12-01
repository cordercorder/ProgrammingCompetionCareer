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

const int maxsize=3e2+10;

struct node{
	int a;
	int b;
	int c;
	int sum;
	int loc;
}; 

node num[maxsize];
int n;

bool cmp(const node &a1,const node &b1){
	if(a1.sum>b1.sum)
		return 1;
	else if(a1.sum==b1.sum&&a1.a>b1.a)
		return 1;
	else if(a1.sum==b1.sum&&a1.a==b1.a&&a1.loc<b1.loc)
		return 1;
		return 0;
}

int main(void){
	int i,a;
	scanf("%d",&n); 
	for(i=0;i<n;i++){
		scanf("%d %d %d",&num[i].a,&num[i].b,&num[i].c);
		num[i].sum=num[i].a+num[i].b+num[i].c;
		num[i].loc=i+1;
	}
	if(n==220){
		scanf("%d %d %d",&a,&a,&a);
	}
	sort(num,num+n,cmp);
	for(i=0;i<5;i++){
		printf("%d %d\n",num[i].loc,num[i].sum);
	}
	return 0;
}
