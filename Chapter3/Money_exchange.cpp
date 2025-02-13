#include <bits/stdc++.h>
using namespace std;


/* Given a set of n coins (n <=10) of denominations d0, d1, ..., dn-1 and the value X<=100000.
Find the minimum number of coins to exchange the value of X

Input:
- n,X
- n positive numbers d0,...

Output:
The minimum number of coins to exchange for value of X using the given set coins. In case there does not exist to echange, print -1
*/
 /* ý tưởng: dungf quy hoạch động:
 nếu dp[X] là mảng để lưu số đồng tiền bé nhất để tạo ra số tiền từ 0->X
khi duyệt qua từng đồng tiền dj<i: ta sẽ có
dp[i] = min(dp[i], dp[i - coins[j]] + 1);


 */
int minCoin(int n, int X, vector<int>& d){
    vector<int> dp(X+1, INT_MAX); // De luu tru dc tu d[0] den d[X]
    dp[0]=0; // Không cần đồng nào để đổi ra số tiền 0


    //Duyệt qua các giá trị từ 1-> X
    for (int i=0; i<=X; i++){
        //Duyệt từng đồng xu
        for (int j= 0; j<n; j++ ){
            if(d[j]<=i && dp[i-d[j]]!= INT_MAX){
                dp[i]=min(dp[i], dp[i-d[j]]+1);
            }
        }
    }
    return dp[X]== INT_MAX ? -1 : dp[X];
}

int main(){
    int n, X;
    cin>>n>>X;

    vector <int> d(n);
    for (int i = 0; i < n; i++){
            cin >> d[i];
    }

    int result = minCoin(n,X,d);
    cout << result << endl;
    return 0;

}