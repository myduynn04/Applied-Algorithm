/*Description
Given a set of coins with denominations D1, D2, ..., Dn and a denomination x. Find the minimum number of coins to exchange for denomination x.
Input
Line 1: contains 2 positive integers n and x (1 <= n <= 1000, 1 <= x <= 1000)
Line 2: contains n positive integers D1, D2, . . ., Dn

Output
Write the minimum number of coins used

Example
Input
4 10
2 1 1 3
Output
4

=> tra ve so dong xu it nhat de doi ra x*/

//=> quy theo gia tri x

#include <bits/stdc++.h>
using namespace std;

#define MAX 1e9
int d[1005]; // array store the value of coin
int mem[1005]; // mang nho
int x, n;
int Mincoin(int x){//
	if (x < 0) return MAX;
	if (x==0) return 0;
	if (mem[x]!=-1) return mem[x];
	int temp =MAX;
	for (int i=0; i<n; i++){
		temp = min (temp, Mincoin(x-d[i])+1);}
	if(temp != MAX) mem[x]= temp;
	return temp;  }
int main(){
	cin >> n>>x;
	for (int i=0; i< n; i++) cin>> d[i];
	memset(mem, -1, sizeof(mem)); // khoi tao ban dau la khong doi dc tien
	mem[0]=0;
	int result = Mincoin(x);
	if (result != MAX) cout << result <<endl;
    else cout<< -1 <<endl; }

