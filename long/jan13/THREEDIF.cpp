#include<stdio.h>
#define mod 1000000007
typedef long long LL;

int main(){
    int t;
    LL n1,n2,n3,ans;
    scanf("%d",&t);
    while(t--){
        scanf("%lld%lld%lld",&n1,&n2,&n3);
        if(n1<=n2 && n2<=n3){
            ans = ((((n1%mod)*((n2-1)%mod))%mod)*((n3-2)%mod))%mod;
        }
        if(n1<=n3 && n3<=n2){
            ans = ((((n1%mod)*((n3-1)%mod))%mod)*((n2-2)%mod))%mod;
        }
        if(n2<=n1 && n1<=n3){
            ans = ((((n2%mod)*((n1-1)%mod))%mod)*((n3-2)%mod))%mod;
        }
        if(n2<=n3 && n3<=n1){
            ans = ((((n2%mod)*((n3-1)%mod))%mod)*((n1-2)%mod))%mod;
        }
        if(n3<=n1 && n1<=n2){
            ans = ((((n3%mod)*((n1-1)%mod))%mod)*((n2-2)%mod))%mod;
        }
        if(n3<=n2 && n2<=n1){
            ans = ((((n3%mod)*((n2-1)%mod))%mod)*((n1-2)%mod))%mod;
        }
        printf("%lld\n",ans);
    }
    return 0;
}