# include<iostream>
# include<algorithm>

using namespace std;

typedef struct node{
	int number;
	int score;
}node;

bool cmp(const node &a,const node &b){
	if(a.score>b.score)
	return 1;
	else if(a.score==b.score&&a.number<b.number)
	return 1;
	return 0;
}

int main(void){
	int n,m,i,mx,j;
	cin>>n>>m;
	node *data=new node[n];
	for(i=0;i<n;i++)
		cin>>data[i].number>>data[i].score;
	mx=m*1.5;
	sort(data,data+n,cmp);
	for(i=n-1;i>=0&&data[i].score<data[mx-1].score;i--);
	cout<<data[mx-1].score<<" "<<i+1<<" "<<endl;
	for(j=0;j<=i;j++){
		cout<<data[j].number<<" "<<data[j].score<<" "<<endl;
	}
	return 0;
}
