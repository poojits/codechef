#include<iostream>
#include<cstdio>
#include<vector>
#include<string>
#include<map>
using namespace std;
int main(){
	int t,n,m,c,l;
	scanf("%d",&t);
	vector<int> sumFloats(100,0);
	while(t--){
		scanf("%d%d",&n,&m);
		for(int i=0;i<n;i++){
			scanf("%d%d",&c,&l);
			sumFloats[l-1]-=c;
		}
		for(int i=0;i<m;i++){
			scanf("%d%d",&c,&l);
			sumFloats[l-1]+=c;
		}
		int ans=0;
		for(int i=0;i<sumFloats.size();i++){
			if(sumFloats[i]>0) ans+= sumFloats[i];
		}
		printf("%d\n",ans);
		sumFloats.clear();
		sumFloats.resize(100,0);
	}
	return 0;
}
