#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	int t,n;
	cin>>t;
	string a,b,child;
	while(t--){
		cin>>a>>b>>n;
		vector<int> count(26,0);
		for(int i=0;i<a.size();i++){
			int loc = a[i]-'a';
			count[loc]++;
		}
		for(int i=0;i<b.size();i++){
			int loc = b[i]-'a';
			count[loc]++;
		}
		for(int i=0;i<n;i++){
			cin>>child;
			for(int j=0;j<child.size();j++){
				int loc = child[j]-'a';
				count[loc]--;
			}
		}
		bool flag = true;
		for(int i=0;i<count.size();i++){
			if(count[i]<0){
				flag = false;
				break;
			}
		}
		if(!flag)
			cout<<"NO"<<endl;
		else
			cout<<"YES"<<endl;
	}
	return 0;
}
