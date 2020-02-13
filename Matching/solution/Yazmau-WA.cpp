#include<stdio.h>
#include<iostream>
using namespace std;
int main(){
	int n,a[505],b[505],pos=0,p[505];
	int dir=0,m=0,i,j;
	cin>>n;
	for(i=0;i<n;i++){
		cin>>a[pos]>>b[pos];
		pos++;
	}
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			if(a[i]==b[j])
				break;
		}
		p[i]=j;
	}
	for(i=0;i<n;i++){
		if(dir==0){
			if(i<=p[i]){

			}
			else{
				dir=1;
				m++;
			}
		}
		else if(dir==1){
			if(i<=p[i]){
				dir=0;
				m++;
			}
			else{

			}
		}
	}
	cout<<m<<endl;
	return 0;
}
