#include<cstdio>
#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<cstdlib>
using namespace std;
bool equalCount(vector<int> &a,vector<int> &b){
	for(int i=0;i<a.size();i++){
		if(a[i]!=b[i]) return false;
	}
	return true;
}
bool samezero(vector<int> &a,vector<int> &b){
	for(int i=0;i<a.size();i++){
		if((a[i]==0 && b[i]!=0) || (b[i]==0&&a[i]!=0)) return false;
	}
	return true;
}
bool chefsays(vector<int> &a,vector<int> &b){
	if(equalCount(a,b)) return true;
	else if(samezero(a,b)) return false;
	else
		return true;
}
int main(){
	ios_base::sync_with_stdio(false);
	int t;
	cin>>t;
	string a,b;
	vector<int> countA(26,0),countB(26,0);
	while(t--){
		cin>>a>>b;
		for(int i=0;i<a.size();i++){
			int index = a[i]-'a';
			countA[index]++;
		}
		for(int i=0;i<b.size();i++){
			int index = b[i]-'a';
			countB[index]++;
		}
		if(chefsays(countA,countB))
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;
		countA.clear();
		countA.resize(26,0);
		countB.clear();
		countB.resize(26,0);
		
	}
	return 0;
}
