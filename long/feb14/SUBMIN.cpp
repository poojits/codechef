#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <cmath>
using namespace std;
vector< vector<int> > arr(50,vector<int>(50));
void pre(vector<int> &inp){
	for(int i=0;i<inp.size();i++){
		int mini=inp[i];
		for(int j=i;j<inp.size();j++){
			mini = min(mini,inp[j]);
			arr[i][j] = mini;
		}
	}
}
int foo(int num){
	int count=0;
	for(int i=0;i<arr.size();i++){
		for(int j=0;j<arr[i].size();j++){
			if(arr[i][j]==num) count++;
		}
	}
	return count;
}
int main(){
	int n;
	cin>>n;
	vector<int> inp(n);
	for(int i=0;i<n;i++){
		cin>>inp[i];
	}
	pre(inp);
	int q;
	cin>>q;
	for(int i=0;i<q;i++){
		int num;
		cin>>num;
		cout<<foo(num)<<endl;
	}
	return 0;
}
