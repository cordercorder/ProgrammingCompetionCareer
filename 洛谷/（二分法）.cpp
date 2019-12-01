# include<iostream>
# include<algorithm>

using namespace std;

const int maxsize=100005;

int num[maxsize];
int n,m;

bool check(int lim){
	int cnt=0,i=0;
	while(i<n){
		cnt++;//记录当前距离可用瓶盖的数量
		i=lower_bound(num,num+n,num[i]+lim)-num;
	}
	
}

int main(void){
	int i;
	int l,r,mid;
	scanf("%d %d",&n,&m);
	for(i=0;i<n;i++){
		scanf("%d",&num[i]);
	}
	sort(num,num+n);
	l=num[0],r=num[n-1];
	while(l<r){
		mid=(l+r)>>1;
		if(check(mid)){
			l=mid;
		}
		else{
			r=mid-1;
		}
	}
	return 0;
} 
