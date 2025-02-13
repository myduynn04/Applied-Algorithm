#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 15; // Gi� tr? t?i �a c?a N
int mem[1 << MAX_N][MAX_N + 1]; // M?ng l�u tr? tr?ng th�i DP

int main() {
    int T; // S? l�?ng test cases
    cin >> T;

    while (T--) {
        int n, k;
        cin >> n >> k;

        // Kh?i t?o l?i m?ng mem cho t?ng test case
        memset(mem, 0, sizeof(mem));

        // Kh?i t?o tr?ng th�i ban �?u
        for (int i = 1; i <= n; i++) {
            mem[1 << (i - 1)][i] = 1;
        }

        // Quy ho?ch �?ng
        for (int mask = 1; mask < (1 << n); mask++) {
            for (int i = 1; i <= n; i++) {
                // N?u i kh�ng n?m trong mask, b? qua
                if (!(mask & (1 << (i - 1)))) continue;

                // Tr?ng th�i tr�?c khi ch?n i
                int premask = mask ^ (1 << (i - 1));

                // Duy?t qua t?t c? c�c ph?n t? j c� th? �?ng tr�?c i
                for (int j = 1; j <= n; j++) {
                    if (!(premask & (1 << (j - 1)))) continue; // N?u j kh�ng n?m trong premask, b? qua
                    if (abs(i - j) > k) continue; // N?u |i - j| > k, kh�ng h?p l?

                    // C?ng d?n s? c�ch t? tr?ng th�i tr�?c
                    mem[mask][i] += mem[premask][j];
                }
            }
        }

        // T�nh t?ng k?t qu? cho tr?ng th�i "ho�n th�nh"
        int done = (1 << n) - 1; // T?t c? c�c s? �?u ��?c ch?n
        int result = 0;
        for (int i = 1; i <= n; i++) {
            result += mem[done][i];
        }

        // In k?t qu? cho test case hi?n t?i
        cout << result << endl;
    }

    return 0;
}

