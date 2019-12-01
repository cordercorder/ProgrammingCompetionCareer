# include<iostream>
# include<algorithm>

using namespace std;

typedef struct Node{
	int l;
	int w;
}Node;

bool cmp(const Node &a,const Node &b){
	if(a.l<b.l)
	return 1;
	else if(a.l==b.l&&a.w<b.w)
	return 1;
	return 0;
}

int main(void){
	int T,n,i,j,result,temp;
	cin>>T;
	while(T--){
		cin>>n;
		Node *num=new Node[n];
		for(i=0;i<n;i++)
		cin>>num[i].l>>num[i].w;
		sort(num,num+n,cmp);
		result=0;
		for(i=0;i<n;i++){
			if(num[i].w){
				temp=num[i].w;
				result++;
				for(j=i+1;j<n;j++){
					if(num[j].w>=temp){
						temp=num[j].w;
						num[j].w=0;
					}			
				}	
			}
		}
		cout<<result<<endl;
	}
	return 0;
}
