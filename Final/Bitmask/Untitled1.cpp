#include <bits/stdc++.h>
using namespace std;

#define MAXN 1e9 // Giá trị vô cực lớn
int n;
int c[22][22]; // Ma trận khoảng cách
int mem[1 << 21][21]; // DP table
int fbest = MAXN; // Kết quả tốt nhất

int main() {
    cin >> n;

    // Nhập ma trận khoảng cách
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) cin >> c[i][j];
    }

    // Khởi tạo mảng `mem` với giá trị lớn
    for (int mask = 0; mask < (1 << n); mask++) {
        for (int i = 1; i <= n; i++) {
            mem[mask][i] = MAXN;
        }
    }

    // Trạng thái khởi đầu: Xuất phát từ thành phố 1
    mem[1][1] = 0;

    // Tính toán DP
    for (int mask = 1; mask < (1 << n); mask++) {
        for (int u = 1; u <= n; u++) {
            if ((mask & (1 << (u - 1))) == 0) continue; // Thành phố u chưa được thăm

            for (int v = 1; v <= n; v++) {
                if ((mask & (1 << (v - 1))) != 0) continue; // Thành phố v đã được thăm
                int nextMask = mask | (1 << (v - 1));
                mem[nextMask][v] = min(mem[nextMask][v], mem[mask][u] + c[u][v]);
            }
        }
    }

    // Tìm kết quả nhỏ nhất
    for (int i = 2; i <= n; i++) {
        fbest = min(fbest, mem[(1 << n) - 1][i] + c[i][1]); // Quay về thành phố 1
    }

    cout << fbest << endl; // In ra kết quả tối ưu
    return 0;
}
