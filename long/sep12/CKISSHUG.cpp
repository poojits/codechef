#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#define mod 1000000007
using namespace std;
typedef long long LL;
LL powermod(LL base,LL exp,LL modulus){ //in O(log n)
	LL result =1;
	while(exp>0){
		if(exp%2==1){
			result = (result*base)%modulus;
		}
		base = (base*base)%modulus;
		exp = exp>>1;
	}
	return result;
}
int main(){
	ios_base::sync_with_stdio(false);
	int t,n;
	cin>>t;
	while(t--){
		LL ans=1;
		cin>>n;
		if(n%2==0){
			ans = (powermod(2,n>>1,mod)*3)%mod;
			ans -=2;
		}
		else{
			ans = powermod(2,(n+3)>>1,mod);
			ans -=2;
		}
		cout<<ans%mod<<endl;
	}
	return 0;
}
