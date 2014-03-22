#include<cstdio>
#include<vector>
#define limit 10000000

using namespace std;

enum clas{EVEN,ODD,PRIME,DONE};

vector<bool> isPrime;
vector<vector<int> > mat;
vector<vector<clas> > flags;
vector<int> numPrimes;

void gridHack(int i,int j,int n,clas type){
	if(i<0||j<0||j>n-1||i>n-1) return;
	if(flags[i][j]!=type) return;
	flags[i][j] = DONE;
	gridHack(i,j+1,n,type);
	gridHack(i+1,j,n,type);
	gridHack(i,j-1,n,type);
	gridHack(i-1,j,n,type);
}

void initSieve(){
	int counter=0;
	isPrime.resize(limit,true);	
	numPrimes.resize(limit);
	numPrimes[2]=counter++;
	isPrime[0]=isPrime[1]=false;
	for(int i=4;i<isPrime.size();i+=2)	isPrime[i] = false;
	for(int i=3;i<isPrime.size();i+=2){
        if(isPrime[i]){
			numPrimes[i] = counter++;
            for(int j=2;i*j<isPrime.size();j++){
                isPrime[i*j]=false;
            }
        }
    }
}

int main(){
	int t,n,num;
	initSieve();
	mat.resize(350,vector<int>(350));
	flags.resize(350,vector<clas>(350));
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				scanf("%d",&num);
				mat[i][j]=num;
				if(isPrime[num]){ //Prime
					flags[i][j] = PRIME;
				}
				else if(num%2==0){ //Even
					flags[i][j] = EVEN;
				}
				else
					flags[i][j] = ODD;
			}
		}
		long long ans = 0;
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				if(flags[i][j] == PRIME){
					ans += (long long)numPrimes[mat[i][j]];
				}
				else if(flags[i][j] == EVEN){
					ans += (long long)mat[i][j]>>1;
					gridHack(i,j,n,EVEN);
				}
				else if(flags[i][j] == ODD){
					ans +=  (long long)(((mat[i][j]+1)>>1)+1);
					gridHack(i,j,n,ODD);
				}
			}
		}
		printf("%lld\n",ans);	
	}
}
