#include<vector>
#include<cstdio>
#include<cmath>
#define cin(in) scanf("%d",&in);
using namespace std;
int main(){
	int t,n;
	cin(t);
	while(t--){
		cin(n);
		vector<vector<int> > score(n,vector<int>(n,0));
		vector<vector<int> > path(n,vector<int>(n,0));
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				cin(score[i][j]);
			}
		}
		path[0][0] = score[0][0];
		for(int i=1;i<n;i++){
			path[0][i] = score[0][i]+path[0][i-1];
			path[i][0] = score[i][0]+path[i-1][0];
		}
		for(int i=1;i<n;i++){
			for(int j=1;j<n;j++){
				int currScore = score[i][j];
				int fromTop = path[i-1][j]+currScore;
				int fromLeft = path[i][j-1]+currScore;
				path[i][j] = max(fromTop,fromLeft);
			}
		}
		if(path[n-1][n-1]<0){
			printf("Bad Judges\n");
		}
		else{
			int divisor = (n<<1) -3;
			printf("%.6f\n",(double)path[n-1][n-1]/divisor);
		}
	}
	return 0;
}

