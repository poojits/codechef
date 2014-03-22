#include<iostream>
#include<vector>
#include<string>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		string j,s;
		cin>>j>>s;
		int ans=0;
		vector<int> charOfJ(52,0);
		vector<int> charOfS(52,0);
		for(int i=0;i<j.size();i++){
			int index = (j[i]<95)?j[i]-'A'+26:j[i]-'a';
			charOfJ[index]++;
		}
		for(int i=0;i<s.size();i++){
			int index = (s[i]<95)?s[i]-'A'+26:s[i]-'a';
			charOfS[index]++;
		}
		for(int i=0;i<52;i++){
			if(charOfJ[i]>0) ans+=charOfS[i];
		}
		cout<<ans<<endl;
	}
	return 0;
}
