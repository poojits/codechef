#include<iostream>
#include<cstdio>
#include<string>
#include<vector>
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	int t,n;
	string inp;
	cin>>t;
	while(t--){
		cin>>n>>inp;
		vector<bool> alive(n,true);
		if(inp[0]=='1'){
			alive[0]=false;
			if(n>1)	alive[1]=false;
		}
		for(int i=1;i<n-1;i++){
			if(inp[i]=='1'){
				alive[i]=false;
				alive[i-1]=false;
				alive[i+1]=false;
			}
		}
		if(inp[n-1]=='1'){
			alive[n-1]=false;
			if(n>1)	alive[n-2]=false;
		}
		int count=0;
		for(int i=0;i<n;i++){
			if(alive[i])	count++;
		}
		cout<<count<<endl;
	}
	return 0;
}
