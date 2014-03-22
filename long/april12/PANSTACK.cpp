#include<iostream>
#include<vector>
#include<cstdio>
#define mod 1000000007
using namespace std;
typedef long long int LL;
LL dp[1001][1001];
int main(){
        for(int i=0;i<=1000;i++){
                for(int j=0;j<=1000;j++){
                        if((i==0&&j==0)||(i==1&&j==1)) dp[i][j]=1;
                        else if((j>i)||(i>0&&j==0)) dp[i][j]=0;
                        else dp[i][j]=((((j%mod)*dp[i-1][j]%mod)%mod)+dp[i-1][j-1]%mod)%mod;
                }
        }
        vector <LL> numbers;
        for(int i=1;i<=1000;i++){
                LL num=0;
                for(int j=1;j<=i;j++)
                        num=(num+dp[i][j])%mod;
                numbers.push_back(num);
        }
        int t;
        scanf("%d",&t);
        while(t--){
                int num;
                scanf("%d",&num);
                printf("%lld\n",numbers[num-1]);
        }
        return 0;
}
