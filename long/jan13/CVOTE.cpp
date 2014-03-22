#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<limits>
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	int n,m;
	cin>>n>>m;
	map<string,string> from; //chef and country
	map<string,int> count; // country and votes
	map<string,int> votes; //chef and votes
	string chef,country;
	for(int i=0;i<n;i++){
		cin>>chef>>country;
		from[chef] = country;
	}
	for(int i=0;i<m;i++){
		cin>>chef;
		votes[chef]++;
		count[from[chef]]++;
	}
	map<string,int>::iterator vit = votes.begin();
	map<string,int>::iterator cit = count.begin();
	string ansCountry=(*cit).first,ansChef = (*vit).first;
	int maxCountry=1;
	int maxChef=1;
	for(;cit!=count.end();cit++){
		if((*cit).second>maxCountry){
			maxCountry = (*cit).second;
			ansCountry = (*cit).first;
		}
		else if((*cit).second==maxCountry){
			if((*cit).first<ansCountry)
				ansCountry = (*cit).first;
		}
	}
	for(;vit!=votes.end();vit++){
		if((*vit).second>maxChef){
			maxChef = (*vit).second;
			ansChef = (*vit).first;
		}
		else if((*vit).second==maxChef){
			if((*vit).first<ansChef)
				ansChef = (*vit).first;
		}
	}
	cout<<ansCountry<<endl<<ansChef<<endl;
	return 0;
}

