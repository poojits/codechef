#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>
#include <string>
using namespace std;
int main(){
	int test,row,col;
	cin>>test;
	vector<string> matrix(50);
	while(test--){
		cin>>row>>col;
		for(int i=0;i<row;i++){
			cin>>matrix[i];
		}
		int count = 0;
		for(int i=0;i<row;i++){
			for(int j=0;j<col;j++){
				if(matrix[i][j]=='#') continue;
				int l=0,r=0,t=0,b=0;
				int q = j;
				//get L
				while(q>0){
					if(matrix[i][q-1]=='^'){
						l++;
						q--;
					}
					else
						break;
				}
				q=j;
				//get R
				while(q<col-1){
					if(matrix[i][q+1]=='^'){
						r++;
						q++;
					}
					else
						break;
				}
				int p = i;
				//get T
				while(p>0){
					if(matrix[p-1][j]=='^'){
						t++;
						p--;
					}
					else
						break;
				}
				p=i;
				//get B
				while(p<row-1){
					if(matrix[p+1][j]=='^'){
						b++;
						p++;
					}
					else
						break;
				}
				int prime = min(min(l,r),min(t,b));
				if(prime>1)
					count++;
			}
		}
		printf("%d\n",count);
	}
	return 0;
}
