#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
	int t;
	scanf("%d",&t);
	while(t--){
		int n;
		scanf("%d",&n);
		vector<int> songs(n);
		for(int i=0;i<n;i++){
			scanf("%d",&songs[i]);
		}
		int position;
		scanf("%d",&position);
		int songToFind = songs[position-1];
		sort(songs.begin(),songs.end());
		int i;
		for(i=0;i<songs.size();i++){
			if(songs[i]==songToFind)
				break;
		}
		printf("%d\n",i+1);
	}
	return 0;
}
