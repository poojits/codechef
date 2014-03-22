#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <stack>
#include <queue>
#include <cstdio>
#include <cmath>
#include <cstdlib>
using namespace std;
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n,m,k;
        priority_queue<int> q;
        scanf("%d %d %d",&n,&m,&k);
        vector<int> initColors(n);
        vector<vector<int> > points(n,vector<int>(m));
        for(int i=0;i<n;i++){
            scanf("%d",&initColors[i]);
        }
        int initVal = 0;
        for(int i=0;i<n;i++){
            int color = initColors[i];
            for(int j=0;j<m;j++){
                scanf("%d",&points[i][j]);
                if(color==j+1) initVal+=points[i][j];
            }
        }
        int cost=0;
        for(int i=0;i<n;i++){
            int initColorVal = points[i][initColors[i]-1];
            int maxVal = -10000;
            for(int j=0;j<m;j++){
                scanf("%d",&cost);
                if(maxVal==-10000)
                    maxVal = points[i][j]-cost-initColorVal;
                else
                    maxVal = max(maxVal,points[i][j]-cost-initColorVal);
            }
            if(q.size()<k) q.push(-maxVal);
            else if (k!=0 && q.size()>=k && -q.top()<maxVal){
                q.pop();
                q.push(-maxVal);
            }                
        }
        int ans=0;
        while(!q.empty()){
            if(-q.top()>0)
                ans+= -q.top();
            q.pop();
        }
        printf("%d\n",initVal+ans);   
    }
    return 0;
}
