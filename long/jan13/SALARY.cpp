#include<cstdio>
#include<vector>
using namespace std;
int main(){
	int t,n;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		int num,min=10000,sum=0;
		for(int i=0;i<n;i++){
			scanf("%d",&num);
			if(num<min) min=num;
			sum+=num;
		}
		int ans = sum - n*min;
		printf("%d\n",ans);
	}
	return 0;
}
