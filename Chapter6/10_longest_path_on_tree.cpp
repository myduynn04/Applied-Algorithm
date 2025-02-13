/*
Description
Given a undirected tree $G = (V, E)$ in which $V = \{1,…,N\}$ is the set of
nodes. Each edge $(u,v) \in E$ has weight $w(u,v)$. The length of a path is
defined to be the sum of weights of edges of this path. Find the longest
elementary path on $G$.
Input
Line 1: positive integer $N$ ($1 <= N <= 10^5$)
Line $i + 1$ ($i = 1,…,N-1$): positive integers $u, v, w$ in which $w$ is the weight of edge $(u,v)$ (1 ≤ w ≤ 100)
Output
The weight of the longest path on the given tree
Example
Input
6
1 3 3
1 6 2
2 6 5
4 5 2
4 6 1
Output
10
*/

#include <bits/stdc++.h>
using namespace std;

#define N 100005

int n,m;
vector<pair<int, int>> adj[N];
int depth[N] ={0};
int maxlength=0;
int visited[N]={0}; //danh dau da tham chua
int temp=1;
void dfs(int r){
    visited[r]=1;
    for (pair <int,int> v: adj[r]){
        if(visited[v.first]) continue;
        depth[v.first]= depth[r] + v.second; //phai cap nhat truoc
        dfs(v.first);
        if(maxlength < depth[v.first]){
            maxlength = depth[v.first];
            temp= v.first;}}}
int main(){
    cin>>n;
    for (int i=1; i<n; i++){  //so canh cua cay la n-1
        int a,b,c;
        cin>>a>>b>>c;
        adj[a].push_back(make_pair(b,c));
        adj[b].push_back(make_pair(a,c)); //do la do thi vo huong
    }
    dfs(1);
    memset(visited, 0, sizeof(visited));
    memset(depth, 0, sizeof(visited));
    maxlength=0;
    dfs(temp);
    cout<<maxlength<<endl;}










