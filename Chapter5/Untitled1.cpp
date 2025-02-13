#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 15; // Giá tr? t?i ða c?a N
int mem[1 << MAX_N][MAX_N + 1]; // M?ng lýu tr? tr?ng thái DP

int main() {
    int T; // S? lý?ng test cases
    cin >> T;

    while (T--) {
        int n, k;
        cin >> n >> k;

        // Kh?i t?o l?i m?ng mem cho t?ng test case
        memset(mem, 0, sizeof(mem));

        // Kh?i t?o tr?ng thái ban ð?u
        for (int i = 1; i <= n; i++) {
            mem[1 << (i - 1)][i] = 1;
        }

        // Quy ho?ch ð?ng
        for (int mask = 1; mask < (1 << n); mask++) {
            for (int i = 1; i <= n; i++) {
                // N?u i không n?m trong mask, b? qua
                if (!(mask & (1 << (i - 1)))) continue;

                // Tr?ng thái trý?c khi ch?n i
                int premask = mask ^ (1 << (i - 1));

                // Duy?t qua t?t c? các ph?n t? j có th? ð?ng trý?c i
                for (int j = 1; j <= n; j++) {
                    if (!(premask & (1 << (j - 1)))) continue; // N?u j không n?m trong premask, b? qua
                    if (abs(i - j) > k) continue; // N?u |i - j| > k, không h?p l?

                    // C?ng d?n s? cách t? tr?ng thái trý?c
                    mem[mask][i] += mem[premask][j];
                }
            }
        }

        // Tính t?ng k?t qu? cho tr?ng thái "hoàn thành"
        int done = (1 << n) - 1; // T?t c? các s? ð?u ðý?c ch?n
        int result = 0;
        for (int i = 1; i <= n; i++) {
            result += mem[done][i];
        }

        // In k?t qu? cho test case hi?n t?i
        cout << result << endl;
    }

    return 0;
}

