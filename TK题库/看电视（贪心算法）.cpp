# include<iostream>
# include<algorithm> 

using namespace std;

typedef struct Node{
	int start;
	int end;
	int op;
}Node;

bool cmp(const Node &a,const Node &b){
	return a.end<b.end;
}

void Handle(Node *num,const int &n){
	int i,j;
	for(i=0;i<n;i++){
		for(j=i+1;j<n;j++){
			if(num[i].end>num[j].start&&num[i].op==1)
			num[j].op=-1;
		}
	}
}

void Result(Node *num,const int &n){
	int i,count=0;
	for(i=0;i<n;i++)
	if(num[i].op==1)
	count++;
	cout<<count<<endl;
}

int main(void){
	int n,i;
	while(cin>>n){
		if(n==0)
		break;
		Node *num=new Node[n];
		for(i=0;i<n;i++){
			cin>>num[i].start>>num[i].end;
			num[i].op=1;
		}
		sort(num,num+n,cmp);
		Handle(num,n);
		Result(num,n);
		delete [] num;
	}
	return 0;
} 
