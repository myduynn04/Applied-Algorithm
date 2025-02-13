/*
Input:
8
1 5 8 9 10 17 17 20
Output:
22
*/

#include <bits/stdc++.h>
using namespace std;
int n;
int p[1005]={0};
int mem[1005]={0};
int main(){
    cin>>n;
    for (int i=1; i<=n; i++){
        cin>>p[i];}
    for (int i=1; i<=n; i++){
        for (int j=0; j<i; j++){
            mem[i]= max(mem[i], mem[j]+ p[i-j]);}}
    cout<<mem[n]<<endl;}
