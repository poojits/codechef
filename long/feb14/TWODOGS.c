#include <math.h>
#include <stdio.h>
#define min(a,b) a>b?b:a
#define max(a,b) a>b?a:b
int hash[1000000];
int main(){
	int n,k,num,i,ans,loc,temp;
	for(i=0;i<1000000;i++) hash[i]=-1;
	scanf("%d %d",&n,&k);
	for(i=0;i<n;i++){
		scanf("%d",&num);
		loc = num-1;
		if(i>=(n>>1)){
			if(hash[loc]==-1)
				hash[loc] = n-i;
			else
				hash[loc] = min(hash[loc],n-i);
		}
		else{
			if(hash[loc]==-1)
				hash[loc] = i+1;
			else
				hash[loc] = min(hash[loc],i+1);
		}
	}
	ans=-1;
	for(i=0;i<1000000;i++){
		if(hash[i]!=-1){
			num = k - i - 1;
			loc = num-1;
			if(loc<0 || i+1 == num) continue;
			if(hash[loc]!=-1){
				temp = max(hash[i],hash[loc]);
				if(ans==-1){
					ans = temp;
				}
				else{
					ans = min(ans,temp);
				}
			}
		}
	}
	printf("%d\n", ans);
	return 0;
}