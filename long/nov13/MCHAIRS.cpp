#include <cstdio>
#include <cmath>
#include <vector>
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
	int t;
	scanf("%d",&t);
	while(t--){
		int n;
		scanf("%d",&n);
		int ans = powermod(2,n,mod)-1;
		if(ans<0)
			ans+=mod;
		printf("%d\n",ans);
	}
	return 0;
}
