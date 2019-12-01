# include<iostream>
# include<cstring>

using namespace std;

char Change(char ch){
	if(ch<='z'&&ch>='a')
	return ch-32;
	else
	return ch;
}

int main(void){
	char str[10000],str1[10000];
	int n,i,j,len,op,count;
	cin>>n;
	getchar();
	for(i=0;i<n;i++){
		cin.getline(str,10000);
		len=strlen(str);
		count=0;
		op=0;
		for(j=0;j<len&&str[j]==' ';j++);
		str1[count++]=Change(str[j]);
		for(;j<len;j++){
			if(str[j]==' '){
				op=1;
				continue;
			}
			else if(op==1){
				str1[count++]=Change(str[j]);
				op=0;
			}
		}
		str1[count]='\0';
		cout<<str1<<endl;
	}
	return 0;
}
