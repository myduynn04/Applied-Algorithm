/*
There are n passengers 1, 2, …, n. The passenger i want to travel from point i to point
i + n (i = 1,2,…,n). There is a bus located at point 0 and has k places for transporting
the passengers (it means at any time, there are at most k passengers on the bus).
You are given the distance matrix c in which c(i,j) is the traveling distance from point
i to point j (i, j = 0,1,…, 2n). Compute the shortest route for the bus, serving n
passengers and coming back to point 0.

Input
Line 1 contains n and k (1≤n≤11,1≤k≤10)
 Line i+1 (i=1,2,…,2n+1) contains the (i−1)
th
 line of the matrix c (rows and columns are indexed from 0,1,2,..,2n).
Output
Unique line contains the length of the shortest route.
Example
Input
3  2
0  8  5  1  10  5  9
9  0  5  6  6  2  8
2  2  0  3  8  7  2
5  3  4  0  3  2  7
9  6  8  7  0  9  10
3  8  10  6  5  0  2
3  4  4  5  2  2  0
Output
25
*/

#include <bits/stdc++.h>
using namespace std;
#define MAXN 1000000000
int n, K;
int c[25][25]={0};
int cmin=MAXN;
int visited[15]={0};
int load=0; //luong dang cho
int onbus[15]={0};
int fbest=MAXN;
int dis=0;
int pos[30]={0};//vi tri hien tai

int check2(int k){
    if(k!=(2*n)) return 0;
    return 1;}
//duyet theo luot don xe bus
void Try(int k){
    //don khach
    if (load<K){
        for (int i=1; i<=n; i++){
            if(visited[i]==0){
                load++;
                visited[i]=1;
                dis+= c[pos[k-1]][i];
                pos[k]=i;
                int temp =-1;
                for (int j=1; j<=K; j++){
				if (!onbus[j]) {
					temp = j; break;}}
                if (temp!=-1) onbus[temp]= i;
                if((dis +cmin*(2*n-k))<fbest) Try(k+1);
                load--;
                visited[i]=0;
                dis-= c[pos[k-1]][i];
                pos[k]=0;
                onbus[temp]= 0;}}}
    //tra khach
    if(load>0){
        for(int v=1; v<=n; v++){
            int check=0;int no=-1;
            for (int i=1; i<=K; i++){
                if(onbus[i]==v) {check=1; no=i;}}
            if(check){
                onbus[no]=0;
                dis+=c[pos[k-1]][v+n];
                pos[k]=v+n;
                load--;
                if(check2(k)){
                    fbest=min(fbest, dis + c[pos[k]][0]);}
                else if (dis +cmin*(2*n-k)<fbest) Try(k+1);
                onbus[no]=v;
                dis-=c[pos[k-1]][v+n];
                pos[k]=0;
                load++;}}}}

int main(){
    cin>>n>>K;
    for (int i=0; i<=2*n; i++){
        for (int j=0; j<=2*n; j++){
            cin>>c[i][j];
            if (c[i][j]!=0) cmin= min(cmin, c[i][j]);}}
    pos[0]=0;
    Try(1);
    cout<<fbest<<endl;}

































