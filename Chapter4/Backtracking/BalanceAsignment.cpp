//C++
#include <bits/stdc++.h>
using namespace std;

#define MAX 1e9
int m, n, k;
int has_asign = 0;
int best = MAX;
map<int, vector<int> > courses;
vector<int> asigned[25];
int conflict[35][35] = {0};

int check(int k, int i) {
	for (int h : asigned[i]) {
		if (conflict[h][k]) return 0;}
	return 1;}

int check_continue(int i) {
	if (asigned[i].size() > best) return 0;
	return 1;}

void upd() {
	int temp = 0;
	for (int i=1; i<=m; i++) {
		int e = asigned[i].size();
		temp = max(temp, e);}
best = min(best, temp);}

void Try(int k) {
    for (int i : courses[k]) {
        if (check(k, i)) {
            //update
            asigned[i].push_back(k);
            if (k == n) {upd();}
			else if (check_continue(i)) {Try(k+1);}
			asigned[i].pop_back();}}}
int main()
{ cin >> m >> n;
for (int i=0; i<m; i++) {
 int h; cin >> h;
 for (int j=0; j<h; j++) {
    int temp; cin >> temp;
    courses[temp].push_back(i+1);}}
cin >> k;
for (int i=0; i<k; i++) {
    int a, b; cin >> a >> b;
    conflict[a][b] = 1;
    conflict[b][a] = 1;}
    Try(1);
    cout << best;}
