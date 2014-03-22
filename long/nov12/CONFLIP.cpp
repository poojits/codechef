#include<cstdio>
#include<cmath>
#include<vector>
#include<string>
#include<iostream>
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	int t,g,n,i,q,ans;
	cin>>t;
	while(t--){
		cin>>g;
		for(int j=0;j<g;j++){
			cin>>i>>n>>q;
			ans = (n+1)>>1;
			if(i==q)
				cout<<n-ans<<endl;
			else
				cout<<ans<<endl;
		}
	}
	return 0;
}
