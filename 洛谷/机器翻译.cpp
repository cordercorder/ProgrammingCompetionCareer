# include<iostream>
# include<algorithm>
# include<cstring>

using namespace std;

const int maxsize=1005;

int M,N;
int Q[maxsize];
int front,rear;
int temp[maxsize];

void solve(int *&num){
	int i,ans=0;
	front=rear=0;
	memset(temp,0,sizeof(int)*maxsize);
	for(i=0;i<N;i++){
		if(front-rear<M&&!temp[num[i]]){
			temp[num[i]]++;
			Q[front++]=num[i];//��� 
			ans++;
		}
		else if(!temp[num[i]]&&front-rear==M){
			temp[Q[rear]]--;//��βԪ�س��� 
			rear++;//���� 
			Q[front++]=num[i];//��Ԫ����� 
			temp[num[i]]++;//��¼��Ԫ�س��ֵĴ��� 
			ans++;
		}
	}
	cout<<ans<<endl;
}

int main(void){
	int i;
	cin>>M>>N;
	int *num=new int[N];
	for(i=0;i<N;i++)
		cin>>num[i];
	solve(num);
	return 0;
}
