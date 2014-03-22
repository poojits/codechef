#include<cstdio>
#define gc getchar_unlocked
int diff[1000000],mini,maxi,ans,num;
int i,x,y,z,n,m,t,w;
void scanint(int &x){
    register int c = gc();
    x = 0;
    for(;(c<48 || c>57);c = gc());
    for(;c>47 && c<58;c = gc()) {x = (x<<1) + (x<<3) + c - 48;}
}
int main(){
	scanint(t);
	while(t--){
		scanint(n);
		scanint(m);
		for(i=0;i<n;i++) diff[i]=1;
		for(i=0;i<m;i++){
			scanint(w);scanint(x);scanint(y);scanint(z);
			if(w==2)z=-z;
			diff[x-1]=diff[x-1]+z;diff[y]=diff[y]-z;
		}
		num=maxi=mini=diff[0];
		for(i=1;i<n;i++){
			num=num+diff[i];
			if(num>maxi) maxi=num;
			if(num<mini) mini=num;
		}
		ans=maxi-mini;
		printf("%d\n",ans);
	}
	return 0;
}
