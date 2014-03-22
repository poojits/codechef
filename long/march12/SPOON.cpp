#include<iostream>
#include<cstdio>
#include<string>
#include<vector>
#define pb push_back
using namespace std;
int dfa[7][5] = {
	1,6,6,6,6,
	1,2,6,6,6,
	1,6,3,6,6,
	1,6,4,6,6,
	1,6,6,5,6,
	5,5,5,5,5,
	1,6,6,6,6
};
int main(){
	int t;
	cin>>t;
	while(t--){
		vector <string> a;
		int r,c;
		cin>>r>>c;
		string line;
		for(int i=0;i<r;i++){
			cin>>line;
			a.pb(line);
		}
		int curr=0;
		for(int i=0;i<r;i++){
			if(curr!=5) curr=0;
			for(int j=0;j<c;j++){
				switch(a[i][j]){
					case 'S':
					case 's': curr = dfa[curr][0];
					break;
					case 'P':
					case 'p': curr = dfa[curr][1];
					break;
					case 'O':
					case 'o': curr = dfa[curr][2];
					break;
					case 'n':
					case 'N': curr = dfa[curr][3];
					default : curr = dfa[curr][4];
				}
			}
		}
		if(curr!=5){
			for(int j=0;j<c;j++){
				if(curr!=5) curr=0;
				for(int i=0;i<r;i++){
					switch(a[i][j]){
						case 'S':
						case 's': curr = dfa[curr][0];
						break;
						case 'P':
						case 'p': curr = dfa[curr][1];
						break;
						case 'O':
						case 'o': curr = dfa[curr][2];
						break;
						case 'n':
						case 'N': curr = dfa[curr][3];
						default : curr = dfa[curr][4];
					}
				}
			}
		}
		if(curr==5) cout<<"There is a spoon!"<<endl;
		else cout<<"There is indeed no spoon!"<<endl;
	}
	return 0;
}
