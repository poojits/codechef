#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		vector<int> numbers(n);
		for(int i=0;i<n;i++){
			cin>>numbers[i];
		}
		sort(numbers.begin(),numbers.end());
		int mini = numbers[1]-numbers[0];
		int val;
		for(int i=2;i<n;i++){
			val = numbers[i]-numbers[i-1];
			if(val<mini) mini=val;
		}
		cout<<mini<<endl;
	}
	return 0;
}
