/*
A fleet of K identical trucks having capacity Q need to be scheduled to delivery pepsi
packages from a central depot 0 to clients 1,2,…,n. Each client i requests d[i]
packages. The distance from location i to location j is c[i,j], 0≤i,j≤n. A delivery
solution is a set of routes: each truck is associated with a route, starting from
depot, visiting some clients and returning to the depot for deliverying requested
pepsi packages such that:
Each client is visited exactly by one route
Total number of packages requested by clients of each truck cannot exceed its capacity

Goal: Find a solution having minimal total travel distance

Note that:
- There might be the case that a truck does not visit any client (empty route)
- The orders of clients in a route is important, e.g., routes 0 -> 1 -> 2 -> 3 -> 0
and 0 -> 3-> 2 -> 1 -> 0 are different.

Input:
Line 1: n,K,Q (2≤n≤12,1≤K≤5,1≤Q≤50)
Line 2: d[1],...,d[n](1≤d[i]≤10)
Line i+3 (i=0,…,n): the ith row of the distance matrix c (1≤c[i,j]≤30)

Output
Minimal total travel distance

Example
Input
4 2 15
7 7 11 2
0 12 12 11 14
14 0 11 14 14
14 10 0 11 12
10 14 12 0 13
10 13 14 11 0

Output
70
*/


#include <bits/stdc++.h>
using namespace std;
#define MAXN 1000000000
int K;
int Q;
int n;
int d[15]={0};//pag for each clients
int c[15][15]={0};//distance
int fbest=MAXN;
int visited[15]={0};
int start[6]={0}; //luu vi tri bat dau cua cac xe
int segment=0; //Tong doan duong ma cac xe da di (max la n+K)
int n_router=0; //trong mot cau hinh(1 lan Try den kq bai toan) co bao nhieu xe xuat phat
int load[6]={0};
int dis=0;
int cmin=MAXN;

int check(int k, int i){
    if(i==0) return 1;
    if(visited[i]==1) return 0;
    if(load[k]+ d[i]>Q) return 0;
    return 1;}
void Try_update(){
    if (dis <fbest) fbest=dis;}
//bd: vi tri hien tai
void Try2(int k, int bd){
    //1. bd=0 thi co 2 th: 1 la khong xuat phat, 2 la da ve
    if(bd==0){
        if (k<K) Try2(k+1,start[k+1]);
        else return;}
    //2. bd!=0
    else{
        for (int i=0; i<=n; i++){
            if(check(k,i)){
                visited[i]=1;
                dis+= c[bd][i];
                load[k]+=d[i];
                segment++;
                if(segment==n_router + n){
                    if(i==0) Try_update();}
                else if(dis + cmin*(n_router +n - segment)  <fbest ){Try2(k,i);}
                visited[i]=0;
                dis-= c[bd][i];
                load[k]-=d[i];
                segment--;}}}}

//Khoi tao hanh khach di cho cac xe
//k la stt xe
void Try1(int k){
    //Tinh so xe xuat phat
    //Truong op xe khong chay
    if(start[k-1]==0 && k<K){
        //k<K de dam bao co it nhat 1 xe se chay
        start[k]=0;//xe nay co the khong xuat phat
        Try1(k+1);}
    for(int i=start[k-1]+1; i<=n; i++){
            start[k]=i;
            n_router++;
            segment++;
            visited[i]=1;
            load[k]+=d[i];
            dis+= c[0][i];
            if(k==K) Try2(1,start[1]);
            else Try1(k+1);
            start[k]=0;
            n_router--;
            segment--;
            visited[i]=0;
            load[k]-=d[i];
            dis-= c[0][i];}}

int main(){
    cin>>n>>K>>Q;
    for (int i=1; i<=n; i++) cin>>d[i];
    for (int i=0; i<=n; i++){
        //luu y i=0 la chi deport 0
        for(int j=0; j<=n; j++){
            cin>>c[i][j];
            if(c[i][j]!=0) cmin=min(cmin, c[i][j]);}}
    Try1(1);
    cout<<fbest<<endl;}

