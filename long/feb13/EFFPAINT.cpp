#include<cstdio>
#include<vector>
#include<string>
#include<iostream>
using namespace std;
int main(){
    int n;
    int black=0;
    int white=0;
    scanf("%d",&n);
    vector<string> canvas(n);
    for(int i=0;i<n;i++){
        cin>>canvas[i];
        for(int j=0;j<n;j++){
            char ch = canvas[i][j];
            if(ch=='B') black++;
            else white++;
        }
    }
    if(white>=black){
        printf("%d\n",black);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(canvas[i][j]=='B')
                    printf("%d %d %d %d B\n",i,j,i,j);
            }
        }
    }
    else{
        printf("%d\n",white+1);
        printf("0 0 %d %d F\n",n-1,n-1);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(canvas[i][j]=='W')
                    printf("%d %d %d %d W\n",i,j,i,j);
            }
        }
    }
    return 0;
}