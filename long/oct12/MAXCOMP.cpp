#include<iostream>
#include<cmath>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
typedef struct{
	int start;
	int end;
	int com;
}job;
bool compEnd(job a,job b){ return a.end<b.end;}
int main(){
	int t,n;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		vector<job> jobs(n);
		for(int i=0;i<n;i++){
			scanf("%d%d%d",&jobs[i].start,&jobs[i].end,&jobs[i].com);
		}
		sort(jobs.begin(),jobs.end(),compEnd);
		vector< vector<int> > dp (n+1,vector<int>(49,0));
		for(int i=1;i<=n;i++){
			for(int t=0;t<=48;t++){
				int duration = jobs[i-1].end - jobs[i-1].start;
				int tnew = min(t,jobs[i-1].end) - duration;
				if(tnew<0 || tnew<jobs[i-1].start)
					dp[i][t] = dp[i-1][t];
				else
					dp[i][t] = max(dp[i-1][t],jobs[i-1].com+dp[i-1][tnew]);
			}
		}
		cout<<dp[n][48]<<endl;
	}
	return 0;
}
