# include<iostream>
# include<algorithm>
# include<vector>

using namespace std;

const int maxsize=1e5+10;

vector<int> p;
int d1[maxsize];
int d2[maxsize];

void solve(){
	int i,loc;
	int l,r,mid;
	int top1=0,top2=0;
	if(p.size()>0){
		d1[top1]=p[0];//最长不上升子序列 
		d2[top2]=p[0];//最长上升子序列 
	}
	for(i=1;i<p.size();i++){
		if(p[i]<=d1[top1]){//后面的元素要尽可能的小，第一个元素要尽可能的大 
			d1[++top1]=p[i];
		}
		else{
			l=0;
			r=top1;
			while(l<r){
				mid=(l+r)>>1;
				if(d1[mid]<p[i]){
					r=mid;
				}
				else{
					l=mid+1;
				}
			}
			d1[l]=p[i];
		}
		if(p[i]>d2[top2]){//后面的元素要尽可能的大，第一个元素要尽可能的小 
			d2[++top2]=p[i];
		}
		else{
			l=0;
			r=top2;
			while(l<r){
				mid=(l+r)>>1;
				if(d2[mid]<p[i]){
					l=mid+1;
				}
				else{
					r=mid;
				}
			}
			d2[l]=p[i];
		}
		//for(int u=0;u<=top1;u++){
	//	printf("%d ",d1[u]);
	//	}
	//	printf("\n");
	}
	printf("%d\n%d\n",top1+1,top2+1);;
}

int main(void){
	int temp;
	while(scanf("%d",&temp)!=EOF)
		p.push_back(temp);
	solve();
	return 0;
}
