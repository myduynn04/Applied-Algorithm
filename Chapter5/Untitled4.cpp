/*
Problem 3. LAIS (Longest Alternating Increasing Subsequence)

The given sequence consists of  integers . An alternating subsequence is a subsequence in which any two consecutive elements always have opposite signs and none of the elements is 0. Find the longest alternating subsequence where the absolute values of its elements form a strictly increasing sequence. A subsequence with a single element is considered valid.

Input

The first line contains a positive integer ;

The second line contains  integers  which are distinct and separated by spaces ().

Output

Print a single integer, the length of the longest alternating subsequence where the absolute values of the elements strictly increase.

Example

Input:

14
2 34 4 -3 4 5 42 -6 45 7 9 10 11 12

Output:
5
*/
#include <bits/stdc++.h>
using namespace std;
#define MAX 1e6

int n;
int a[1005];
int mem[1005];

int main(){
	cin>>n;
	for(int i=1; i<=n; i++){
		cin>>a[i];
	}
    vector <int> sto; // luu day ma se chen theo upper bound
	
	//bat dau tim kiem nhi phan
	for (int i=1; i<=n; i++){
		(sto.push)
	} 
	 
	
	cout << result<<endl;
	
	return 0;
}


