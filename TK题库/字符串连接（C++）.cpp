# include<iostream>
# include<string>

using namespace std;

int main(void){
	int n,i;
	string str1,str2;
	cin>>n;
	for(i=0;i<n;i++){
		cin>>str1>>str2;
		str1=str1.insert(str1.length()/2,str2);
		cout<<str1<<endl;
	}
	return 0;
}
