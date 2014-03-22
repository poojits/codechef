#include<cstdio>
#include<vector>
#define mod 1000000007
using namespace std;
typedef long long LL;
vector<LL> fibonacci;
void precompute(){
	LL sum,summod;
	fibonacci.resize(1000000);
	fibonacci[0] = 1;
	fibonacci[1] = 2;
	for(int i=2;i<fibonacci.size();i++){
		sum = fibonacci[i-1]+fibonacci[i-2];
		summod = sum%mod;
		fibonacci[i] = summod;
	}
}
int noOnesBinary(int num){
	int count=0;
	while(num!=0){
		if(num&1==1) count++;
		num>>=1;
	}
	return count;
}
int main(){
	int t,n,g,ans;
	precompute();
	scanf("%d",&t);
	while(t--){
		scanf("%d %d",&n,&g);
		ans = noOnesBinary(fibonacci[n-1]);
		if(ans==g) printf("CORRECT\n");
		else printf("INCORRECT\n");
	}
	return 0;
}
