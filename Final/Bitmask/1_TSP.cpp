/*
There are n cities 1, 2, ..., n. The travel distance from city i to city j is c(i,j),
for i,j = 1, 2, ..., n.  A person departs from city 1, visits each city 2, 3, ..., n
exactly once and comes back to city 1. Find the itinerary for that person so that the
total travel distance is minimal.
Input
Line 1: a positive integer n (1 <= n <= 20)
Line i+1 (i = 1, . . ., n): contains the i
th row of the distance matrix x (elements are separated by a SPACE character)
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
7
*/
#include <bits/stdc++.h>
using namespace std;
#define MAXN 1000000000
int n;
int c[22][22];
int fbest=MAXN;
int mem[1<<22][22];

int main(){
    cin>>n;
    for(int i=1; i<=n; i++){
        for (int j=1; j<=n; j++) cin>>c[i][j];}
    for (int i=0; i<(1<<n); i++){
        for (int j=1; j<=n; j++){
            mem[i][j]=MAXN;}}
    mem[1][1]=0;

    for (int mask = 1; mask < (1<<n); mask++ ){
        //Kiem tra da xuat phat tu 1 chua
        if( (mask& 1)==0 ) continue;
        for (int i=2; i<=n; i++){
            //Kiem tra da tham chua
            if((mask & (1<<(i-1))) ==0) continue;//==0 tuc la tp nay chua dc tham, vay thi bo qua
            int premask = mask ^ (1<<(i-1));
            for (int j=1; j<=n; j++){
                mem[mask][i]= min(mem[mask][i], mem[premask][j]+c[j][i]);}}}

    for(int i=2; i<=n; i++){
        fbest = min(fbest, mem[(1<<n)-1][i]+c[i][1]);}
    cout<<fbest<<endl;}

















