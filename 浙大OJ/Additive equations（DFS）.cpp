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

const int maxsize=35;

int a[maxsize],pos[maxsize];

int m,t,num;

bool flag;

void print(int sum){
	int i;
	for(i=pos[num-1]+1;i<m;i++)
		if(sum==a[i])
			break;
	if(i<m){
		flag=1;
		for(i=0;i<num;i++){
			if(i)
				printf("+");
			printf("%d",a[pos[i]]);
		}
		printf("=%d\n",sum);
	}
}

int Search(int k,int sum){
	if(k==num){
		print(sum);
		return 1;
	}
	int i,b;
	if(k==0)
		b=0;
	else
		b=pos[k-1]+1;
	for(i=b;i<m-1;i++){
		pos[k]=i;
		if(sum+a[pos[k]]>a[m-1])//部分和比最大元素的值还要大，则放弃搜索 
			return 0;
		if(!Search(k+1,sum+a[pos[k]])&&pos[k+1]-pos[k]==1)//相邻的元素构成部分和时无解，后面的元素肯定无解 
			return 0;
	}
	return 1;
}

int main(void){
	int i;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&m);
		for(i=0;i<m;i++){
			scanf("%d",&a[i]);
		}
		sort(a,a+m);
		flag=0;
		for(i=2;i<m;i++){
			num=i;//pos是搜索的截止位置
			Search(0,0);
		}
		if(!flag){
			printf("Can't find any equations.\n");
		}
		printf("\n");
	}
	return 0;
}
