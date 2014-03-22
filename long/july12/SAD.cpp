#include<iostream>
#include<cstdio>
#include<vector>
#include<cmath>
#include<cstdlib>
using namespace std;
typedef unsigned short us;
us r,c;
int mat[100][100];
int getMax(us col){
	int Tmax = mat[0][col];
	for(us i=1;i<r;i++){
		if(mat[i][col] >Tmax)
			Tmax = mat[i][col];
	}
	return Tmax;
}
int getMin(us row){
	int Tmin = mat[row][0];
	for(us i=1;i<c;i++){
		if(mat[row][i]<Tmin)
			Tmin = mat[row][i];
	}
	return Tmin;
}
int main(){
	ios_base::sync_with_stdio(false);
	cin>>r>>c;
	int Rmin,Cmax;
	for(us i=0;i<r;i++)
		for(us j=0;j<c;j++)
			cin>>mat[i][j];
	vector<int> maxi(c,-1);
	for(us i=0;i<r;i++){
		Rmin = getMin(i);
		for(us j=0;j<c;j++){
			Cmax = (maxi[j]==-1)?getMax(j):maxi[j];
			if(Rmin==Cmax){
				cout<<Rmin<<endl;
				exit(0);
			}
		}
	}
	cout<<"GUESS"<<endl;
	return 0;
	
}
