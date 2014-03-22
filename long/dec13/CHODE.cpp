#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <cstdlib>
#include <cstdio>
#include <map>
#include <queue>
#include <stack>
using namespace std;
typedef struct hist{
	int index;
	int value;
}hist;
bool mycomp(hist i, hist j){
	if(i.value==j.value)
		return i.index<j.index;
	else
		return i.value<j.value;
}
int main(){
	int t;
	cin>>t;
	cin.ignore();
	while(t--){
		string feng;
		string text;
		getline(cin,feng);
		getline(cin,text);
		vector<hist> count(26);
		for(int i=0;i<count.size();i++){
			count[i].index = i;
			count[i].value=0;
		}
		vector<char> ftext(26);
		for(int i=0;i<text.size();i++){
			if((text[i]>='a' && text[i]<='z')){
				count[text[i]-'a'].value++;
			}
			else if(text[i]>='A' && text[i]<='Z'){
				count[text[i]-'A'].value++;
			}
		}
		sort(count.begin(),count.end(),mycomp);
		vector<int> position(26,0);
		for(int i=0;i<position.size();i++){
			int index = count[i].index;
			position[index] = i;
		}
		char out;
		int index;
		for(int i=0;i<text.size();i++){
			if(text[i]>='a' && text[i]<='z'){
				index = text[i]-'a';
				out = feng[position[index]];
			}
			else if(text[i]>='A' && text[i]<='Z'){
				index = text[i]-'A';
				out = feng[position[index]];
				out = out+'A'-'a';
			}
			else{
				out = text[i];
			}
			cout<<out;
		}
		cout<<endl;
	}
	return 0;
}
