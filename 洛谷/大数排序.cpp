# include<iostream>
# include<string>
# include<algorithm>

using namespace std;

const int maxsize=22;

typedef struct node{
	int number;
	string num;
}node; 

bool cmp(const node &a,const node &b){
	if(a.num.length()>b.num.length())
	return 1;
	else if(a.num.length()==b.num.length()&&a.num>b.num)
	return 1;
	return 0;
}

int main(void){
	node num[maxsize];
	int n,i;
	cin>>n;
	for(i=0;i<n;i++){
		cin>>num[i].num;
		num[i].number=i+1;
	}
	sort(num,num+n,cmp);
	cout<<num[0].number<<endl;
	cout<<num[0].num<<endl;
}
