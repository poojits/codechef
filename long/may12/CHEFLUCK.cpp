#include<iostream>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		int num;
		cin>>num;
		while(num%7!=0){
			num=num-4;
			if(num<0){
				num=-1;
				break;
			}
		}
		cout<<num<<endl;
	}
	return 0;	
}
