/*Description
Cho dãy a1, a2, ..., an trong đó các phần tử đôi một 
khác nhau và 1 giá trị nguyên dương M. Hãy đếm số Q 
các cặp (i,j) sao cho 1 <= i < j <= n và ai + aj = M.

Dữ liệu
Dòng 1: ghi n và M (1 <= n, M <= 1000000)
Dòng 2: ghi a1, a2, ..., an
Kết quả
Ghi ra giá trị Q
Ví dụ
Dữ liệu
5 6
5 2 1 4 3
Kết quả
2*/

#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, M;
    cin >> n >> M;
    vector<int> a(n);

    for (int i=0; i<n; i++) cin >> a[i];
    sort(a.begin(), a.end()); // bài này họ lại không cho mảng đã xếp sẵn, nên cần xếp tay 
    //ys tưởng là dùng 2 con trỏ đầu và cuối
    int i=0;
    int j=n-1;
    int res=0;
    while (i<j){
        if ((a[i]+a[j])== M) {
            res +=1; 
            i++;
            j--;
        } 
        else if ( (a[i] +a[j])<M) i++;
        else j--;
    }
    cout << res << endl;
    return 0;
}