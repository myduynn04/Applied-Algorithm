/*
Description
Given a sequence of positive integers a
1
, a
2
, . . ., a
n
. Perform a sequence of actions of following types:
update  i  v : assign a
i
 = v
get-max  i  j : return the maximum value of the subsequence a
i
, a
i
+1
, . . ., aj

Input
Line 1: contains a positive integer n (1 <= n <= 100000)
Line 2: contains a
1
, a
2
, . . ., a
n
. (1 <= a
i
 <= 10000)
Line 3: contains a positive integer m (1 <= m <= 100000) which is the number of actions
Line i + 3 (i = 1, 2, . . ., m): contains an action described above
Output
Write in each line the result of the corresponding action of type get-max
Example
Input
10
1 10 9 7 1 4 2 4 8 10 
5
get-max 5 8
get-max 5 9
get-max 3 8
update 9 20
get-max 4 10

Ouput
4
8
9
20
*/
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e6;
int a[MAXN];
int main(){
    int n;
    cin >> n;
    for (int i= 1; i< n; i++){
        cin >> a[i];
}
}