#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <deque>
#include <limits>
using namespace std;
class SegmentTree{
	private:
		int elements;
		int height;
		int beginIndex;
		int endIndex;
		vector<int> segment_tree;
		int initializeMIN(vector<int> &a,int node,int begin,int end){
			if(begin==end)
				segment_tree[node] = a[begin];
			else{
				int mid = begin + (end-begin)/2; //New Error encountered, when 0>>1, so using this. Good find.
				int newNode = node<<1;
				segment_tree[node] = min(
					initializeMIN(a,newNode+1,begin,mid),
					initializeMIN(a,newNode+2,mid+1,end)
				);
			}
			return segment_tree[node];
		}
		int initializeMAX(vector<int> &a,int node,int begin,int end){
			if(begin==end)
				segment_tree[node] = a[begin];
			else{
				int mid = begin + (end-begin)/2;
				int newNode = node<<1;
				segment_tree[node] = max(
					initializeMAX(a,newNode+1,begin,mid),
					initializeMAX(a,newNode+2,mid+1,end)
				);
			}
			return segment_tree[node];
		}
		int RMQMIN(int segBegin,int segEnd,int queryBegin,int queryEnd,int node){
			if(queryBegin > segEnd || queryEnd < segBegin)
				return numeric_limits<int>::max();
			if(segBegin >= queryBegin && segEnd <= queryEnd)
				return segment_tree[node];
			int mid = segBegin + (segEnd-segBegin)/2;
			int newNode = node<<1;
			return min(
				RMQMIN(segBegin,mid,queryBegin,queryEnd,newNode+1),
				RMQMIN(mid+1,segEnd,queryBegin,queryEnd,newNode+2)
			);
		}
		int RMQMAX(int segBegin,int segEnd,int queryBegin,int queryEnd,int node){
			if(queryBegin > segEnd || queryEnd < segBegin)
				return numeric_limits<int>::min();
			if(segBegin >= queryBegin && segEnd <= queryEnd)
				return segment_tree[node];
			int mid = segBegin + (segEnd-segBegin)/2;
			int newNode = node<<1;
			return max(
				RMQMAX(segBegin,mid,queryBegin,queryEnd,newNode+1),
				RMQMAX(mid+1,segEnd,queryBegin,queryEnd,newNode+2)
			);
		}
	public:
		SegmentTree(vector<int> &a,bool minimum){
			this->elements = a.size();
			this->height = (int)ceil(log2(this->elements));
			int max_size = (((int)pow(2,this->height))<<1)-1;
			this->segment_tree.resize(max_size);
			if(minimum)
				initializeMIN(a,0,0,this->elements-1);
			else
				initializeMAX(a,0,0,this->elements-1);
		}
		int RMQ(int queryBegin,int queryEnd,bool minimum){
			if(minimum)
				return RMQMIN(0,this->elements-1,queryBegin,queryEnd,0);
			else
				return RMQMAX(0,this->elements-1,queryBegin,queryEnd,0);
		}
};
int main(){
	ios_base::sync_with_stdio(false);
	int n,b,q,l,r;
	scanf("%d",&n);
	vector<int> matches(n);
	for(int i=0;i<n;i++){
		scanf("%d",&matches[i]);
	}
	SegmentTree minTree(matches,true);
	SegmentTree maxTree(matches,false);
	scanf("%d",&q);
	for(int i=0;i<q;i++){
		scanf("%d %d",&l,&r);
		int minMatch = minTree.RMQ(l,r,true);
		int maxMatch = maxTree.RMQ(l,r,false);
		double time1 = minMatch + ((double)(maxMatch-minMatch))/2;
		maxMatch = 0;
		if(l==0 && r!=matches.size()-1){
			maxMatch = maxTree.RMQ(r+1,matches.size()-1,false);
		}
		else if(l!=0 && r==matches.size()-1){
			maxMatch = maxTree.RMQ(0,l-1,false);
		}
		else if(l!=0 && r!=matches.size()-1){
			maxMatch = max(
				maxTree.RMQ(0,l-1,false),
				maxTree.RMQ(r+1,matches.size()-1,false)
			);
		}
		double maxTime = max((double)minMatch+maxMatch,time1);
		printf("%0.1f\n",maxTime);
	}
	return 0;
}
