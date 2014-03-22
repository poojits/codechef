#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
	int t,n,k;
	scanf("%d",&t);
	while(t--){
		scanf("%d %d",&n,&k);
		vector<int> numbers(n);
		int sum=0;
		int val;
		for(int i=0;i<n;i++){
			scanf("%d",&val);
			numbers[i] = val;
			sum+=val;
		}
		sort(numbers.begin(),numbers.end());
		int tempsum=0;
		for(int i=0;i<min(k,n-k);i++){
			tempsum+=numbers[i];
		}
		int ans = sum-(tempsum<<1);
		printf("%d\n",ans);
	}
	return 0;
}
