#include <cstdio>
#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;
typedef struct request{
		int s;
		int f;
}request;
bool reqcompare(request a,request b){
	return a.f<b.f;
}
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int n,k;
		scanf("%d %d",&n,&k);
		map<int,vector<request> > hash;
		int s,f,p;
		for(int i=0;i<n;i++){
			scanf("%d %d %d",&s,&f,&p);
			request r;
			r.s=s;
			r.f=f;
			hash[p].push_back(r);
		}
		int counter=0;
		map<int,vector<request> >::iterator it;
		for(it=hash.begin();it!=hash.end();it++){
			sort(it->second.begin(),it->second.end(),reqcompare);
			int last=0;
			for(int i=0;i<it->second.size();i++){
				if(it->second[i].s>=last){
					counter++;
					last = it->second[i].f;
				}
			}
		}
		printf("%d\n",counter);
	}
	return 0;
}
