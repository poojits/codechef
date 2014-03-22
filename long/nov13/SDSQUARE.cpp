#include <cstdio>
#include <vector>
#include <cmath>
#include <map>
using namespace std;
typedef long long LL;
bool checkDigits(LL num){
	while(num!=0){
		int dig = num%10;
		if(dig!=0&&dig!=1&&dig!=4&&dig!=9){
			return false;
		}
		num /= 10;
	}
	return true;
}
int main(){
	vector<int> sum(100001,0);
	LL sq;
	for(int i=1;i<sum.size();i++){
		sq = (LL)i*i;
		if(checkDigits(sq))
			sum[i] = sum[i-1]+1;
		else
			sum[i] = sum[i-1];
	}
	int t;
	scanf("%d",&t);
	while(t--){
		LL a,b;
		scanf("%lld %lld",&a,&b);
		int start = ceil(sqrt(a));
		int end = floor(sqrt(b));
		int ans=0;
		if(start<=end){
			if(sum[start]-sum[start-1]!=0)
				ans=sum[end]-sum[start]+1;
			else
				ans=sum[end]-sum[start];
		}
		printf("%d\n",ans);
	}
	return 0;
}
