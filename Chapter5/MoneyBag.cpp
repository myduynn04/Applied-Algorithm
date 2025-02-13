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
	 	sum+=a[i];}
	  for (int mask =1; mask<(1<<n); mask++){
	  	int sum1=0;
	  	for (int k=0; k<n; k++){
	  		if ( ((mask >> k)&1) == 0) //o vi tri k la 0
			  {continue;}
			else { sum1+= a[k];		}
			best = min (best, abs(sum -2*sum1));}}
	  cout<<best<<endl;}
