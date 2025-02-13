/*
Given a tree T=(V,E) in which V={1,. . ., n} is the set of nodes.
Each edge (u,v) of T has length w(u,v).
Denote f(v) the sum of length of paths from all other nodes to v.
Write a program to compute max{f(1), .  . ., f(n)}.

Input
Line 1 contains a positive integer n (2 <= n <= 10^5)
Line i+1 (i=1, . . ., n): contains u, v and w in which w is the weight
of the edge (u,v)
Output
Write the value max{f(1), . . , f(n}.

Example
Input
4
1 2 1
1 3 3
3 4 2
Output
13
*/

#include <bits/stdc++.h>
using namespace std;

#define N 100005

int n,m;
vector<pair<int, int>> adj[N];
int f[N]={0};
int d[N]= {0}; // duong di tu nopde den tat ca node thuoc cay goc la node do
int visited[N]={0}; //danh dau da tham chua
int maxf=0;
int num[N]; //luu so node cua cay N
void dfs(int u){
    visited[u]=1;

    for (pair <int,int> v: adj[u]){
        if(visited[v.first]) continue;
        int a=v.first;
        dfs(a);
        num[u]+= num[a];
        d[u] += d[a] + v.second * num[a];}}

void update(int u){
    visited[u]=1;
    for(auto v : adj[u]){
      if(visited[v.first]) continue;
      int a=v.first;
      f[a]= f[u] + v.second *(num[1]- 2*num[a]);
      maxf = max(maxf, f[a]);
      update(v.first);}}

int main(){
    fill_n(num, N, 1);
    cin>>n;
    for (int i=1; i<n; i++){  //so canh cua cay la n-1
        int a,b,c;
        cin>>a>>b>>c;
        adj[a].push_back(make_pair(b,c));
        adj[b].push_back(make_pair(a,c)); //do la do thi vo huong
        }
    dfs(1);
    fill_n(visited, N, 0);
    f[1]= d[1];
    maxf=f[1];
    update(1);
    cout<<maxf<<endl;}
