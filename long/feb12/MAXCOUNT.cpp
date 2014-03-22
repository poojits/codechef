#include<iostream>
#include<vector>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		vector<int> store(10001,0);
		int n;
		cin>>n;
		int num;
		for(int i=0;i<n;i++){
			cin>>num;
			store[num]++;	
		}
		int c=store[10000];
		int v=10000;
		for(int i=9999;i>=1;i--){
			if(store[i]>=c){
				c=store[i];
				v=i;
			}
		}
		cout<<v<<" "<<c<<endl;
	}
	return 0;
}
