#include <bits/stdc++.h>
using namespace std;

const int MAX_CITIES = 1001;
const int INF = INT_MAX;
int n;
int distance_matrix[MAX_CITIES][MAX_CITIES];
vector<int> tour;
void nearest_neighbor_tsp() {
    vector<bool> visited(n, false);
    int current_city = 0;
    visited[current_city] = true;
    tour.push_back(current_city + 1);
    for (int step = 1; step < n; ++step) {
        int nearest_city = -1;
        int min_distance = INF;
        for (int next_city = 0; next_city < n; ++next_city) {
            if (!visited[next_city] && distance_matrix[current_city][next_city] < min_distance) {
                min_distance = distance_matrix[current_city][next_city];
                nearest_city = next_city;}}
        if (nearest_city != -1) {
            visited[nearest_city] = true;
            current_city = nearest_city;
            tour.push_back(current_city + 1);}}}

int main() {
    cin >> n;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin >> distance_matrix[i][j];}}
    nearest_neighbor_tsp();
    cout << n << endl;
    for (int city : tour) {
        cout << city << " ";}
    cout << endl;}
