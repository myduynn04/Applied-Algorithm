/*Given N (N<=15) and K, count number of permutations of [1, 2, 3...N] in which no two adjacent elements differ by more than K. 
For example, permutation [4, 1, 2, 3] cannot be counted for .

Input
First line contains T(1 <= T <= 10), the number of test cases. Each test case consists of N(1 ? N ? 15) and K(0 ? N) in single line.

Output
For each test case print the required answer in one line.

Examples
Input
2
2 1
3 1
Output
2
2*/

#include <bits/stdc++.h>
using namespace std;

int main( ){
	int T; cin >> T;
	int n, k;
	for (int i=0; i<T; i++){
		cin>> n >> k;
		int mem[(1<<n)][16];
		memset(mem, 0, sizeof(mem));
		for (int i=1; i<= n; i++) mem[1][i]=1;
		
		for (int mask = 0; )
		
	}
	
}




















