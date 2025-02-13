/*Description
There are n cities 1, 2, ..., n. The travel distance from city i to city j is c(i,j), for i,j = 1, 2, ..., n.  
A person departs from city 1, visits each city 2, 3, ..., n exactly once and comes back to city 1. 
Find the itinerary for that person so that the total travel distance is minimal.

Input
Line 1: a positive integer n (1 <= n <= 20)
Line i+1 (i = 1, . . ., n): contains the i
th
 row of the distance matrix x (elements are separated by a SPACE character)

Output
Write the total travel distance of the optimal itinerary found.
Example
Input
4
0 1 1 9
1 0 9 3
1 9 0 2
9 3 2 0
Output
7*/

#include <bits/stdc++.h>
using namespace std;
int n;
int c[21][21];
int mem[(1<<20)][21];

int main (){
	cin>>n;
	for (int i =1; i<=n; i++ ){
		for (int j =1; j<=n; j++ ) cin >> c[i][j];
	}
	
	memset(mem, 1e9, sizeof(mem));
	mem[1][1]=0;
	
	for (int mask = 1; mask < (1<<n); mask++ ){
		
		for (int i =1; i<=n; i++ ){
		
			if ( (mask >>(i-1)&1) ==0  ) continue; // visited
			int premask = mask ^ (1 << (i-1)); // luu y do bat dau tu 1 nen XOR voi 1<< (i-1)
			if (premask == 0 ) mem[mask][i]= c[1][i]; // hieu la lui lai la den 1
			else{
				int temp = 1e9;
				for (int j = 2; j<=n; j++){	
					if ((premask >> (j - 1) & 1) == 0) continue;
					temp= min ( temp, mem[premask][j]+ c[j][i]);	
				}
			mem[mask][i]= temp;
			}			
		}
	}
	int res=1e9;
	int done = (1<<n)-1;
	for (int i=2; i<=n; i++){
		res = min (res, mem[done][i] + c[i][1])  ;
	}	
	cout<< res <<endl;	
}

// Luu y: Tim min nen
