#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
#define fori(i,max) for(i=0;i<max;i++)
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	int n,m,i,j,k;
	cin>>n;
	int adj[n][n];
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			cin>>adj[i][j];
		}
	}
	fori(k,n)
		fori(i,n)
			fori(j,n)
				adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);
	cin>>m;
	int s,g,d;
	fori(i,m){
		cin>>s>>g>>d;
		int actual = adj[s][g]+adj[g][d];
		int better = adj[s][d];
		cout<<actual<<" "<<actual-better<<endl;
	}	
	return 0;
}
