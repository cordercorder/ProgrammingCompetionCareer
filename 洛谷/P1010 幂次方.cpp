# include<iostream>
# include<cstring>

using namespace std;

void solve(int n){
	int num[20],count=0,i;
	while(n){
		if(n&1){//n能不被2整除 
			num[count++]=1;
		}
		else{
			num[count++]=0;
		}
		n=n>>1;
	}
	count--;
	for(i=count;i>=0;i--){
		if(num[i]){
			if(i!=count){
				cout<<"+";
			}
			cout<<"2";
			if(i!=1){
				cout<<"(";
				if(i==0){
					cout<<"0";
				}
				else if(i==2){
					cout<<"2";
				}
				else{
					solve(i);
				}
				cout<<")";
			}
		}
	}
}

int main(void){
	int n;
	cin>>n;
	solve(n);
	return 0;
}
