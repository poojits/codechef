#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <cmath>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		string a,b;
		cin>>a>>b;
		map<char,int> hasha,hashb;
		for(int i=0;i<a.size();i++){
			hasha[a[i]]++;
		}
		for(int i=0;i<b.size();i++){
			hashb[b[i]]++;
		}
		map<char,int>::iterator it;
		int count=0;
		for(it=hasha.begin();it!=hasha.end();it++){
			if(hashb.find(it->first)!=hashb.end()){
				count+= min(it->second,hashb[it->first]);
			}
		}
		cout<<count<<endl;
	}
	return 0;
}
