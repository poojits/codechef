#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
using namespace std;
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		double pa;
		scanf("%lf",&pa);
		if(pa<0.5)
			pa = 1.0-pa;
		double pb = 1.0-pa;
		double amt = pa*(2*pb*10000+10000);
		printf("%0.6lf\n",amt);
	}
	return 0;
}
