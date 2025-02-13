#include <bits/stdc++.h>

using namespace std;

int main() {
    int n; cin >> n;
    int max_x = 0, max_y = 0;
    map<int, map<int, int> > sto;
    for (int i=0; i<n; i++) {
        int a, b, c; cin >> a >> b >> c;
        if (sto.find(a) == sto.end() || sto[a].find(b) == sto[a].end()) {
            sto[a][b] = 0;}
            max_x = max(max_x, a);
            max_y = max(max_y, b);
            sto[a][b] += c;}
    long long res[max_y+1] = {0};
    for (int i=1; i<=max_x; i++) {
        if (sto.find(i) == sto.end()) continue;
        for(int j=1; j<=max_y; j++) {
            res[j] = max(res[j], res[j-1]);
            if (sto[i].find(j) != sto[i].end()) {
                res[j] += sto[i][j];}}}
    cout << res[max_y];}
