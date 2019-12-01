# include<iostream>
# include<string>

using namespace std;

int main(void){
	int n,T,location;
	string temp;
	cin>>T;
	while(T--){
		string str="zzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzz";
		cin>>n>>temp; 
		char Min='z';
		for(int i=0;i<n;i++){
			Min=min(Min,temp[i]);
		}
		for(int i=0;i<n;i++){
			if(temp[i]==Min){
				string str1=temp.substr(i,n)+temp.substr(0,i);
				if(str1<str){
					location=i;
					str=str1;
				}
			}
		}
		cout<<location<<endl;
	}
	return 0;
}
