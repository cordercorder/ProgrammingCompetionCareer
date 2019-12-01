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

const int maxsize=1e5+10;
const int maxw=1e9+10; 

struct node{
	string s;
	int cost;
	int g;
	bool operator<(const node &a)const{
		if(s<a.s)
			return 1;
		return 0;
	}
};

int n,k,m;
node a[maxsize];
vector<int> s[maxsize];
int num[maxsize];
string str[maxsize];

bool cmp(const node &a,const node &b){
	return a.cost<b.cost;
}

int main(void){
	int Min;
	int x;
	int id,pos;
	node tmp;
	tmp.g=-1;
	tmp.cost=-1;
	ll ans;
	while(scanf("%d %d %d",&n,&k,&m)!=EOF){
		for(int i=1;i<=n;i++)
			cin>>a[i].s;
		for(int i=1;i<=n;i++)
			scanf("%d",&a[i].cost);
		for(int i=1;i<=k;i++){
			scanf("%d",&x);
			Min=maxw;
			while(x--){
				scanf("%d",&id);
				a[id].g=i;
				if(a[id].cost<Min){
					Min=a[id].cost;
				}
			}
			num[i]=Min;
		}
		sort(a+1,a+1+n); 
		ans=0;
		for(int i=0;i<m;i++){
			cin>>tmp.s;
			pos=lower_bound(a+1,a+n+1,tmp)-a-1;
			//cout<<"g=="<<a[pos+1].g<<endl;
			//cout<<"###=="<<num[a[pos+1].g]<<endl;
			ans+=num[a[pos+1].g];
		}
		printf("%lld\n",ans);
	}
	return 0;
}
