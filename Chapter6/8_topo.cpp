/*
7 7
1 2
1 4
2 3
4 5
6 5
5 3
7 4
output
1 2 7 5 6 3 4
*/

#include <bits/stdc++.h>
using namespace std;


#define N 105
#define M 10005
#define MAXN 1e9
int n,m;
vector<int> adj[N];
int result[N]; //mang luu chi so sau khi danh so lai
queue <int> Q;
int num_in[N]={0};
int main(){
    cin>>n>>m;
    for(int i=1; i<=m; i++){
        int a,b; cin>>a>>b;
        adj[a].push_back(b);
        num_in[b]++;}
    int index=1;
    //Cap nhat ban bac vao
    for(int i=1; i<=n; i++){
        if(num_in[i]==0){
            Q.push(i);}}
    while(!Q.empty()){
        int top = Q.front();
        Q.pop();
        result[top]=index++;
        for (int v: adj[top]){
            num_in[v]--; //giam ban bac vao
            if(num_in[v]==0){ //nguon moi
                Q.push(v);}}}
    for(int i=1; i<=n; i++) cout<<result[i]<<" ";
    cout<<endl;}




























