#include<cstdio>
#include<cmath>
#include<vector>
#include<string>
#include<iostream>
#include<map>
using namespace std;
int main(){
	int t,n;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		int val,citynumber=0;
		string city1,city2;
		vector<int> child(n,-1);
		vector<int> parent(n,-1);
		vector<int> cost(n,0);
		map<string,int> name2num;
		map<int,string> num2name;
		for(int i=0;i<n-1;i++){
			cin>>city1>>city2;
			scanf("%d$",&val);
			if(name2num.find(city1)==name2num.end()){ //not found
				name2num[city1] = citynumber++;
				num2name[citynumber-1] = city1;
			}
			if(name2num.find(city2)==name2num.end()){ //not found
				name2num[city2] = citynumber++;
				num2name[citynumber-1] = city2;
			}
			parent[name2num[city2]] = name2num[city1];
			child[name2num[city1]] = name2num[city2];
			cost[name2num[city1]] = val;
		}
		int start=-1,total=0;
		for(int i=0;i<n;i++){
			if(parent[i]==-1){
				start=i;
				break;
			}
		}
		int count=0;
		while(count!=n-1){
			cout<<num2name[start]<<" "<<num2name[child[start]]<<" "<<cost[start]<<"$"<<endl;
			count++;
			total+=cost[start];
			start=child[start];
		}
		cout<<total<<"$"<<endl;
	}
	return 0;
}
