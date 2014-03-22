#include <iostream>
#include <vector>
#include <string>
using namespace std;
bool process(string &m,string &w){
	string smaller,larger;
	if(m.size()<w.size()){
		smaller = m;
		larger = w;
	}
	else{
		smaller = w;
		larger = m;
	}
	int i=0,j=0;
	while(true){
		if(i==smaller.size())
			return true;
		else if(j==larger.size())
			return false;
		if(smaller[i]==larger[j]){
			i++;
			j++;
		}
		else{
			j++;
		}
	}
}
int main(){
	ios_base::sync_with_stdio(false);
	int t;
	string m,w;
	cin>>t;
	while(t--){
		cin>>m>>w;
		if(process(m,w))
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;
	}
	return 0;
}
