#include<cstdio>
int n;
int DATA[100000];
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(int k=0;k<n;k++) scanf("%d",&DATA[k]);
		int difference=0, min=DATA[0], max=DATA[0], current=0, pos_max=0, max_difference=0;
		while(current<n){
			if(DATA[current]>max) max = DATA[current];
			if(DATA[current] < min ) min = max = DATA[current];
			difference = max - min;
			if(max_difference < difference ) max_difference = difference;
			current++;
		}
		if(max_difference>0) printf("%d\n",max_difference);
		else printf("UNFIT\n");
	}
	return 0;
}
