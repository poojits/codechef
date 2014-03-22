#include <iostream>
#include <string>
#include <cmath>
#include <vector>
using namespace std;
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		long long n,k;
		scanf("%lld %lld",&n,&k);
		if(k!=0){
			long long q = n/k;
			long long r = n%k;
			printf("%lld %lld\n",q,r);
		}
		else
			printf("0 %lld\n",n);
	}
	return 0;
}
