#include <iostream>
#include <cmath>
using namespace std;
typedef long long LL;
bool getAns(LL base,LL ex,LL s,LL l){
	LL result = 1;
	while(ex>0){
		if(ex%2==1){
			result = result*base;
			if(result>=l) return true;
		}
		base = base*base;
		if(base>=l) return true;
		ex >>= 1;
	}
	if(s*result<l) return false;
	else return true;
}
int main(){
	int t;
	cin>>t;
	while(t--){
		LL l,d,s,c;
		cin>>l>>d>>s>>c;
		LL base = c+1;
		LL ex = d-1;
		bool ans = getAns(base,ex,s,l);
		if(ans)
			cout<<"ALIVE AND KICKING"<<endl;
		else
			cout<<"DEAD AND ROTTING"<<endl;
	}
	return 0;
}
