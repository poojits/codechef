#include <cstdio>
#include <vector>
#include <string>
#include <map>
#include <iostream>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		vector<int> count(26,0);
		string inp;
		cin>>inp;
		for(int i=0;i<inp.size()>>1;i++){
			count[inp[i]-'a']++;
		}
		int start;
		if(inp.size()%2==0)
			start=inp.size()>>1;
		else
			start=(inp.size()>>1)+1;
		for(int i=start;i<inp.size();i++){
			count[inp[i]-'a']--;
		}
		bool flag=true;
		for(int i=0;i<count.size();i++){
			if(count[i]!=0){
				flag=false;
				break;
			}
		}
		if(!flag){
			cout<<"NO"<<endl;
		}
		else
			cout<<"YES"<<endl;
	}
	return 0;
}
