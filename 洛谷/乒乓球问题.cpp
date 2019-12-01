# include<iostream>
# include<cstring>
# include<cmath>

using namespace std;

const int maxsize=10000000;

int num[2];
char str[maxsize];

void solve(char *str,const int &len,int xa){
	if(len==0){
		printf("0:0\n");
		return ;
	}
	int i;
	memset(num,0,sizeof(int)*2);
	for(i=0;i<len;i++){
		if(str[i]=='W')
			num[0]++;
		else if(str[i]=='L'){
			num[1]++;
		}
		if((num[0]>=xa||num[1]>=xa)&&abs(num[0]-num[1])>=2){
			printf("%d:%d\n",num[0],num[1]);
			num[0]=0;
			num[1]=0;
		}
	}
	printf("%d:%d\n",num[0],num[1]);
}

int main(void){
	char temp;
	int len=0,i;
	while(scanf("%c",&temp)){
		if(temp=='E')
			break;
		else{
			if(temp=='W')
				str[len++]=temp;
			else if(temp=='L')
				str[len++]=temp;
		}
	}
	str[len]='\0';
	solve(str,len,11);
	printf("\n");
	solve(str,len,21);
	return 0;
}
