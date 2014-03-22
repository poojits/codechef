#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
int main(){
	int t;
	vector<short> digits(52,-1);
	int num = 103993;
	int denom = 33102;
	int i=0;
	while(i<digits.size()){
		num = (num%denom) * 10;
		digits[i] = num/denom;
		i++;
	}
	scanf("%d",&t);
	int pri;
	while(t--){
		scanf("%d",&pri);
		printf("3");
		if(pri>0) printf(".");
		for(int i=0;i<min(pri,52);i++){
			printf("%d",digits[i]);
		}
		if(pri>52){
			int rep = (pri-52)/51;
			int alone = (pri-52)%51;
			for(int i=0;i<rep;i++){
				for(int j=1;j<52;j++){
					printf("%d",digits[j]);
				}	
			}
			for(int i=0;i<alone;i++){
				printf("%d",digits[i+1]);
			}
		}
		printf("\n");
	}
	return 0;
}
