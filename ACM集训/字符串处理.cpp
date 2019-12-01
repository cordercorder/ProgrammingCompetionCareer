# include<iostream>
# include<string>

using namespace std;

int main(void){
	string str;
	int i,ans;
	while(getline(cin,str)){
		if(str=="#")
		break;
		ans=0;
		for(i=0;i<str.length();){
			if(str[i]==' '){
				ans++;
				//cout<<"str[i]="<<str[i]<<endl<<"ans="<<ans<<endl;
				while(str[i]==' ')
					i++;
					continue;
			}
			i++;
		}
		if(str[str.length()-1]==' ')
			cout<<ans<<endl;
		else
			cout<<ans+1<<endl;
	}
	return 0;
}
