#include<iostream>
#include<cstring>
using namespace std;
bool prm[1111111];
int num[1111111];
void prime(){
	memset (num,0,sizeof(num));
	memset (prm,0,sizeof(prm));
	//prm [i] =1  not prm ;
	prm[0] = prm[1]   =  1;
	   num[0] =  num[ 1] =0;
	   int cnt =0;
	for(int i=2;i<=1000000;i++){
 		if(prm[i]==0){
		 	for(int j = 2*i;j<=1000000;j+=i){
	 			prm[j]=1;
	 			
	 		}
		 	cnt++;
		 }
  		num[i]=cnt;	
	}
}
int main(){
   prime();
   int n;
   while(cin>>n){
   	cout<<num[n]<<endl;
   }	
	
}