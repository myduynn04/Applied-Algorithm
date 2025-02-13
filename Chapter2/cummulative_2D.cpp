#include <bits/stdc++.h>
using namespace std;
/*Given a table of n rows (1, 2, ..., n) and m columns (1, 2, ..., m). 
Each cell (i,j) has a non-negative integer a(i,j).
Perform a sequence of queries (r1, c1, r2, c2) which returns the sum of 
elements of the sub-table from row r1 to row r2 and from column c1 to 
column c2 (1 <= r1 <= r2 <= n, 1 <= c1 <= c2 <= m).

Input
Line 1: contains n and m (1 <= n, m <= 1000)
Line i+1(i = 1, 2, ..., n): contains the elements on row i of the table 
Line n+2: contains a positive integer Q (1 <= Q <= 100000) which is the number of queries 
Line q+n+2 (q = 1, 2, ..., Q): contains r1, c1, r2, c2 
(1 <= r1 <= r2 <= n, 1 <= c1 <= c2 <= m)

Output
Write in each line the result of the corresponding query read from the input

Example
Input
3 4
1 1 0 1 
1 1 1 0 
0 1 0 0 
3
2 3 3 4
1 3 3 4
2 2 3 4

Output 
1
2
3*/

int main(){
    //freopen("input.txt", "r", stdin);  // Đọc từ file input.txt
    //freopen("output.txt", "w", stdout);  // Ghi kết quả ra file output.txt
    int n,m;  //n: row, m: column
    cin>>n>>m;
    vector<vector<int>> A(n, vector<int>(m));
    for (int i=0;i<n; i++){
        for (int j=0; j<m; j++) cin >> A[i][j];
    }

    vector<vector<int>> S(n+1, vector<int>(m+1,0));

    for (int i=1;i<=n; i++){
        for (int j=1; j<=m; j++) S[i][j]= S[i][j-1]+ S[i-1][j] - S[i-1][j-1] + A[i][j];
    }

    int Q;
    cin>> Q;
    while (Q--){
        int r1, c1, r2, c2;
        cin>> r1>> c1>>r2>>c2;
        cout<< S[r2][c2]-S[r1-1][c2] - S[r2][c1-1] + S[r1-1][c1-1]<<endl;
    }
    

    return 0;
}