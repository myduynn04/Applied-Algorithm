#include <bits/stdc++.h>
#include <vector>
using namespace std;
/*
Description
Given a sequence of integers a1, a2, . . ., an
. Perform a sequence of Q queries q(i,j) that returns the sum of ai, ai+1, . . ., aj


Input
Line 1: contains a positive integer n (2 <= n <= 100000)
Line 2: contains a
a1, a2, . . ., an. (1 <= ai <= 1000)
Line 3: contains a positive integer Q (1 <= Q <= 100000)
Line 3 + k (k = 1, 2, ..., Q): contains 2 positive integers i and j (1 <= i < j <= n) of the k th query
 
Output
Write in each line, the result of the corresponding query read from the input

Example
Input
5
5 8 7 1 9 
4
1 2
1 5
1 3
4 5

Output 
13
30
20
10 
*/
int main(){
    int n;
    cin>> n;
    vector <int> a(n); // ban đầu các phần tử đều là 0
    for (int i=0; i<n; i++) cin>> a[i];

    vector <int> S(n,0);
    S[0] = a[0];
    for (int i=1; i<n; i++) S[i]+= S[i-1] + a[i];


    int Q;
    cin>> Q;
    vector<vector<int>> pair(Q, vector<int>(2));
    for (int i = 0; i < Q; i++) cin >> pair[i][0] >> pair[i][1];
    for (int i=0; i<Q; i++){
        int first = pair[i][0];
        int second = pair[i][1];
        if (first==1) cout<< S[second-1] <<endl;
        else cout<< S[second-1]  - S[first-2] <<endl;
    }
    return 0;

}