#include <bits/stdc++.h>
using namespace std;
#define MAXN 1000000000

int n, m;
vector< pair<pair<int,int>,int>> sto; //luu cap dinh va trong so cua canh
int A[2][760];//luu toa do
int par[760]={0};
int res=0;
int num_edge=0;

int distance(int a, int b){
    return (A[0][a]-A[0][b])*(A[0][a]-A[0][b]) + (A[1][a]-A[1][b])*(A[1][a]-A[1][b]);
}

int check(int a, int b){
    int root_a= a;
    while(root_a!=par[root_a]){//tim goc cua tplt chua a
        root_a = par[root_a];
    }
    int root_b=b;
    while(root_b!=par[root_b]){
        root_b = par[root_b];
    }
    if(root_a!=root_b)return 1;
    return 0;
}

void S_union(int a, int b){
    int root_a= a;
    while(root_a!=par[root_a]){//tim goc cua tplt chua a
        root_a = par[root_a];
    }
    int root_b=b;
    while (root_b!=par[root_b]){
        root_b= par[root_b];
        par[b]=root_a;
        b= root_b;
    }
    par[root_b]=root_a;//Truong hop khi da cham den root cua tplt chua b
}

int main(){
    cin>>n; //so dinh
    for (int i=1; i<=n; i++){
        int x,y;
        cin>>x>>y;
        A[0][i]=x;
        A[1][i]=y;}
    //Các tplt roi rac
    for(int i=1; i<=n;i++){
        par[i]=i;}
    cin>>m;
    //Cho cac cau xay roi co chi phi la 0
    for(int i=1; i<=m; i++){
        int a,b;
        cin>>a>>b;
        sto.push_back(make_pair(make_pair(a,b), 0));}
    for (int i=1; i<=n; i++){
        for(int j=i+1; j<=n; j++ ){
            int c= distance(i,j);
            sto.push_back(make_pair(make_pair(i,j), c));}}

    sort(sto.begin(), sto.end(), [](auto a,auto b ){
         return a.second<b.second;});

    for (auto edge: sto){
        if (check(edge.first.first,edge.first.second )){
            res+= edge.second;
            num_edge+=1;
            if(num_edge==n-1) break;
            S_union(edge.first.first,edge.first.second );}}
    cout<<res<<endl;

}
