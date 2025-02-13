#include <bits/stdc++.h>
using namespace std;


#define N 10000
#define MAXN 1e9
int n,m; //n la so dinh
int heap[N]; //luu tru cay vun dong min (dam bao a[i]<a[2i+1] va a[2i+2]
int index[N]; //luu vi tri cua tung phan tu trong cay vun dong
vector<int> adj[N];
int W[N][N]; //luu trong so
int D[N]; //mang luu duong di ngan nhat tu s->u
int P[N]={0}; //dnh dau dinh u da duoc xu ly chua
int pos[N];

void build_bottom(int i){
    if(2*i+1>=n) return;
    int temp;
    int tempindex;
    int temppos;
    if(2*i+2<n && heap[2*i+1]>heap[2*i+2]) {
        tempindex=2*i+2;
        temp= heap[2*i+2];
    }
    else{
        tempindex=2*i+1;
        temp= heap[2*i+1];
    }

    swap(pos[i], pos[tempindex]);
    swap(heap[i], heap[tempindex]);
    index[pos[i]]=i;
    index[pos[tempindex]]= tempindex;
    build_bottom(tempindex);
}

void build_up(int i){
    int pre = (i-1)/2;
    int temp;
    int tempindex;

    if(i==0) return;
    if(heap[pre]>heap[i]){
        swap(heap[i], heap[pre]);
        swap(pos[i], pos[pre]);
        index[pos[i]]=i;
        index[pos[pre]]=pre;
        build_up(pre);
    }



}

void dijkstra(int s){
    D[s] = 0;
    heap[index[s]]=0; //vi tri cua s trong cay ban dau la 0 (goc) -> sap xep dong d

    for(int i=1; i<=n; i++){
        int top = heap[0];
        heap[0]=MAXN;
        int position = pos[0];
        build_bottom(0);// cap nhat lai cay khi bo goc ra khoi cay-> goc da duoc duyet roi
        //cap nhat lai cac D
        P[position]=1;

        for (int v: adj[position]){
            if (!P[v]){
                D[v]=min(D[v], D[position]+W[position][v]);
                heap[index[v]]= D[v];
                build_up(index[v]);
            }
        }

    }


}


int main(){
    //memset(W, -1, sizeof(W));
    fill_n(heap, N, MAXN);
    fill_n(D, N, MAXN);
    cin>>n>>m;
    for(int i=0; i<m; i++){
        int a,b,w;
        cin>>a>>b>>w;
        adj[a].push_back(b);
        W[a][b]=w;
    }

    for(int i=1; i<=n; i++) {
        index[i] = i-1; //de xuat phat tu 0 cho dung thuat toan
        pos[i-1]=i; // luu theo heap, heap bat dau tu 0
    }
    dijkstra(1); //dijkstra tu dinh 1

    for (int i=1; i<=n; i++){
        cout<<D[i]<<" ";
    }
    cout<<endl;

    return 0;
}
