#include<iostream>
#include<string>
#include<stack>
using namespace std;
typedef struct{
	short i;
	string arr;
}bc;
int main(){
	ios_base::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--){
		short k;
		cin>>k;
		string arr;
		cin>>arr;
		bool valid=true;
		stack<bc> prevQ;
		short start=0;
		for(short i=0;i<arr.size();i++){
			short next = (i==arr.size()-1)?0:i+1; //if last element, set next to 0 else set to i+1
			short prev = (i==0)?arr.size()-1:i-1; //if first element, set prev to len-1 else set to i-1
			if(arr[i]=='?'){ //if char is a ?
				bool updated=false; //to see whether there are options to fill ?
				for(short j=start;j<k;j++){ //iterate over the options
					if(j!=arr[prev]-'0' && j!=arr[next]-'0'){
						arr[i]=j+'0';
						updated=true;
						bc back;
						back.i = i;
						back.arr = arr;
						prevQ.push(back);
						start=0;
						break;
					}
				}
				if(!updated){
					if(prevQ.empty()){
						valid=false;
						break;
					}
					else{
						bc back;
						back = prevQ.top();
						start = arr[back.i]-'0'+1;
						arr = back.arr;
						arr[back.i] = '?';
						i = back.i-1;
						prevQ.pop();

					}
				}
			}
			else if(arr.size()!=1 && (arr[i]==arr[prev] || arr[i]==arr[next])){
				valid=false;
				break;
			}
		}
		if(valid) cout<<arr<<endl;
		else cout<<"NO"<<endl;
	}
	return 0;
}
