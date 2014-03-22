#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <cstdio>
#include <map>
#include <stack>
#include <queue>
#define mod 1000000
typedef long long LL;
using namespace std;
int main(){
	int t,n;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		LL st=0;
		LL num;
		for(int i=0;i<n;i++){
			scanf("%lld",&num);
			if(st<num) st+=(num-st);
			st--;
		}
		printf("%lld\n",st+n);
	}
	return 0;
}
