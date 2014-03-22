#include<vector>
#include<cstdio>
#include<cmath>
#include<string>
#include<cstdlib>
#include<iostream>
#include<algorithm>
typedef long long int LL;
using namespace std;
LL modPow(LL a,LL x, LL p){ //compute a^x % p in log x time
	LL res =1;
	while(x>0){
		if(x%2!=0){
			res=(res*a)%p;
		}
		a=(a*a)%p;
		x=x>>1;
	}
	return res;
}
LL modInverse(LL a,LL p){
	return modPow(a,p-2,p);
}
LL factorialMod(LL num,LL mod){
	LL ans = 1;
	for(LL i=2;i<=num;i++)
		ans = (ans*i)%mod;
	return ans;
}
LL ncr(LL n,LL r, LL mod){
	LL nminusr = factorialMod(n-r,mod);
	LL rfact = factorialMod(r,mod);
	return (((factorialMod(n,mod)*modInverse(nminusr,mod))%mod)*modInverse(rfact,mod))%mod;
}
int main(){
	int t,n,temp;
	scanf("%d",&t);
	LL ans,mod=1000000007;
	while(t--){
		scanf("%d",&n);
		for(int i=0;i<n;i++)
			scanf("%d",&temp);
		if(n%2!=0){
			ans=1;
			ans = modPow(2,n-1,mod);
		}
		else{
			ans = 1;
			ans = modPow(2,n,mod);
			ans -= ncr(n,n>>1,mod);
			if(ans<0)
				ans+=mod;
			ans = (ans*modInverse(2,mod))%mod;
		}
		cout<<ans<<endl;
	}
	return 0;
}
