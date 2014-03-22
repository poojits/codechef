#include<string>
#include<iostream>
#include<map>
using namespace std;
int main(){
	int t;
	cin>>t;
	string inp;
	while(t--){
		cin>>inp;
		map<char,int> store;
		for(int i=0;i<inp.size();i++){
			char alpha = inp[i];
			store[alpha]++;
		}
		map<char,int>::iterator it;
		int ans=0;
		for(it=store.begin();it!=store.end();it++){
			ans+= ((*it).second+1)>>1;
		}
		cout<<ans<<endl;
	}
	return 0;
}
