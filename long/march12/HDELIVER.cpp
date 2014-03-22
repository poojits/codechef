#include<iostream>
#include<cstdio>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<algorithm>
#define pb push_back
typedef long long int LL;
using namespace std;
inline void bfs(bool graph[100][100],int &s,int &n,bool reach[100][100]){
	queue <int> q;
	q.push(s);
	reach[s][s] = true;
        while(!q.empty()){
	      	int node = q.front();
	      	q.pop();
               	for(int i=0;i<n;i++){
               		if(i!=s&&graph[node][i]){
               			if(!reach[s][i]){
               				reach[s][i]=true;
               				q.push(i);
               			}
               		}
               	}
        }
}
int main(){
        int t,n,m;
        scanf("%d",&t);
        while(t--){
                scanf("%d %d",&n,&m);
                bool graph[100][100];
                bool reach[100][100];
                for(int i=0;i<n;i++){
                        for(int j=0;j<n;j++){
                                graph[i][j]=false;
                                reach[i][j]=false;
                        }
                }
                while(m--){
                        int x1,x2;
                        scanf("%d %d",&x1,&x2);
                        graph[x1][x2]=true;
                        graph[x2][x1]=true;
                }
                int q;
                scanf("%d",&q);
                for(int i=0;i<n;i++)	bfs(graph,i,n,reach);
                while(q--){
                        int x1,x2;
                        scanf("%d %d",&x1,&x2);
                        if(reach[x1][x2]) printf("YO\n");
                        else printf("NO\n");
                }
        }
        return 0;
}
