/*Given a sequence of n integers a0,. . .,an-1
. We denote rmq(i,j) the minimum element of the sequence
ai, ai+1, . . .,aj
. Given m pairs (i1, j1),. . .,(im, jm), compute the
sum Q = rmq(i1,j1) + . . . + rmq(im, jm)
Input
Line 1: n (1 <=  n<= 10^6)
Line 2: a0,. . .,an-1( 1  <=  ai <= 10^6)
line 3: m (1  <= m <= 10^6)
Line k+3 (k=1, . . ., m): ik, jk (0  <=  ik< jk< n)
Output
Write the value Q
Example
Input
16
2 4 6 1 6 8 7 3 3 5 8 9 1 2 6 4
4
1 5
0 9
1 15
6 10

Output
6
*/

#include <bits/stdc++.h>
using namespace std;
const int MAXN=1e6+5;
const int LOGN=20;

int a[MAXN];  //dãy số ban đầu
int M[LOGN][MAXN];

void preprocess(int n){
    int  k = static_cast<int> (log2(n))+1;

    for (int j=0; j<n; j++) M[0][j]=j;// Khởi tạo dòng đầu của M với chỉ số ban đầu

    for ( int i=1; i<k; i++ ){
        for (int j= 0; j+ (1<<i)<=n; j++){
            int x1=  M[i-1][j] ;
            int x2= M[i-1][j + (1<<(i-1))];
            if( a[x1]< a[x2] ) M[i][j]=x1;
            else M[i][j] = x2;}}
int RMQ(int i, int j){
    int k= static_cast<int> (log2(j-i+1));
    int x1=  M[k][i] ;
    int x2= M[k][j-(1<<(k))+1];
    return a[x1]<=a[x2] ? x1: x2;}

int main(){
    //freopen("input.txt", "r", stdin);
    int n,m;
    cin>>n;
    for (int i=0; i< n; i++) cin>> a[i];
    preprocess(n);
    cin>>m; //số truy vấn
    int sum =0;
    for (int k=0; k<m; k++){
        int i,j;
        cin>>i>>j;
        sum+= a[RMQ(i,j)];}
    cout<<sum<<endl;}
