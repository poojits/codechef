#include<iostream>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		int n,c,val;
		cin>>n>>c;
		for(int i=0;i<n;i++){
			cin>>val;
			c-=val;
		}
		if(c>=0) cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
	}
	return 0;
}
