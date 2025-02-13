/*Phan chia tai*/

#include <bits/stdc++.h>
using namespace std;
int n; 
int sum=0;

int best= 1e9;

int main(){
	cin>>n;
     int a[21];
	 for (int i=0; i<n; i++) {
	 	cin >> a[i];
	 	sum+=a[i];
	 }
	 // tim ra tai sn thangf 1 qua submask  XOR voi tai san 1+2 => taif snr thangwf 2 => XOR voiws tong => ra tai san thang 3
	  for (int mask =1; mask < (1<<n); mask++){
	  	int sum12=0;
	  	for (int k=0; k<n; k++){
	  		if ( ((mask >> k)&1) == 0) //o vi tri k la 0 
			  {continue;}
			sum12+= a[k];		
			}
			
			int sum3= sum -sum12;
	  	for (int submask= mask; submask>0; submask= (submask-1)&mask ){
	  		 int sum1=0;
			  for (int k=0; k<n; k++){
	  		if ( ((submask >> k)&1) == 0) //o vi tri k la 0 
			  {continue;}
		   
			sum1+= a[k];		
			}
			int sum2= sum12-sum1;
			int temp = max(abs(sum1-sum2), max( abs(sum3-sum2),abs(sum1-sum3)));
		  best= min(temp, best);
	  	
	  }
	  	
	  }
	  cout<<best<<endl;
	  return 0;
} 
