#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long int LL;
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int n;
		scanf("%d",&n);
		vector<LL> x(n,0);
		vector<LL> y(n,0);
		for(int i=0;i<n;i++){
			scanf("%lld %lld",&x[i],&y[i]);
		}
		LL ans;
		if(n%2==0){
			sort(x.begin(),x.end());
			sort(y.begin(),y.end());
			LL xMed1 = x[x.size()/2 -1];
			LL yMed1 = y[y.size()/2 -1];
			LL xMed2 = x[x.size()/2];
			LL yMed2 = y[y.size()/2];
			ans=(xMed2-xMed1+1)*(yMed2-yMed1+1);
		}
		else ans=1;
		printf("%lld\n",ans);	
	}
	return 0;
}
