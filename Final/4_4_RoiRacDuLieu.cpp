#include <bits/stdc++.h>
using namespace std;
#define MAXN 1000000000
int h_best= MAXN; //luu chenh lech nho nhat
int n, K;
int f[10005];
int g[22]={0};
int tong[10005]={0};
int check(int k){
  for (int u=1; u<k; u++){
    if( abs(g[u]-g[k])>h_best ) return 0;}
  return 1;}

void try_update(){
    int temp=0;
    for (int i=1; i<=K; i++){
        for (int j=i; j<=K; j++){
            temp= max(temp, abs(g[i]-g[j]));}}
    h_best= min(h_best, temp);}


void Try(int k, int i){ //i la gia tri ket thuc cua doan thu k
//Neu k==K thi no phai lay tu i+1 den n
    if (k==K){
        g[k]= tong[n]-tong[i];
        try_update();}
    else{
     for (int j=i+1; j<n; j++ ){
        //update
        g[k]= tong[j]-tong[i];//tong tan so trong khoang
        if (check(k))Try(k+1,j);
        //release
        g[k]=0;}}}

int main(){
    cin>>n>>K;
    for (int i=1; i<=n; i++){
        int a, b;
        cin>>a>>b;
        f[i]=b;
        tong[i]= tong[i-1]+f[i];}
    Try(1, 0);
    cout<<h_best<<endl;}
