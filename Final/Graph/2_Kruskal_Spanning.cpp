/*
Given a undirected connected graph G=(V,E) where V={1,…,N}. Each edge (u,v)∈E(u,v)∈E has weight w(u,v)w(u,v). Compute minimum spanning tree of G.
Input
Line 1: N and M (1≤N,M≤10
5
) in which NN is the number of nodes and MM is the number of edges.
Line i+1 (i=1,…,M): contains 3 positive integers u, v, and w where w is the weight of edge (u,v)
Output
Write the weight of the minimum spanning tree found.
Example
Input
5 8
1 2 1
1 3 4
1 5 1
2 4 2
2 5 1
3 4 3
3 5 3
4 5 2
Output
7
*/

#include <bits/stdc++.h>
using namespace std;
int n, m;
int par[100005];// danh dau a thuoc tplt nao
vector < pair<pair<int,int >, int>> sto; //luu cap canh va trong so
int res =0;

int check(int a, int b){
    //Ta phai tim goc
    int root_a= a;
    int root_b= b;
    //Dk de la goc: r=par[r];
    while(root_a!=par[root_a]){
        root_a= par[root_a];}
    while(root_b!=par[root_b]){
        root_b= par[root_b];}
    if(root_a!=root_b)return 1;
    return 0;}
void S_union(int a, int b){
    int root_a=a;
    int root_b=b;
    while(root_a!=par[root_a]){
        root_a=par[root_a];}
    //Can tim root cua b va cap nhat cho par[b] = root_a
    //Cap nhat tren ca tplt chua b
    while(root_b!=par[root_b]){
        root_b= par[root_b];
        par[b]=root_a;
        b=root_b;//di len tren cung root_b
    }
    //Cap nhat goc cua root_b=root_a
    par[root_b]=root_a;}

int main(){
    cin >>n>>m;
    for (int i=1; i<=m; i++){
        int a, b, c;
        cin>>a>>b>>c;
        sto.push_back(make_pair(make_pair(a,b),c));}
    //ban dau cac node la cac tplt roi rac
    for (int i=1; i<=n; i++){
        par[i]=i;}
    //sap xep cac canh theo thu tu tang dan
    sort(sto.begin(), sto.end(), [](auto a, auto b){
          return a.second <b.second;});
    for(auto edge: sto){
        if(check(edge.first.first, edge.first.second)){
            res+= edge.second;
            S_union(edge.first.first, edge.first.second);}}
    cout<<res<<endl;}

