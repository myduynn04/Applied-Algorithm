/*Given a sequence of distinct integers a1, a2, . . ., an
 and an integer value Q. Compute the number P of triples (i, j, k) such that
 1 <= i < j < k <= n and ai + aj + ak = Q.

Input
Line 1: contains 2 integers n and Q (1 <= n <= 5000, 1 <= Q <= 1000000)
Line 2: contains n integers a1, a2, . . ., an(1 <= ai <= 100000)

Output
Write the value P mod 109+7

Example
Input
6 10
2 1 6 7 4 5

Output
2
*/

#include <bits/stdc++.h>
using namespace std;
#define MAXN 5005
#define MAXQ 1000005
int n,Q;
int a[MAXN];
int sol=0;
map <int, int> P;


//Lưu ý với bài này do find chỉ tìm đc theo key nên ta lưu key là giá trị còn value là chỉ số

int main(){
    cin>>n>>Q;
    for (int i=1; i<=n; i++){
        cin >>a[i];
        P[a[i]]= i;
    }
    for (int i=1; i<=n; i++){
        for (int j=i+1; j<=n; j++){
           int ak = Q-a[i]-a[j];
           if (P.find(ak)!= P.end()){
                if(P[ak] >j) {
                    sol++;
                    //cout<<a[i]<<a[j]<<a[P[ak]]<<endl;
                }
           }
        }
    }
    cout << sol % (1000000007) <<endl;

}
