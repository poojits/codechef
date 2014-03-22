#include<iostream>
#include<vector>
#include<string>
#include<stack>
#include<cstdlib>
#include<cstdio>
#include<cmath>
#include<map>
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	int num,n,k,ans=0;
	map<int,int> index;
	cin>>n>>k;
	for(int i=0;i<n;i++){
		cin>>num;
		if(index.count(num)>0){
			if(i-index[num]>=k){
				index[num] = i;
				ans++;
			}
		}
		else{
			index[num] = i;
			ans++;
		}
	}
	cout<<ans<<endl;
	return 0;
}
