/*
A princess, looking for a computer science husband, poses the following problem:

Given n integers, find a subset of these n integers such that the sum of the integers in the subset
does not exceed a given value M. Moreover, the difference between M and the sum of the selected integers
should be minimized.

Input:
An integer n (1 <= n <= 20), representing the number of integers.
A list of n integers, where each integer is between 1 and 1000.
An integer M (1 <= M <= 100000), the maximum allowed sum.
Output:
The output should be a single integer, which is the difference between M and the sum of the selected integers
that is closest to M.
Input   (stdin)
5
208   750 114 184 538
897
Output   (stdout)
33
*/


#include <bits/stdc++.h>
using namespace std;
#define MAXN 1000000000
int n, M;
int a[22];
int sol =MAXN;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>n;
    for (int i=1; i<=n; i++)cin>>a[i];
    cin>>M;
    for (int mask=1; mask<(1<<n); mask++){
        int temp=0;
        for (int i=0; i<n; i++){
            int v= (mask & (1<<i));
            if(v!=0) temp+=a[i+1];
            if (temp>M) break;
        }
        if(temp>M) continue;
        sol= min(sol, M-temp);}

    cout<<sol<<endl;
}
