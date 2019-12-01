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

typedef long long ll;

using namespace std;

const int maxsize=25;

const int maxw=1e6;

char str[maxsize],tmp[maxsize];
int len,ans;

void handle(const int &x){
	if(x<len-1){
		if(str[x+1]=='0')
			str[x+1]='1';//�ı��һ���ַ��� 
		else
			str[x+1]='0';
	}
	if(x>0){
		if(str[x-1]=='0')
			str[x-1]='1';//�ı�ǰһ���ַ��� 
		else
			str[x-1]='0';
	}
}

void solve(int x,int num){
	if(strcmp(str,tmp)==0){
		if(num<ans)
			ans=num;
		return ;
	}
	if(x>=len)
		return ;
	if(str[x]=='0'){//�ı��ַ��� 
		str[x]='1';
		handle(x);
		solve(x+1,num+1);
		str[x]='0';//��ԭ�ַ���
		handle(x);
	}
	else if(str[x]=='1'){
		str[x]='0';
		handle(x);
		solve(x+1,num+1);
		str[x]='1';//��ԭ�ַ��� 
		handle(x);
	}
	solve(x+1,num);//���ı��ַ��� 
}

int main(void){
	int i;
	while(scanf("%s",str)!=EOF){
		len=strlen(str);
		for(i=0;i<len;i++){
			tmp[i]='0';
		}
		tmp[len]='\0';//�Ƚ��ַ��� 
		ans=maxw;
		solve(0,0);
		if(ans==maxw){
			printf("NO\n");
		}
		else{
			printf("%d\n",ans);
		}
	}
	return 0;
}
