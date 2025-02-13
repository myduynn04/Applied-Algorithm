/*
Given a sequence of distinct integers a1, a2, . . ., an
Compute the number P of triples of distinct indices (i, j, k) such that among 3 items ai, aj , ak
there is an item which is equal to the sum of 2 remaining items.
1<=n<=2000
1<=ai<=100000
Input
6
1 3 4 5 8 9

Output
5
*/
#include <bits/stdc++.h>
using namespace std;
#define MAXN 1000000000
int n;
map<int,int> P; //key la a[i], value la i cho de truy van
int res=0;
int a[2002];
int main(){
    cin>>n;
    for (int i=1; i<=n; i++)cin>> a[i];
    for (int i=1; i<=n; i++) P[a[i]]=i;
    for (int i=1; i<=n; i++){
        for (int j=i+1; j<=n; j++){
            if (P.find(a[i]+a[j])!=P.end()){
                int k= P[a[i]+a[j]];
                if (k==j || k==i) continue;
                res++;}}}
    cout<<res<<endl;
}
