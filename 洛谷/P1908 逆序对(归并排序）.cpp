# include<iostream>
# include<cstdio>

using namespace std;

const int maxsize=40005;

int num[maxsize];
int temp[maxsize];
int ans;

void merge(int start,int end,int mid){
	int i=start,j=mid+1,k=start;
	while(i<=mid&&j<=end){
		if(num[i]>num[j]){
			temp[k++]=num[j++];
			ans=mid-i+1+ans;
		}
		else{
			temp[k++]=num[i++];
		}
	}
	while(i<=mid){
		temp[k++]=num[i++];
	}
	while(j<=end){
		temp[k++]=num[j++];
	}
	for(i=start;i<=end;i++){
		num[i]=temp[i];
	}
}

void m_sort(int start,int end){
	int mid;
	if(start<end){
		mid=(start+end)/2;
		m_sort(start,mid);
		m_sort(mid+1,end);
		//cout<<"start="<<start<<"  mid="<<mid<<"  end="<<end<<endl;
		merge(start,end,mid);
	}
}

int main(void){
	int i,n;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&num[i]);
	}
	ans=0;
	m_sort(0,n-1);
	printf("%d\n",ans);
	return 0;
}
