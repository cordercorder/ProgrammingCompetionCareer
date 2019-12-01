# include<stdio.h>
# include<string.h>
# include<stdlib.h> 

# define Maxsize 101

void Change(char *str){
	int len=strlen(str),i,count=0,temp;
	char *str1=(char*)malloc(sizeof(char)*len);
	for(i=0;i<len;i++){
		if(str[i]>='1'&&str[i]<='9'){
			if(i+1<len&&str[i+1]>='0'&&str[i+1]<='9'){
				temp=(str[i]-48)*10+(str[i+1]-48);
				str1[count++]=temp+64;
				i++;
			}
			else{
				temp=(str[i]-48);
				str1[count++]=temp+64;
			}
		}
		else if(str[i]=='#')
		str1[count++]=' ';
	}
	str1[count]='\0';
	strcpy(str,str1);
}

int main(void){
	int T;
	scanf("%d",&T);
	char str[Maxsize];
	getchar();
	while(T--){
		scanf("%s",str);
		Change(str);
		printf("%s\n",str);
	}
	return 0;
}
