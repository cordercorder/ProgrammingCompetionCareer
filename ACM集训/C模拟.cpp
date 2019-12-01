# include<iostream>
# include<string>
# include<cstring>

using namespace std;

int main(void){
	string str;
	int i,num[3];
	while(cin>>str){
		if(str=="E")
		break;
		memset(num,0,sizeof(int)*3);
		for(i=0;i<str.length();i++)
		if(str[i]=='Z')
			num[0]++;
			else if(str[i]=='O')
				num[1]++;
					else if(str[i]=='J')
						num[2]++;
		for(i=0;i<str.length();i++){
			if(num[0]){
				cout<<"Z";
				num[0]--;
			}
			if(num[1]){
				cout<<"O";
				num[1]--;
			}
			if(num[2]){
				cout<<"J";
				num[2]--;
			}
		}
		cout<<endl;
	}
	return 0;
}
