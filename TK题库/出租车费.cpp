# include<iostream>
# include<cmath> 

using namespace std;

int main(void){
	double result,temp,out,n;
	int op;
	while(cin>>n){
		if(n==0)
		break;
		result=0;
		out=(static_cast<int>(n))%8;
		temp=n-out;
		temp=temp/8;
		if(temp<1){//总里程小于8公里时 
			out=(static_cast<int>(n))%4;
			temp=n/4;
			if(temp<=1){
				cout<<"10"<<endl;
				continue;
			}
			printf("%.0lf\n",10+out*2);
			continue;
		}
		if(out<=5){
			result=temp*18+out*2.4;
			op=result;
			if(op==result)
			printf("%.0lf\n",result);
			else
			printf("%.1lf\n",result);
		}
		else{
			result=temp*18+10+(out-4)*2;
			printf("%.0lf\n",result);
		}
	}
	return 0;
}
