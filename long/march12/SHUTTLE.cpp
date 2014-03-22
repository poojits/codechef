#include<iostream>
#include<vector>
#include<cstdio>
#define limit 10001
#define sqLimit 100
using namespace std;
vector <bool> sieve(limit,true);
int main(){
	sieve[1]=false;
	for(int i=2;i<=sqLimit;i++){
		if(sieve[i]){
			for(int j=2;j*i<limit;j++){
				sieve[i*j]=false;
			}
		}
	}
	int t;
	cin>>t;
	while(t--){
		int num;
		cin>>num;
		int numer=1,denom=1;
		for(int i=2;i<=num;i++){
			if(sieve[i]){
				if(num%i==0){ //is a prime factor
					numer*=(i-1);
					denom*=i;
				}
			}
		}
		int ans=(numer*num)/denom;
		cout<<ans<<endl;
	}
	return 0;
}
