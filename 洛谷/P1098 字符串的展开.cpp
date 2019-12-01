# include<iostream>
# include<cstring>
# include<string>

using namespace std;

const int maxsize=1005;

void solve(const int &p1,const int &p2,const int &p3,string &str){
	int i,j,u,count;
	char temp[maxsize];
	for(i=0;i<str.length();i++){
		count=0;
		if(i>0&&i<str.length()-1&&str[i]=='-'&&str[i+1]>str[i-1]&&((str[i+1]<='Z'&&str[i-1]>='A')||(str[i+1]<='z'&&str[i-1]>='a')||(str[i+1]<='9'&&str[i-1]>='0'))){
			if(p1==1){
				if(p3==1){
					for(j=str[i-1]+1;j<=str[i+1]-1;j++){
					for(u=0;u<p2;u++)
						if(j<='Z'&&j>='A')
							temp[count++]=j+32;
						else
							temp[count++]=j;
				}
				}
				else if(p3==2){
					for(j=str[i+1]-1;j>=str[i-1]+1;j--){
					for(u=0;u<p2;u++)
						if(j<='Z'&&j>='A')
							temp[count++]=j+32;
						else
							temp[count++]=j;
				}
				}
			}
			else if(p1==2){
				if(p3==1){
					for(j=str[i-1]+1;j<=str[i+1]-1;j++){
					for(u=0;u<p2;u++)
						if(j<='Z'&&j>='A')
							temp[count++]=j;
						else if(j<='z'&&j>='a')
							temp[count++]=j-32;
						else
							temp[count++]=j;
				}
				}
				else if(p3==2){
					for(j=str[i+1]-1;j>=str[i-1]+1;j--){
					for(u=0;u<p2;u++)
						if(j<='Z'&&j>='A')
							temp[count++]=j;
						else if(j<='z'&&j>='a')
							temp[count++]=j-32;
						else
							temp[count++]=j;
				}
				}
			}
			else if(p1==3){
				for(j=str[i-1]+1;j<=str[i+1]-1;j++){
					for(u=0;u<p2;u++)
						temp[count++]='*';
				}
			}
			temp[count]='\0';
			if(count!=0)
				printf("%s",temp);
		}
		else{
			printf("%c",str[i]);
		}
	}
}

int main(void){
	int p1,p2,p3;
	string str;
	cin>>p1>>p2>>p3;
	cin>>str;
	solve(p1,p2,p3,str);
}
