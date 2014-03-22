#include <cstdio>
#include <cstring>
using namespace std;
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		char str[100001];
		scanf("%s",str);
		bool flag=false;
		if(strlen(str)>2){
			for(int i=0;i<strlen(str)-2;i++){
				char a=str[i];
				char b=str[i+1];
				char c=str[i+2];
				if((a=='0' && b=='1' && c=='0') || (a=='1' && b=='0' && c=='1')){
					flag=true;
					break;
				}
			}
		}
		if(flag)
			printf("Good\n");
		else printf("Bad\n");
	}
}
