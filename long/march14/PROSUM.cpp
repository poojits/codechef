#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <cstdio>
#include <map>
#include <stack>
#include <queue>
typedef long long LL;
using namespace std;
int main(){
	int t,n;
	scanf("%d",&t);
	while(t--){
		int count=0,num,count2=0;
		scanf("%d",&n);
		for(int i=0;i<n;i++){
			scanf("%d",&num);
			if(num==2) count2++;
			else if(num!=0 && num!=1) count++;
		}
		count=count+count2;
		LL ans1 = (LL)count*(LL)(count-1);
		LL ans2 = (LL)count2*(LL)(count2-1);
		ans1>>=1;
		ans2>>=1;
		printf("%lld\n",ans1-ans2);
	}
	return 0;
}
