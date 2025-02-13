#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, m,dem = 0;
    cin >> n >> m;
    vector<int> a(n+1);
    for (int i = 1; i <= n; i++) 
    {cin >> a[i];}
    sort(a.begin(), a.end());
    int i = 1, j = n;
    while (i < j) {
        int sum = a[i] + a[j];
        if (sum == m) {
            dem++;
            i++;
            j--;
        } 
        else if (sum < m) {i++;} 
        else {j--;}
    }
    cout << dem;
    return 0;
}
