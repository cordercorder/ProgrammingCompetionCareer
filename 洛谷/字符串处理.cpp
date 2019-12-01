# include<iostream>
# include<string>
# include<cstring>
# include<cmath>

using namespace std;

int num[26];

bool solve(int &m){
	int i,Min=10000,Max=-1;
	for(i=0;i<26;i++){
			Max=max(num[i],Max);
			if(num[i]) 
			Min=min(num[i],Min);
	}
	m=Max-Min;
	if(m==0||m==1)
		return 0;
	if(m==2)
		return 1;
	for(i=2;i<=sqrt(m)+1;i++)
		if(!(m%i))
			return 0;
	return 1;
}

int main(void){
	string str;
	int i,m;
	cin>>str;
	memset(num,0,sizeof(int)*26);
	for(i=0;i<str.length();i++){
		num[str[i]-97]++;
	}
	if(solve(m))
		cout<<"Lucky Word"<<endl<<m<<endl;
	else
		cout<<"No Answer"<<endl<<"0"<<endl;
	return 0;
}
