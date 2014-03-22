#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
using namespace std;
bool isOverlucky(int num){
	int digit;
	while(num!=0){
		digit = num%10;
		if(digit==4||digit==7)
			return true;
		num/=10;
	}
	return false;
}
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int num;
		int count=0;
		scanf("%d",&num);
		int sqRoot = sqrt(num);
		for(int i=1;i<=sqRoot;i++){
			if(num%i==0){
				if(isOverlucky(i)){
					count++;
				}
				if(isOverlucky(num/i)){
					count++;
				}
			}
		}
		if(sqRoot*sqRoot==num && isOverlucky(sqRoot)){
			count--;
		}
		printf("%d\n",count);
	}
	return 0;
}
