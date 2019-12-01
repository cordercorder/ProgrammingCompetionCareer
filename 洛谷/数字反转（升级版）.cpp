# include<iostream>
# include<string>

using namespace std;

const int maxsize=105;

void solve(string &str){
	char temp[maxsize];
	int i,count=0,len=str.length();
	for(i=0;i<len&&str[len-1-i]=='0';i++);
	for(;i<len;i++){
		temp[count++]=str[len-1-i];
	}
	str.clear();
	if(count==0){
		str="0";
	}
	else{
		temp[count]='\0';
		str=temp;
	}
}

int main(void){
	string str,temp1,temp2;
	int loc;
	while(cin>>str){
		loc=str.find('.');//小数 
		if(loc!=string::npos){
			//cout<<"loc="<<loc<<endl;
			temp1=str.substr(0,loc);
			temp2=str.substr(loc+1,maxsize);
			//cout<<"temp1="<<temp1<<endl;
			//cout<<"temp2="<<temp2<<endl;
			solve(temp1);
			solve(temp2);
			while(temp2.length()>1&&temp2[temp2.length()-1]=='0'){
				temp2=temp2.erase(temp2.length()-1,1);
			}
			cout<<temp1<<"."<<temp2<<endl;
			continue;
		}
		loc=str.find('/');//分数 
		if(loc!=string::npos){
			temp1=str.substr(0,loc);
			temp2=str.substr(loc+1,maxsize);
			solve(temp1);
			solve(temp2);
			cout<<temp1<<"/"<<temp2<<endl;
			continue;
		}
		loc=str.find('%');//百分数 
		if(loc!=string::npos){
			temp1=str.substr(0,loc);
			solve(temp1);
			solve(temp2);
			cout<<temp1<<"%"<<endl;
			continue;
		}
		solve(str);
		cout<<str<<endl;	
	}
	return 0;
}
