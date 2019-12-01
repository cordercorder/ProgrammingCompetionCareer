# include<iostream>
# include<string>

using namespace std;

void solve(string &str1,string &str2){
	int i,temp,res=1,ans=1;
	for(i=0;i<str1.length();i++){
		temp=str1[i]-64;
		res=res*temp;
	}
	for(i=0;i<str2.length();i++){
		temp=str2[i]-64;
		ans=ans*temp;
	}
	if(ans%47==res%47){
		cout<<"GO"<<endl;
	}
	else{
		cout<<"STAY"<<endl;
	}
}

int main(void){
	string str1,str2;
	while(cin>>str1>>str2){
		solve(str1,str2);
	}
	return 0;
}
