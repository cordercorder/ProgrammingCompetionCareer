#include<iostream>
#include<algorithm>
#include<cstring>
#include<string>
#include<cmath>
#include<queue>
#include<stack>
#include<set>
#include<vector>
#include<cstdio>
#include<cstdlib>
#include<map>
#include<deque>
#include<limits.h>
#include<bitset>
#include<ctime>

#define deb(x) cout<<"#---"<<#x<<"=="<<x<<endl

using namespace std;

const long double PI=acos(-1.0); 
const long double eps=1e-6;
const long long maxw=1e17+10;

typedef long long ll;
typedef pair<int,int> pii;
/*head------[@cordercorder]*/

const int maxn=2e4+10;

int n,k,num[maxn];
int sa[maxn],rank[maxn],height[maxn];
int wa[maxn],wb[maxn],wv[maxn],wd[maxn];

bool cmp(int *r,int a,int b,int l){
	return r[a]==r[b]&&(r[a+l]==r[b+l]);
}

void da(int *r,int n,int m){
	int i,j,p,*x=wa,*y=wb,*t;
	for(i=0;i<m;i++){
		wd[i]=0;
	}
	for(i=0;i<n;i++){
		wd[x[i]=r[i]]++;
	}
	for(i=1;i<m;i++){
		wd[i]+=wd[i-1];
	}
	for(i=n-1;i>=0;i--){
		sa[--wd[x[i]]]=i;
	}
	for(j=1,p=1;p<n;j*=2,m=p){
		for(p=0,i=n-j;i<n;i++){
			y[p++]=i;
		}
		for(i=0;i<n;i++){
			if(sa[i]>=j){
				y[p++]=sa[i]-j;
			}
		}
		for(i=0;i<n;i++){
			wv[i]=x[y[i]];
		}
		for(i=0;i<m;i++){
			wd[i]=0;
		}
		for(i=0;i<n;i++){
			wd[wv[i]]++;
		}
		for(i=1;i<m;i++){
			wd[i]+=wd[i-1]; 
		}
		for(i=n-1;i>=0;i--){
			sa[--wd[wv[i]]]=y[i];
		}
		for(t=x,x=y,y=t,p=1,x[sa[0]]=0,i=1;i<n;i++){
			x[sa[i]]=cmp(y,sa[i-1],sa[i],j)?p-1:p++;
		}
	}
}


void calHeight(int *r,int n){
	int i,j,k=0;
	for(i=1;i<=n;i++){
		rank[sa[i]]=i;
	}
	for(i=0;i<n;height[rank[i++]]=k){
		for(k?k--:0,j=sa[rank[i]-1];r[i+k]==r[j+k];k++);
	}
}

bool check(int len){
	int i=2,cnt;
	while(1){
		while(i<=n&&height[i]<len){
			i++;
		}
		if(i>n)
			break;
		cnt=1;
		while(i<=n&&height[i]>=len){
			cnt++;
			i++;
		}
		if(cnt>=k){
			return 1;
		}
	}
	return 0;
}

int main(void){
	scanf("%d %d",&n,&k);
	for(int i=0;i<n;i++){
		scanf("%d",&num[i]);
	}
	num[n]=0;
	da(num,n+1,20000);
	calHeight(num,n);
	int l=1,r=n,mid;
	while(l<r){
		mid=(l+r)>>1;
		if(check(mid)){
			l=mid+1;
		}
		else{
			r=mid;
		}
	}
	if(!check(l)){
		l--;
	}
	printf("%d\n",l);
	return 0;
}
