
#include <bits/stdc++.h>
using namespace std;

#define N 100005
#define M 100005
int n, m;
vector<int> adj[N];
queue <int> Q;
int visited[N]={0};
/*
void bfs(int u){
    Q.push(u);
    while (!Q.empty()){
        //lay phan tu dau tien va loai bo khoi queue
        int first = Q.front();
        Q.pop();
        if(visited[first]) continue; //neu first dc duyet roi thi bo qua (minh dang tinh la cu cho het vao queue, khong quan tam da duyet hay chua, va chi kiem tra lai khi pop)
        visited[first]= 1;
        for (int v : adj[first]){
            if (!visited[v]){
                Q.push(v);
            }
        }
    }
}

*/

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
                visited[v]=1;
            }
        }
    }

}

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

    cout<<num_connect<<endl;

    return 0;
}










