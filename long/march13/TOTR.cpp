#include<iostream>
#include<string>
#include<vector>
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	int t,val;
	char p;
	string perm;
	vector<int> perm_map(26);
	cin>>t>>perm;
	for(int i=0;i<perm.size();i++){
		p = perm[i];
		val = p-'a';
		perm_map[i] = val;
	}
	string translate;
	while(t--){
		cin>>translate;
		for(int i=0;i<translate.size();i++){
			char tr = translate[i];
			if(tr>='a'&&tr<='z')
				cout<<(char)(perm_map[tr-'a']+'a');
			else if(tr>='A'&&tr<='Z')
				cout<<(char)(perm_map[tr-'A']+'A');
			else if(tr=='_')
				cout<<' ';
			else cout<<tr;
		}
		cout<<endl;
	}
	return 0;
}
