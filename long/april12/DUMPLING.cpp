#include<cstdio>
#include<cmath>
#include<iostream>
using namespace std;
typedef unsigned long long LL;
LL gcd(LL large,LL smaLL){
	if(smaLL==0) return large;
	return gcd(smaLL,large%smaLL);
}
LL a,b,c,d,k,po,shifu,gcdPoShifu,g1,ans;
int t;
int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%lld",&a);
		scanf("%lld",&b);
		scanf("%lld",&c);
		scanf("%lld",&d);
		scanf("%lld",&k);
		po = gcd(max(a,b),min(a,b));
		shifu = gcd(max(c,d),min(c,d));
		gcdPoShifu = gcd(max(po,shifu),min(po,shifu));
		g1 = po/gcdPoShifu;
		if((g1*shifu)/shifu!=g1) ans=0;
		else{
			g1*=shifu;
			ans = k/g1;
		}
		ans=(ans<<1)+1;
		printf("%lld\n",ans);
	}
	return 0;
}
