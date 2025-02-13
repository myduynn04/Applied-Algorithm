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
int num[N]={0};
int low[N]={0};
//int tail[N]={0};
vector <int> adj[N];
int timedfs=0;
int num_strong_compose=0;
stack <int> S; //Stack de tim chot
int A[N]={0}; //luu phan tu thuoc tp lien thong manh goc nao

void dfs(int u, int pre){
    low[u]=num[u]= ++timedfs;
    S.push(u);
    for (int v: adj[u]){
        if(A[v]) continue; //neu node nay da bi bo ra khoi stack thi k duyet nua (vi da thuoc thanh phan lt manh khac) //canh cheo
        if(v==pre)continue;
        if(!num[v]){ //Truong hop v chua duoc tham
            dfs(v,u);
            low[u]= min(low[u], low[v]);
        }
        else if(num[v]){
           low[u]= min(low[u], num[v]);
        }
    }
    //tail[u]=timedfs;

    //kiem tra co phai chot khong
    if(low[u]==num[u]){
        num_strong_compose++;
        int top = S.top(); //top la gia tri cua phan tu tren cung cua S
        S.pop();
        A[top]=u;//gan phan tu top nay thuoc tplt u
        while(top!=u){//neu chua pop ra den chot u
            top= S.top();
            S.pop();
            A[top]=u;
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
        adj[a].push_back(b); //do co huong
    }
    for (int i=1; i<=n; i++){
        if(!num[i]) dfs(i,i);
    }

    cout<<num_strong_compose<<endl;
    return 0;
}

























































