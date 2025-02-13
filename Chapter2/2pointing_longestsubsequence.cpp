/*
Given a sequence of positive integers a = a1, a2, . . ., an.
A subsequence of a is defined to be a sequence of
consecutive elements ai, ai+1, . . ., aj (1 <= i <= j <= n).
The weight of a subsequence is the sum of its elements.
Given a positive integer Q. A subsequence is said to be feasible if the weight is less than or equal to Q.
Find a feasible subsequence such that the number of elements of that subsequence is maximal.
Input
Line 1: contains two positive integers n and Q (1 <= n <= 10 ^6, 1 <= Q <= 100000)
Line 2: contains a = a1, a2, . . ., an
Output
Write the number of elements of the subsequence found, or write -1 if no such subsequence exists.
Example
Input
10 40
19 2 7 6 9 1 17 19 8 4
Output
5*/

#include <bits/stdc++.h>
using namespace std;
int main(){
    int n, Q;
    cin>>n>>Q;
    vector<int> a(n);
    for( int i=0; i<n; i++) cin>> a[i];
    int res=0; //lưu độ dài subsequence lớn nhất
    int L =0; //Con trỏ trái
    int R=0; //Con trỏ phải
    int S=0; //tổng của subsequence
    for (; R<n; R++){
        S+= a[R];
        while (S>Q) {
            S-= a[L];
            L+=1;}
    res = max(res, R-L+1);    }
cout << res << endl;
return 0;
}
