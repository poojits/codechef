#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
using namespace std;
bool isSame(vector<int> &H,vector<int> &D){
	bool same=true;
	for(int i=0;i<H.size();i++){
		if(H[i]!=D[i]){
			same = false;
		}
	}
	return same;
}
int compute(vector<int> &H,vector<int> &D){
	int n = H.size();
	if(n==1){
		if(H[0]<D[0]){
			return -1;
		}
		else{
			return (H[0]-D[0]);
		}
	}
	else if(n==2){
		int sumH = H[0]+H[1];
		int sumD = D[0]+D[1];
		if(sumH == sumD){
			if(H[0]<D[0])
				return D[0]-H[0];
			else
				return H[0]-D[0];
		}
		else{
			return -1;
		}
	}
	else{
		int sumH = 0;
		int sumD = 0;
		for(int i=0;i<n;i++){
			sumD += D[i];
			sumH += H[i];
		}
		if(sumH > sumD){
			return -1;
		}
		else{
			int steps = (sumD-sumH);
			if(steps==0 && isSame(D,H))
				return 0;
			if(steps%(n-2)!=0){
				return -1;
			}
			else{
				steps /= (n-2);
			}
			for(int i=0;i<n;i++){
				int val = H[i]-D[i]+steps;
				if(val%2==1|| val < 0){
					return -1;
				}
			}
			return steps;
		}
	}
}
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int n;
		scanf("%d",&n);
		vector<int> H(n);
		vector<int> D(n);
		for(int i=0;i<n;i++){
			scanf("%d",&H[i]);
		}
		for(int i=0;i<n;i++){
			scanf("%d",&D[i]);
		}
		cout<<compute(H,D)<<endl;
	}
	return 0;
}
