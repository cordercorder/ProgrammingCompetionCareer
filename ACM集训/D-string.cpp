# include<iostream>
# include<string>
# include<algorithm>
# include<cstring>

# define maxsize 100002

using namespace std;

typedef struct S{
	string pre;//前缀 
	string post;//后缀 
	int count;
}S;

	string Dstr[maxsize],temp;
	S str[maxsize];
	char ch[maxsize];
	
bool cmp1(const string &a,const string &b){
	return a>b;
}
	
	
bool cmp2(const char &a,const char &b){
	return a>b;
}

bool Check(const int &x,const int &y){//x为主串序号 
	//cout<<endl<<" 1 "<<"Dstr= "<<Dstr[x]<<endl<<"str= "<<str[y].pre<<" "<<str[y].post<<endl;
	//cout<<"location is"<<Dstr[x].find(str[y].post)<<" "<<"len of the str post"<<str[y].post.length()<<endl;
	if(Dstr[x].length()<str[y].post.length()+str[y].pre.length())
	return 0;
	if(Dstr[x].find(str[y].pre)==0&&((Dstr[x].rfind(str[y].post)+str[y].post.length())==Dstr[x].length()))
	return 1;
	return 0;
}

void compare(const int &N,const int &Q){
	int i,j;
	for(i=0;i<Q;i++){
		for(j=temp.find(str[i].pre[0]);j!=string::npos&&j<N&&str[i].pre<=Dstr[j];j++){
			if(str[i].post[str[i].post.length()-1]==Dstr[j][Dstr[j].length()-1]&&Check(j,i)){
				str[i].count++;
				//cout<<endl<<" 2""Dstr= "<<Dstr[j]<<endl<<"str= "<<str[i].pre<<" "<<str[i].post<<endl;
			}
		}
	}
}

int main(void){
	int T,i,N,Q,j,count;
	cin>>T;
	while(T--){
		cin>>N>>Q;
		for(i=0;i<N;i++){
			cin>>Dstr[i];
			ch[i]=Dstr[i][0];
			//cout<<"ch[i]= "<<ch[i]<<endl;
		}
		count=i;
		for(i=0;i<Q;i++){
			cin>>str[i].pre>>str[i].post;
			str[i].count=0;
		}
		ch[count]='\0';
		sort(ch,ch+count,cmp2);
		temp=ch;
		//cout<<"ch= "<<ch<<endl;
		//cout<<"temp= "<<temp<<endl;
		sort(Dstr,Dstr+N,cmp1);//对主串排序 
		//for(i=0;i<N;i++)
		//cout<<"Dstr= "<<Dstr[i]<<endl;
		//for(i=0;i<Q;i++)
		//cout<<"str= "<<str[i].pre<<" "<<str[i].post<<endl;
		compare(N,Q);
		for(i=0;i<Q;i++)
		cout<<str[i].count<<endl;
		temp.clear();
	}
	return 0;
}
