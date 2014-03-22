#include<iostream>
#include<cstring>
using namespace std;
int main(){
        int t;
        cin>>t;
        while(t--){
                int ans=0;
                string number;
                cin>>number;
                for(int i=0;i<number.length();i++){
                        if(number[i]!='4'&&number[i]!='7') ans++;
                }
                cout<<ans<<endl;
        }
        return 0;
}
