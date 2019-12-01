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

string str1,str2,str;

int main(void){
	int i;
	while(cin>>str1){
		if(str1.length()<=5000){
			str2=str1;
			reverse(str1.begin(),str1.end());
			str=str1+str2;
			cout<<str<<endl;
		}
		else{
			str2=str1;
			reverse(str1.begin(),str1.end());
			if(str2==str1){
				cout<<str1<<endl;
			}
			else{
			}
		}
	}
	return 0;
}
