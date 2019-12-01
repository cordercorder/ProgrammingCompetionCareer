# include<iostream>
# include<string>
# include<cstring>

using namespace std;

int Cal(string *str,bool *isvisited,const int &n){
	int i,j; 
	for(i=n-1;i>=0;i--){
		for(j=0;j<i;j++)
		if(!isvisited[j]){
			if(str[i].find(str[j])!=string::npos)
			continue;
			else
			return i+1;
		}
	}
	return -1;	
}

int main(void){
	int t,sum=0,n,i;
	cin>>t;
	string str[501];
	bool isvisited[501];
	while(t--){
		sum++;
		cin>>n;
		memset(isvisited,0,sizeof(bool)*501);
		for(i=0;i<n;i++){
			cin>>str[i];
			if(i>0&&str[i].find(str[i-1])!=string::npos)
			isvisited[i-1]=1;
		}
		cout<<"Case #"<<sum<<": ";
		cout<<Cal(str,isvisited,n)<<endl;
	//	for(i=0;i<n;i++)
	//	cout<<str[i]<<endl;
	}
	return 0;
}

