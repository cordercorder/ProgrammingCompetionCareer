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

# define deb(x) printf("# x=%d\n",x)
# define deb_d(x) printf("# x=%lf\n",x)

typedef long long ll;

using namespace std;

int n; 
string in;
string pr,h,por,path;

void solve(){
	int i,pos,tmp,tmp1;
	pos=in.find("://");
	tmp=pos;
	cout<<"Protocol = "<<in.substr(0,pos)<<endl;
	pos=in.find(':',pos+3);
	tmp1=pos;
	if(pos==string::npos){
		pos=in.find('/',tmp+3);
		if(pos==string::npos){
			cout<<"Host     = "<<in.substr(tmp+3,60)<<endl;
			cout<<"Port     = <default>"<<endl;
			cout<<"Path     = <default>"<<endl;
			return ;
		}
		else{
			cout<<"Host     = "<<in.substr(tmp+3,pos-tmp-3)<<endl;
			cout<<"Port     = <default>"<<endl;
			cout<<"Path     = "<<in.substr(pos+1,60)<<endl;
			return ;
		}
	}
	else{
		cout<<"Host     = "<<in.substr(tmp+3,pos-tmp-3)<<endl;
		pos=in.find('/',pos);
		if(pos==string::npos){
			cout<<"Port     = "<<in.substr(tmp1+1,60)<<endl;
			cout<<"Path     = <default>"<<endl;
			return ;
		}
		else{
			cout<<"Port     = "<<in.substr(tmp1+1,pos-tmp1-1)<<endl;
			cout<<"Path     = "<<in.substr(pos+1,60)<<endl;
			return ;
		}
	}
}

int main(void){
	int i;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		cin>>in;
		printf("URL #%d\n",i+1);
		solve();
		if(i!=n-1)
			printf("\n");
	}
	return 0;
}
