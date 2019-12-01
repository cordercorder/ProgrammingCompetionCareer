# include<iostream>
# include<string>
# include<cmath>

using namespace std;

void solve(string &s,string &str){
	int i=0,j=0,ans=0,loc;
	bool flag=0;
	while(i<str.length()&&j<s.length()){
		//printf("shiyan %d\n",abs(str[i]-str[j]));
		if(str[i]==s[j]||abs(str[i]-s[j])==32){
			i++;
			j++;
			if(((i==str.length())||(str[i]==' '))&&j==s.length()){
			if(!flag){
				loc=i-j;
				flag=1;//代表已经找到 
			}
			ans++;
			j=0;
			}
		}
		else{
			i=i-j+1;
			j=0;
		}
	}
	if(flag)
		printf("%d %d\n",ans,loc);
	else
		printf("-1\n");
}

int main(void){
	string s,str;
	getline(cin,s);
	getline(cin,str);
	while(s[s.length()-1]==' '){
		s=s.erase(s.length()-1,1);
	}
	solve(s,str);
	return 0;
} 
