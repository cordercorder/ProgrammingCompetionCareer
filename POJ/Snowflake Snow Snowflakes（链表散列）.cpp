# include<iostream>
# include<algorithm>
# include<cstring>
# include<string>
# include<cmath>
# include<queue>
# include<stack>
# include<set>
# include<vector>
# include<cstdio>
# include<cstdlib>
# include<map>
# include<deque>

# define deb(x) printf("# x=%d\n",x)
# define deb_d(x) printf("# x=%lf\n",x)
# define ccout(x) printf("%d\n",x)

typedef long long ll;

using namespace std;

const int mod=1e6+9;

const int maxsize=1e6+10;

struct node{
	int a[6];
	node *next;
	bool flag;
	node():next(NULL),flag(0){			};
};

node num[maxsize];
int tmp[6];

int n;

void handle(const int &id){
	node *newnode=new node[1];
	memcpy(newnode->a,tmp,sizeof(tmp));
	newnode->next=num[id].next;
	num[id].next=newnode;
}

bool check_p(const int &id,node *p){
	int cnt;
	int i,j;
	if(p==NULL){
		for(i=0;i<6;i++){
			if(num[id].a[0]==tmp[i]){
				cnt=(i+1)%6;
				for(j=1;j<6;j++){
					if(num[id].a[j]==tmp[cnt]){
						cnt=(cnt+1)%6;
					}
					else
						break;
				}
				if(j==6)
					return 1;
			}
		}
		for(i=0;i<6;i++){
			if(num[id].a[0]==tmp[i]){
				cnt=i-1;
				if(cnt<0)
					cnt+=6;
				for(j=1;j<6;j++){
					if(num[id].a[j]==tmp[cnt]){
						cnt--;
						if(cnt<0)
							cnt+=6;
					}
					else
						break;
				}
				if(j==6)
					return 1;
			}
		}
	}
	else{
		for(i=0;i<6;i++){
			if(p->a[0]==tmp[i]){
				cnt=(i+1)%6;
				for(j=1;j<6;j++){
					if(p->a[j]==tmp[cnt]){
						cnt=(cnt+1)%6;
					}
					else
						break;
				}
				if(j==6)
					return 1;
			}
		}
		for(i=0;i<6;i++){
			if(p->a[0]==tmp[i]){
				cnt=i-1;
				if(cnt<0)
					cnt+=6;
				for(int j=1;j<6;j++){
					if(p->a[j]==tmp[cnt]){
						cnt--;
						if(cnt<0)
							cnt+=6;
					}
					else
						break;
				}
				if(j==6)
					return 1;
			}
		} 
	}
	return 0;
}

bool check(const int &id){
	if(check_p(id,NULL))
		return 1;
	node *p=num[id].next;
	while(p){
		if(check_p(id,p))
			return 1;
		p=p->next;
	}
	handle(id);
	return 0;
}

int main(void){
	bool flag;
	node xx;
	int sum;
	scanf("%d",&n);
	flag=0;
	for(int i=0;i<n;i++){
		sum=0;
		for(int j=0;j<6;j++){
			scanf("%d",&tmp[j]);
		}
		if(flag)
			continue;
		for(int j=0;j<6;j++){
			sum=(sum%mod+tmp[j]%mod)%mod;
		}	
		if(!num[sum].flag){
			num[sum].flag=1;
			for(int j=0;j<6;j++){
				num[sum].a[j]=tmp[j];
			}
		}
		else{
			if(check(sum))
				flag=1;
		}
	}
	if(flag){
		puts("Twin snowflakes found.");
	}
	else{
		puts("No two snowflakes are alike.");
	}
	return 0;
}
