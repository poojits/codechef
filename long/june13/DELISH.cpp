#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
template <class T>
T abs(T val){
	if(val < 0)
		return -1*val;
	else
		return val;
}
using namespace std;
typedef long long LL;
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int n;
		scanf("%d",&n);
		vector<LL> delite(n);
		for(int i=0;i<n;i++){
			scanf("%lld",&delite[i]);
		}
		vector<LL> maxSoFarL(n);
		vector<LL> minSoFarL(n);
		vector<LL> maxSoFarR(n);
		vector<LL> minSoFarR(n);
		//vector<LL> maxEndingHere(n);
		//LL maxSoFar=delite[0];
		LL maxEndingHereL = delite[0];
		LL minEndingHereL = delite[0];
		maxSoFarL[0] = delite[0];
		minSoFarL[0] = delite[0];

		LL maxEndingHereR = delite[n-1];
		LL minEndingHereR = delite[n-1];
		maxSoFarR[n-1] = delite[n-1];
		minSoFarR[n-1] = delite[n-1];

		for(int i=1;i<n;i++){
			maxEndingHereL = max(delite[i],maxEndingHereL+delite[i]);
			maxSoFarL[i] = max(maxSoFarL[i-1],maxEndingHereL);
			minEndingHereL = min(delite[i],minEndingHereL+delite[i]);
			minSoFarL[i] = min(minSoFarL[i-1],minEndingHereL);
		}
		for(int i=n-2;i>=0;i--){
			maxEndingHereR = max(delite[i],maxEndingHereR+delite[i]);
			maxSoFarR[i] = max(maxSoFarR[i+1],maxEndingHereR);
			minEndingHereR = min(delite[i],minEndingHereR+delite[i]);
			minSoFarR[i] = min(minSoFarR[i+1],minEndingHereR);
		}
		LL diff1 = max(abs(maxSoFarL[0]-minSoFarR[1]),abs(minSoFarL[0]-maxSoFarR[1]));
		LL diff2 = diff1;
		for(int i=1;i<n-1;i++){
			diff1 = max(abs(maxSoFarL[i]-minSoFarR[i+1]),abs(minSoFarL[i]-maxSoFarR[i+1]));
			diff2 = max(diff1,diff2);
		}
		printf("%lld\n",diff2);
	}
	return 0;
}
