# include<iostream>
# include<cstring>
# include<string>

using namespace std;

string str;


int main(void){
	int i,sum,count;
	char ch;
	while(cin>>str){
		sum=0;
		count=0;
		for(i=0;i<str.length()-1;i++){
			if(str[i]>='0'&&str[i]<='9'){
				sum=sum+(str[i]-48)*(count+1);
				count++;
			}
		}
		sum=sum%11;
		ch=sum+48;
		if(sum!=10){
			if(str[str.length()-1]==ch)
				printf("Right\n");
			else{
				str[str.length()-1]=ch;
				cout<<str<<endl;
			}
		}
		else{
			if(str[str.length()-1]=='X')
				printf("Right\n");
			else{
				str[str.length()-1]='X';
				cout<<str<<endl;
			}	
		}
	}
	return 0;
} 
