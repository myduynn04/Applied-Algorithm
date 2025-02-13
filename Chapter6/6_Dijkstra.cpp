                                                                                                                                                                               /*

*/
//dinh xuat phat, dinh ket thuc, trong so
//Out put la mang D
#include <bits/stdc++.h>
using namespace std;
#define N 10000
#define MAXN 1e9
int n,m; //n la so dinh
vector<int> adj[N];
int W[N][N]; //luu trong so
int D[N]; //mang luu duong di ngan nhat tu s->u
int P[N]={0}; //dnh dau dinh u da duoc xu ly chua
int trace[N]; //truy vet
void dijkstra( int u){
     D[u]=0;
     for(int j=1; j<=n; j++){
     int Dmin = MAXN;
     int temp =-1;
     for(int i=1; i<=n; i++){
        if (!P[i] && Dmin>D[i] ) {
            Dmin =D[i];
            temp =i;}}
        if(temp==-1) break;
        P[temp]=1;
        for (int v: adj[temp]){
            if (!P[v]){ //chi xet dinh chua duoc xet
                D[v]= min(D[v], D[temp]+ W[temp][v]);// neu laprim thi khng cong them trong so
                }}}}


int main(){
    memset(W, -1, sizeof(W));
    cin>>n>>m;
    for(int i=0; i<m; i++){
        int a,b,w;
        cin>>a>>b>>w;
        adj[a].push_back(b);
        W[a][b]=w;}

    for(int i=1; i<=n; i++) D[i]= MAXN;
    dijkstra(1); //dijkstra tu dinh 1

    for (int i=1; i<=n; i++){
        cout<<D[i]<<" ";}
    cout<<endl;

    return 0;
}
