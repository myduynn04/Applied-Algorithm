#include <bits/stdc++.h>
using namespace std;
#define N 255

int n, m;
int A[N][N];
int visited[N][N];
queue<pair<int, int>> Q;
int num_slick = 0;  // số lượng vết dầu loang
vector<int> slick;

// Hướng di chuyển: phải, xuống, trái, lên
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

void check(int i, int j) {
    for (int k = 0; k < 4; k++) {
        int new_i = i + dx[k];
        int new_j = j + dy[k];

        if (new_i >= 1 && new_i <= n && new_j >= 1 && new_j <= m &&
            A[new_i][new_j] && !visited[new_i][new_j]) {
            Q.push({new_i, new_j});
            visited[new_i][new_j] = 1;
            slick[num_slick]++;
        }
    }
}

void bfs(int i, int j) {
    slick.push_back(1);
    num_slick++;  // tăng số lượng thành phần liên thông
    visited[i][j] = 1;
    Q.push({i, j});

    while (!Q.empty()) {
        auto [x, y] = Q.front();
        Q.pop();
        check(x, y);
    }
}

void processCase() {
    // Khởi tạo
    slick.clear();
    num_slick = 0;
    memset(A, 0, sizeof(A));
    memset(visited, 0, sizeof(visited));

    // Đọc input
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> A[i][j];
        }
    }

    // Tìm các vết dầu loang
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (!visited[i][j] && A[i][j]) {
                bfs(i, j);
            }
        }
    }

    // In kết quả
    cout << num_slick << endl;

    // Đếm số lượng vết dầu theo kích thước
    sort(slick.begin(), slick.end());
    int currentSize = slick[0];
    int count = 0;

    for (int size : slick) {
        if (size == currentSize) {
            count++;
        } else {
            if (currentSize > 0) {
                cout << currentSize << " " << count << endl;
            }
            currentSize = size;
            count = 1;
        }
    }
    if (currentSize > 0 && count > 0) {
        cout << currentSize << " " << count << endl;
    }
}

int main() {
    while (true) {
        cin >> n >> m;
        if (n == 0 && m == 0) break;
        processCase();
    }
    return 0;
}
