#include <vector>
#include<string>
#include<cstdio>
#include<map>
using namespace std;
 // Returns sum of elements with indexes a..b, inclusive
vector<int> fCol1,fCol2,fRow1,fRow2;
vector<vector<int> > rowMap;
vector<vector<int> > colMap;
int version=1,n,q;
int query(const vector<int> &tree, int a, int b) {
    if (a == 0) {
        int sum = 0;
        for (; b >= 0; b = (b & (b + 1)) - 1)
          sum += tree[b];
        return sum; 
    } else {
        return query(tree, 0, b) - query(tree, 0, a-1);
    }
}
void set(vector<int> &tree, int k, int inc) {
    for (; k < (int)tree.size(); k |= k + 1)
        tree[k] += inc;
}
void Set(bool isRow,int idx,int value){
	if(isRow){
		int prevValue = rowMap[idx][0];
		int prevVersion = rowMap[idx][1];
		if(prevVersion>0){
			if(prevValue==0)
				set(fRow1,prevVersion,-1);
			else
				set(fRow2,prevVersion,-1);
		}
		rowMap[idx][0] = value;
		rowMap[idx][1] = version;
		if(value==0)
			set(fRow1,version,1);
		else
			set(fRow2,version,1);
	}
	else{
		int prevValue = colMap[idx][0];
		int prevVersion = colMap[idx][1];
		if(prevVersion>0){
			if(prevValue==0)
				set(fCol1,prevVersion,-1);
			else
				set(fCol2,prevVersion,-1);
		}
		colMap[idx][0] = value;
		colMap[idx][1] = version;
		if(value==0)
			set(fCol1,version,1);
		else
			set(fCol2,version,1);
	}
	version++;
}
int Query(bool isRow,int idx){
	int c;
	int value;
	if(isRow){
		value = rowMap[idx][0];
		int row_version = rowMap[idx][1];
		//int c;
		if(1-value ==0){
			c = query(fCol1,row_version+1,version);
		}
		else
			c = query(fCol2,row_version+1,version);
	}
	else{
		value = colMap[idx][0];
		int col_version = colMap[idx][1];
		//int c;
		if(1-value ==0){
			c = query(fRow1,col_version+1,version);
		}
		else
			c = query(fRow2,col_version+1,version);
	}
	if(value==1)
		return n-c;
	else
		return c;
}
int main(){
    scanf("%d %d",&n,&q);
	colMap.assign(n,vector<int>(2,0));
	rowMap.assign(n,vector<int>(2,0));
	fCol1.assign(q+1,0);
	fCol2.assign(q+1,0);
	fRow1.assign(q+1,0);
	fRow2.assign(q+1,0);
    vector<int> fCol1(n,0),fCol2(n,0),fRow1(n,0),fRow2(n,0);
    char command[10];
    int location, value;
    for(int i=0;i<q;i++){
        scanf("%s",command);
        if(command[3]=='Q'){ //query
            scanf("%d",&location);
            if(command[0]=='R')
                printf("%d\n",n-Query(true,location-1)); //true for row
            else 
                printf("%d\n",n-Query(false,location-1));
        }
        else{ //set
            scanf("%d %d",&location,&value);
            if(command[0]=='R')
                Set(true,location-1,value); //true for row
            else
                Set(false,location-1,value);
        }
    }
    return 0;
}