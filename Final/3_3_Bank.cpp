/*
A bank needs to transfer n bags of money from its headquarters to its branches using two specialized
cash transport vehicles with equal transportation capabilities. Each money bag has a value. To minimize
operational risk, the cash transport coordinator needs to divide these n money bags between the two
vehicles so that the difference in the total value of money transported by these two vehicles is as small
as possible.
Input/Đầu vào
Row 1: A integer representing the number of cash bags, n (1 <= n <= 20)
Row 2: n integers separated by by spaces, each representing the value of a cash bag. These integers range
from 1 to 1000
Output/Đầu ra
An integer representing the smallest possible difference in the total values of money transported by the
two vehicles.
Example/Ví dụ
Input   (stdin)
5
208   750 114 184 538
Output (stdout)
66

*/

#include <bits/stdc++.h>
using namespace std;
#define MAXN 1000000000
int n;
int a[22];
int res= MAXN;
//0 la xe 0, 1 la xe 1
int main(){
    cin >>n;
    for (int i=0; i<n; i++) cin>>a[i];

    for (int mask =1; mask<(1<<n); mask++){
        int temp0=0;
        int temp1=0;
        for (int i=0; i<n; i++){
            int v= mask & (1<<i);
            if (v==0) temp0+= a[i];
            else temp1+=a[i];
        }
        res = min (res, abs(temp0-temp1));
    }

    cout<<res<<endl;
}
