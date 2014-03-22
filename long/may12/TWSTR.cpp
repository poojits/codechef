#include<cstdio>
#include<cstring>
using namespace std;
typedef struct{
	char name[1001];
	int p;
}recipe_t;
inline void lookup(char *query,recipe_t *recipe,int n,char *ans){
	int max=-1000000000;
	strcpy(ans,"NO");
	for(int i=0;i<n;i++){
		if(strncmp(recipe[i].name,query,strlen(query))==0){
			if(recipe[i].p>max){
				max=recipe[i].p;
				strcpy(ans,recipe[i].name);
			}
		}
	}
}
int main(){
	int n;
	scanf("%d",&n);
	recipe_t recipe[n];
	for(int i=0;i<n;i++) scanf("%s %d",recipe[i].name,&recipe[i].p);
	int q;
	scanf("%d",&q);
	while(q--){
		char query[1001];
		scanf("%s",query);
		char ans[1001];
		lookup(query,recipe,n,ans);
		printf("%s\n",ans);
	}
	return 0;
}
