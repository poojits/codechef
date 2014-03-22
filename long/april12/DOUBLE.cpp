#include<cstdio>
typedef long long int LL;
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		LL num;
		scanf("%lld",&num);
		if(num%2==1) num--;
		printf("%lld\n",num);
	}
	return 0;
}
