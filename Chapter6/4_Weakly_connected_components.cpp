/*Yêu cầu:
Cho đơn đồ thị vô hướng liên thông G = (V, E) gồm n đỉnh và m cạnh, các đỉnh được đánh số từ 1 tới n và các cạnh được đánh số từ 1 tới m. Tìm số thành phần liên thông của đồ thị.

Input
Dòng 1: Chứa hai số n, m .

M dòng tiếp theo: Dòng thứ i có dạng 2 số nguyên u, v. Trong đó u, v là chỉ số hai đỉnh đầu mút của cạnh thứ i.

Output
Ghi số k là số thành phần liên thông của đồ thị.

Ví dụ
Input:
7 6
1 2
1 3
2 3
5 6
6 7
5 7
Output:
3

Giới hạn:
1 <= n <= 100000
1 <= m <= 100000*/

#include <bits/stdc++.h>
using namespace std;

#define N 100005
#define M 100005
int n, m;
vector<int> adj[N];
queue <int> Q;
int vistited[N]={0};
int num_connect=0;
void bfs(int u){
    Q.push(u);
    visited[u]=1;
    num_connect++;
    while (!Q.empty()){
        int first = Q.front();
        Q.pop();
        for (int v : adj[first]){
            if (!visited[v]){
                Q.push(v);
                visited[v]=1;}}}}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>m;
    for(int i =1 ; i<=m; i++){
        int a,b;
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
   for (int i=1; i<=n; i++){
    if (!visited[i]) bfs(i);
   }

    count<<num_connect<<endl;

    return 0;
}










