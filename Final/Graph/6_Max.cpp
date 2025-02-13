#include <bits/stdc++.h>
using namespace std;

int n, m;
map<int, map<int, int> > task;
int res = 0;
int par[20005] = {0};
set<int> visited;

void update(int start) {
    int u = m+n+1;
    while (u != start) {
        task[par[u]][u] -= 1;
        task[u][par[u]] += 1;
        u = par[u];}}

int bfs(int start) {
    queue<int> Q;
    Q.push(start);
    while (!Q.empty()) {
        auto u = Q.front(); Q.pop();
        visited.insert(u);
        for (auto v : task[u]) {
            if (visited.find(v.first) == visited.end() && task[u][v.first] > 0) {
                par[v.first] = u;
                if (v.first == m+n+1) {
                    update(start);
                    visited.clear();
                    return 1;}
                Q.push(v.first);
                par[v.first] = u;}}}
    return 0;}

int main() {
	cin >> n >> m;
	for (int i=0; i<n; i++) {
		int t; cin >> t;
		int temp;
        task[0][i+1] = 1;
		for (int j=0; j<t; j++) {
			cin >> temp;
			task[i+1][n+temp] = 1;
            task[n+temp][i+1] = 0;}}

    for (int i=0; i<m; i++) {
        task[n+i+1][n+m+1] = 1;}

    for (int i=0; i<n; i++) {
        res += bfs(i+1);
        if (res == min(m, n)) {break;}}
    cout << res;}
