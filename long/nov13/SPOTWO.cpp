#include <cstdio>
#include <cmath>
#define mod 1000000007
#define totient 1000000006
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
int convertWithMod(LL n){
	int dig;
	LL decimal=0,place=1;
	while(n!=0){
		dig = n%2;
		decimal = (decimal + (place*dig)%totient)%totient;
		place = (place * 10)%totient;
		n >>= 1;
	}
	return decimal;
}
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int n;
		scanf("%d",&n);
		int n_bin = convertWithMod(n);
		LL ans = powermod(2,n_bin,mod);
		ans = (ans*ans)%mod;
		printf("%lld\n",ans);
	}
	return 0;
}
