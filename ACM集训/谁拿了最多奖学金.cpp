# include<iostream>
# include<algorithm>


using namespace std;

typedef struct Node{
	char name[21];
	int end_grade;
	int dis_grade;
	char head;
	char west;
	int article;
	int location;
	int money;
}Node;

void solve(Node *&num,const int &N){
	int i;
	for(i=0;i<N;i++){
		if(num[i].end_grade>80&&num[i].article>=1)
		num[i].money=num[i].money+8000;
		if(num[i].end_grade>85&&num[i].dis_grade>80)
		num[i].money=num[i].money+4000;
		if(num[i].end_grade>90)
		num[i].money=num[i].money+2000;
		if(num[i].west=='Y'&&num[i].end_grade>85)
		num[i].money=num[i].money+1000;
		if(num[i].head=='Y'&&num[i].dis_grade>80)
		num[i].money=num[i].money+850;
	}
}

bool cmp(const Node &a,const Node &b){
	if(a.money>b.money)
	return 1;
	else if(a.money==b.money&&a.location<b.location)
	return 1;
	return 0;
}


int main(void){
	int N,i,sum=0;
	cin>>N;
	Node *num=new Node[N];
	for(i=0;i<N;i++){
		cin>>num[i].name>>num[i].end_grade>>num[i].dis_grade>>num[i].head>>num[i].west>>num[i].article;
		num[i].location=i;
		num[i].money=0;
	}
	solve(num,N);
	sort(num,num+N,cmp);
	for(i=0;i<N;i++){
		sum=sum+num[i].money;
	}
	cout<<num[0].name<<endl<<num[0].money<<endl<<sum<<endl;
	delete [] num;
	return 0;
}

