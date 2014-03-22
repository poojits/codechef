#include <cstdio>
#include <cmath>
#include <iostream>
#define mod 1000000
typedef long long LL;
bool sorted[mod];
int main(){
	int t,n,i,sign;
	int a,b,c,d;
	LL sum,ans,t1,t2,t3;
	scanf("%d",&t);
	while(t--){
		scanf("%d %d %d %d %d",&n,&a,&b,&c,&d);
		for(i=0;i<mod;i++) sorted[i]=false;
		sorted[d]=true;
		sum=d;
		for(i=1;i<n;i++){
			t1 = a*sum*sum;
			t2 = b*sum;
			t3 = t1+t2;
			sum = (t3+c)%mod;
			sorted[sum] = !sorted[sum];
		}
		ans=0;
		sign=1;
		for(i=mod-1;i>=0;i--){
			if(sorted[i]){
				ans+=(i*sign);
				sign *= -1;
			}
		}
		if(ans<0) ans= -ans;
		printf("%lld\n",ans);
	}
	return 0;
}
