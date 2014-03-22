#include<cstdio>
#include<cmath>
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int n;
		scanf("%d",&n);
		int i,diff,mindiff=n;
		for(i=1;i<=sqrt(n);i++){
			if(n%i==0){ //divi
				diff=n/i-i;
				if(diff>mindiff) break;
				if(diff<mindiff) mindiff=diff;
			}
		}
		printf("%d\n",mindiff);
	}
	return 0;
}
