#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <cstdlib>
#include <queue>
#include <stack>
using namespace std;
int main(){
	int n;
	scanf("%d",&n);
	vector<int> area(n);
	int ax,ay,bx,by,cx,cy;
	for(int i=0;i<n;i++){
		scanf("%d %d %d %d %d %d",&ax,&ay,&bx,&by,&cx,&cy);
		area[i] = ax*(by-cy) + bx*(cy-ay)+cx*(ay-by);
		area[i] = abs(area[i]);
	}
	int minimum = area[0];
	int maximum = area[0];
	int minIdx=0;
	int maxIdx=0;
	for(int i=1;i<n;i++){
		if(area[i]<= minimum){
			minimum = area[i];
			minIdx = i;
		}
		if(area[i] >= maximum){
			maximum = area[i];
			maxIdx = i;
		}
	}
	printf("%d %d\n",minIdx+1,maxIdx+1);
	return 0;
}
