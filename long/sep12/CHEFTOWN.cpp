#include<iostream>
#include<cstdio>
#include<climits>
#include<vector>
#include<queue>
#include<deque>
#include<string>
using namespace std;
typedef long long LL;
int main(){
	ios_base::sync_with_stdio(false);
	int n,m;
	cin>>n>>m;
	vector<int> arr(n);
	int total=0;
	long long sum=0, minimum,maximum;
	int indexMin,indexMax;
	for(int i=0;i<n;i++) cin>>arr[i];
	deque<int> minQ, maxQ;
	for(int i=0;i<m;i++){
		while(!minQ.empty() && arr[i] <= arr[minQ.back()]) minQ.pop_back();
		while(!maxQ.empty() && arr[i] >= arr[maxQ.back()]) maxQ.pop_back();
		minQ.push_back(i);
		maxQ.push_back(i);
		sum += arr[i];
	}
	LL seriesSum;
	for(int i=m;i<n;i++){
		minimum = arr[minQ.front()];
		maximum = arr[maxQ.front()];
		if(minimum+m-1==maximum){
			seriesSum = (((minimum<<1)+(m-1))*m)>>1;
			if(sum==seriesSum)	total++;
		}
		sum += (arr[i] - arr[i-m]);
		while(!minQ.empty() && arr[i] <= arr[minQ.back()]) minQ.pop_back();
		while(!maxQ.empty() && arr[i] >= arr[maxQ.back()]) maxQ.pop_back();
		while(!minQ.empty() && minQ.front() <= i-m) minQ.pop_front();
		while(!maxQ.empty() && maxQ.front() <= i-m) maxQ.pop_front();
		minQ.push_back(i);
		maxQ.push_back(i);
	}
	minimum = arr[minQ.front()];
	maximum = arr[maxQ.front()];
	if(minimum+m-1==maximum){
		seriesSum = (((minimum<<1)+(m-1))*m)>>1;
		if(sum==seriesSum)	total++;
	}
	cout<<total<<endl;
	return 0;
}
