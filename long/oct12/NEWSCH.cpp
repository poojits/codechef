#include<cstdio>
#include<cmath>
#include<vector>
#include<iostream>
#include<stack>
#include<queue>
#include<algorithm>
#include<map>
#include<deque>
#include<string>
#include<cstdlib>
#define mod 1000000007
#define sint(n) scanf("%d",&n)
typedef long long LL;
LL getAns(int num){
	LL base = 3;
	LL result=1;
	int offset = (num%2==0)?3:-3;
	while(num>0){
		if(num%2==1)
			result = (result * base)%mod;
		base = (base * base)%mod;
		num=num>>1;
	}
	return (result+offset)%mod;
}
int main(){
	int t,num,ans;
	sint(t);
	while(t--){
		sint(num);
		ans = getAns(num);
		printf("%d\n",ans);
	}
	return 0;
}

