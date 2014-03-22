#include<cstdio>
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int n;
		scanf("%d",&n);
		int n1[n][n],n2[n][n];
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++) scanf("%d",&n1[i][j]);
		}
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++) scanf("%d",&n2[i][j]);
		}
		for(int i=0;i<n;i++) printf("%d ",i+1);
		printf("\n");
		for(int i=0;i<n;i++) printf("%d ",i+1);
		printf("\n");
	}
	return 0;
}
