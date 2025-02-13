/*
Given a directed graph G=(V,E) where V={1,. . ., N} is the number of nodes and the set E has M arcs. Compute number of strongly connected components of G
Input
Line 1: two positive integers N and M (1 <= N <= 10
5
, 1 <= M <= 10
6
)
Line i+1 (i=1,. . ., M\): contains two positive integers u and v which are endpoints of i
th
 arc
Output
Write the number of strongly connected components of G
Example
Input
8 13
1 2
1 8
2 3
2 6
3 6
4 3
4 6
5 4
6 5
7 1
7 2
7 6
8 7
Output
3
*/

#include <bits/stdc++.h>
using namespace std;
#define N 100005
#define M 100005


int n, m;
int visited[N]={0};
int num[N]={0};
int low[N]={0};
int tail[N]={0};
int num_com=0;
int A[N]={0};//Danh dau thuoc tplt nao
//vi la duyet DFS -> dung ds ke de truy van
map<int, vector<int>> adj;
stack <int> S;
int timeDFS =0;
void dfs(int u, int pre){
    num[u]=low[u]= ++timeDFS;
    S.push(u);

    for (auto v: adj[u]){
        if(v==pre) continue; //neu v la cha truc tiep cua u thi bo qua
        else if(!num[v]){
            //neu v chua duoc tham
            dfs(v, u);
            low[u]= min(low[u], low[v]);
            }
        else{//TH back edge
            low[u]= min(low[u], num[v]);}}

    if(low[u]==num[u]){
        //Day la chot
        num_com++;
        int top=S.top();
        S.pop();
        A[top]=u;
        while(top!=u){
            top=S.top();
            S.pop();
            A[top]=u;
        }

    }



    }
int main(){
    cin >>n>>m;
    for (int i=1; i<=m; i++){
        int a, b; cin>>a>>b;
        adj[a].push_back(b); //do la do thi co huong

}
    for (int i=1; i<=n; i++){
        if(!num[i]) {dfs(i,i);}}
    cout<<num_com<<endl;}

