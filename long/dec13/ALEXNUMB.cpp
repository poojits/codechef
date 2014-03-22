#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <cstdlib>
#include <cstdio>
#include <map>
#include <queue>
#include <stack>
using namespace std;
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		long long n;
		scanf("%lld",&n);
		int dum;
		for(int i=0;i<n;i++)
			scanf("%d",&dum);
		long long ans = n*(n-1)>>1;
		cout<<ans<<endl;
	}
	return 0;
}
