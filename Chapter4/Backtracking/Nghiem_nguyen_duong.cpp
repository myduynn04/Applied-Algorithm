/*
Given a positive integer n and n positive integers a1, a, ..., an. 
Compute the number of positive integer solutions to the equation:
a1X1 + a2X2+ . . . + anXn= M

Input
Dòng 1: n và M
Dòng 2: a1, a2, ..., an
Output
So nghiem nguyên duong
Ví du
Input
3 5
1 1 1
Output
6
*/

#include <bits/stdc++.h>
using namespace std;
int n, M;
int a[20];
int res=0;
int x[20];
int sum=0;



void Try(int k){
	//duyet theo a[k]
	int temp = M/ a[k];
	for (int i=1; i<=temp; i++ ){
	    if ( sum + a[k] * i <=M ) 
		{	//update
			sum+= a[k] * i;
			//dung
			if(k==n) {
				if (sum==M) res ++;
			}
			else {
			Try(k+1);
			}
			
			//release
			sum-= a[k] * i;
	    }
	}
	
}

int main(){
	cin >>n>>M;
	for (int i=1; i<=n; i++){
		cin >>a[i];
	}
	
	Try(1);
	cout<< res<<endl;
	
	return 0;
	
	 
}














